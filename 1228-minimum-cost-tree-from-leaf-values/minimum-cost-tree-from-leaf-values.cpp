
class Solution {
public:
int solve(vector<int>& arr,int left,int right,map<pair<int,int>,int>& maxi){
    if(left==right){
        return 0;
    }
    int ans=INT_MAX;
    for(int i=left;i<right;i++){
        int cost=maxi[{left,i}]*maxi[{i+1,right}]+solve(arr,left,i,maxi)+solve(arr,i+1,right,maxi);
        ans=min(ans,cost);
    }
    return ans;
}

//memorization
int solveMem(vector<int>& arr,int left,int right,map<pair<int,int>,int>& maxi,vector<vector<int>>& dp){
    if(left==right){
        return 0;
    }
    if(dp[left][right]!=-1){
        return dp[left][right];
    }
    int ans=INT_MAX;
    for(int i=left;i<right;i++){
        int cost=maxi[{left,i}]*maxi[{i+1,right}]+solveMem(arr,left,i,maxi,dp)+solveMem(arr,i+1,right,maxi,dp);
        ans=min(ans,cost);
    }
    return dp[left][right]=ans;
}
    int mctFromLeafValues(vector<int>& arr) {
        int n=arr.size();
        map<pair<int,int>,int> maxi;
        vector<vector<int>> dp(n+1,vector<int> (n+1,-1));
        for(int i=0;i<arr.size();i++){
            maxi[{i,i}]=arr[i];
            for(int j=i+1;j<arr.size();j++){
                maxi[{i,j}]=max(arr[j],maxi[{i,j-1}]);
            }
        }
        return solveMem(arr,0,arr.size()-1,maxi,dp);
    }
};