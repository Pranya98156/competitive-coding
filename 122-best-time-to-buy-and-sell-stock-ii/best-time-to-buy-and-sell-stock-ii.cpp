class Solution {
public:
//recusion
int solve(int buy,int index,vector<int>& prices){
    //base case
    if(index==prices.size()){
        return 0;
    }
    int profit=0;
    if(buy){
        int buykaro=-prices[index]+solve(0,index+1,prices);
        int skipkaro=0+solve(1,index+1,prices);
        profit=max(buykaro,skipkaro);
    }
    else{
        int sellkaro=prices[index]+solve(1,index+1,prices);
        int ignorekaro=0+solve(0,index+1,prices);
        profit=max(sellkaro,ignorekaro);
    }
    return profit;
}

//memorization
int solveMem(int buy,int index,vector<int>& prices,vector<vector<int>>& dp){
    if(index==prices.size()){
        return 0;
    }
    int profit=0;
    if(dp[buy][index]!=-1){
        return dp[buy][index];
    }
    if(buy){
        int buykaro=-prices[index]+solveMem(0,index+1,prices,dp);
        int skipkaro=0+solveMem(1,index+1,prices,dp);
        profit=max(buykaro,skipkaro);
    }
    else{
        int sellkaro=prices[index]+solveMem(1,index+1,prices,dp);
        int ignorekaro=0+solveMem(0,index+1,prices,dp);
        profit=max(sellkaro,ignorekaro);
    }
    return dp[buy][index]=profit;

}

//tabulation
int solveTab(vector<int>& prices){
    int n=prices.size();
    vector<vector<int>> dp(n+1,vector<int> (2,0));
    for(int index=n-1;index>=0;index--){
        for(int buy=0;buy<=1;buy++){
            int profit=0;
            if(buy){
                int buykaro=-prices[index]+dp[index+1][0];
                int skipkaro=0+dp[index+1][1];
                profit=max(buykaro,skipkaro);
            }
            else{
                int sellkaro=prices[index]+dp[index+1][1];
                int ignorekaro=0+dp[index+1][0];
                profit=max(sellkaro,ignorekaro);
            }
            dp[index][buy]=profit;

        }
    }
    return dp[0][1];
}

//optimization
int solveOpt(vector<int>& prices) {

    int n = prices.size();

    int nextBuy = 0;
    int nextNotBuy = 0;

    for(int index = n - 1; index >= 0; index--) {

        int currBuy =
            max(-prices[index] + nextNotBuy,
                nextBuy);

        int currNotBuy =
            max(prices[index] + nextBuy,
                nextNotBuy);

        nextBuy = currBuy;
        nextNotBuy = currNotBuy;
    }

    return nextBuy;
}
    int maxProfit(vector<int>& prices) {
       // return solve(1,0,prices);
        // int n=prices.size();
        // vector<vector<int>> dp(2,vector<int> (n,-1));
        // return solveMem(1,0,prices,dp);
       // return solveTab(prices);
        return solveOpt(prices);
    }
};