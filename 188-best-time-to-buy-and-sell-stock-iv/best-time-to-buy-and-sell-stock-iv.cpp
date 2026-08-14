class Solution {
public:
//recursion
int solve(int index,int operation,int k,vector<int>& prices){
    if(index==prices.size()){
        return 0;
    }
    if(operation==2*k){
        return 0;
    }
    int profit=0;
    if(operation%2==0){
        int buykaro=-prices[index]+solve(index+1,operation+1,k,prices);
        int skipkaro=0+solve(index+1,operation,k,prices);
        profit=max(buykaro,skipkaro);
    }
    else{
        int sellkaro=prices[index]+solve(index+1,operation+1,k,prices);
        int ignorekaro=0+solve(index+1,operation,k,prices);
        profit=max(sellkaro,ignorekaro);
    }
    return profit;
}

//memorization
int solveMem(int index,int operation,int k,vector<int>& prices,vector<vector<int>>& dp){
    if(index==prices.size()){
        return 0;
    }
    if(operation==2*k){
        return 0;
    }
    if(dp[index][operation]!=-1){
        return dp[index][operation];
    }
    int profit=0;
    if(operation%2==0){
        int buykaro=-prices[index]+solveMem(index+1,operation+1,k,prices,dp);
        int skipkaro=0+solveMem(index+1,operation,k,prices,dp);
        profit=max(buykaro,skipkaro);
    }
    else{
        int sellkaro=prices[index]+solveMem(index+1,operation+1,k,prices,dp);
        int ignorekaro=0+solveMem(index+1,operation,k,prices,dp);
        profit=max(sellkaro,ignorekaro);
    }
    return dp[index][operation]=profit;
}

//tabulation
int solveTab(vector<int>& prices,int k){
    int n=prices.size();
    vector<vector<int>> dp(n+1,vector<int> (2*k+1,0));
    for(int index=n-1;index>=0;index--){
        for(int operation=0;operation<2*k;operation++){
            int profit=0;
            if(operation%2==0){
                int buykaro=-prices[index]+dp[index+1][operation+1];
                int skipkaro=0+dp[index+1][operation];
                profit=max(buykaro,skipkaro);
            }
            else{
                int sellkaro=prices[index]+dp[index+1][operation+1];
                int ignorekaro=0+dp[index+1][operation];
                profit=max(sellkaro,ignorekaro);
            }
            dp[index][operation]=profit;
        }
    }
    return dp[0][0];
}

//optimization
int solveOpt(int k,vector<int>& prices){
    int n=prices.size();
    vector<int> curr(2*k+1,0);
    vector<int> next(2*k+1,0);
    for(int index=n-1;index>=0;index--){
        for(int operation=0;operation<2*k;operation++){
            int profit=0;
            if(operation%2==0){
                int buykaro=-prices[index]+next[operation+1];
                int skipkaro=0+next[operation];
                profit=max(buykaro,skipkaro);
            }
            else{
                int sellkaro=prices[index]+next[operation+1];
                int ignorekaro=0+next[operation];
                profit=max(sellkaro,ignorekaro);
            }
            curr[operation]=profit;
        }
        next=curr;
    }
    return next[0];
}
    int maxProfit(int k, vector<int>& prices) {
        //return solve(0,0,k,prices);
        // int n=prices.size();
        // vector<vector<int>> dp(n,vector<int> (2*k,-1));
        // return solveMem(0,0,k,prices,dp);
        return solveTab(prices,k);
        return solveOpt(k,prices);

    }
};