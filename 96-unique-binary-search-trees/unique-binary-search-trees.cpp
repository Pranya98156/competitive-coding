class Solution {
public:
//recursion
int solve(int n){
    //base case
    if(n<=1){
        return 1;
    }
    int ans=0;
    for(int i=1;i<=n;i++){
        ans+=solve(i-1)*solve(n-i);
    }
    return ans;
}

//memorization
int solveMem(int n,vector<int>& dp){
    if(n<=1){
        return 1;
    }
    if(dp[n]!=-1){
        return dp[n];
    }
    int ans=0;
    for(int i=1;i<=n;i++){
        ans+=solveMem(i-1,dp)*solveMem(n-i,dp);
    }
    return dp[n]=ans;
}

//tabulation
int solveTab(int n){
    vector<int> dp(n+1,0);
    dp[0]=dp[1]=1;
    //for number of node
    for(int i=2;i<=n;i++){
        // for root node
        for(int j=1;j<=i;j++){
            dp[i]+=dp[j-1]*dp[i-j];
        }
    }
    return dp[n];
}
    int numTrees(int n) {
        // return solve(n);
        // vector<int> dp(n+1,-1);
        // return solveMem(n,dp);
        return solveTab(n);
    }

};