class Solution {
public:
//recursion
int solve(int index,int buy,vector<int>& prices,int limit){
    //base case
    if(index==prices.size()){
        return 0;
    }
    if(limit==0){
        return 0;
    }
    int profit=0;
    if(buy){
        int buykaro=-prices[index]+solve(index+1,0,prices,limit);//hsving 2 limit
        int skipkaro=0+solve(index+1,1,prices,limit);
        profit=max(buykaro,skipkaro);

    }
    else{
        int sellkaro=prices[index]+solve(index+1,1,prices,limit-1);//having only 1 limit now  that's why limit-1
        int ignorekaro=0+solve(index+1,0,prices,limit);
        profit=max(sellkaro,ignorekaro);
    }
    return profit;
}

//memorization
int solveMem(int index,int buy,vector<int>& prices,int limit,vector<vector<vector<int>>>& dp){
    if(index==prices.size()){
        return 0;
    }
    if(limit==0){
        return 0;
    }
    if(dp[index][buy][limit]!=-1){
        return dp[index][buy][limit];
    }
    int profit=0;
    if(buy){
        int buykaro=-prices[index]+solveMem(index+1,0,prices,limit,dp);
        int skipkaro=0+solveMem(index+1,1,prices,limit,dp);
        profit=max(buykaro,skipkaro);
    }
    else{
        int sellkaro=prices[index]+solveMem(index+1,1,prices,limit-1,dp);
        int ignorekaro=0+solveMem(index+1,0,prices,limit,dp);
        profit=max(sellkaro,ignorekaro);
    }
    return dp[index][buy][limit]=profit;
}

//tabulation
int solveTab(vector<int>& prices){
    int n=prices.size();
    vector<vector<vector<int>>> dp(n+1,vector<vector<int>> (2,vector<int> (3,0)));
    for(int index=n-1;index>=0;index--){
        for(int buy=0;buy<=1;buy++){
            for(int limit=1;limit<=2;limit++){
                int profit=0;
                if(buy){
                    int buykaro=-prices[index]+dp[index+1][0][limit];
                    int skipkaro=0+dp[index+1][1][limit];
                    profit=max(buykaro,skipkaro);
                }
                else{
                    int sellkaro=prices[index]+dp[index+1][1][limit-1];
                    int ignorekaro=0+dp[index+1][0][limit];
                    profit=max(sellkaro,ignorekaro);
                }
               dp[index][buy][limit]=profit;
            }
             
        }
   
    }
         return dp[0][1][2];
}

//optimization
int solveopt(vector<int>& prices){
    int n=prices.size();
    vector<vector<int>> curr(2,vector<int> (3,0));
    vector<vector<int>> next(2,vector<int> (3,0));
    for(int index=n-1;index>=0;index--){
        for(int buy=0;buy<=1;buy++){
            for(int limit=1;limit<=2;limit++){
                int profit=0;
                if(buy){
                    int buykaro=-prices[index]+next[0][limit];
                    int skipkaro=0+next[1][limit];
                    profit=max(buykaro,skipkaro);
                }
                else{
                    int sellkaro=prices[index]+next[1][limit-1];
                    int ignorekaro=0+next[0][limit];
                    profit=max(sellkaro,ignorekaro);
                }
                curr[buy][limit]=profit;
            }
            next=curr;
        }
    }
    return next[1][2];
}
    int maxProfit(vector<int>& prices) {
        //return solve(0,1,prices,2);
        //int n=prices.size();
        // vector<vector<vector<int>>>dp (n+1,vector<vector<int>> (2,vector<int> (3,-1)));
        // return solveMem(0,1,prices,2,dp);
        return solveTab(prices);
        return solveopt(prices);
    }
};