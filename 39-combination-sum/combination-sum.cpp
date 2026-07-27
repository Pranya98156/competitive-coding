class Solution {
public:
void solve(vector<int>& arr,vector<vector<int>>& ans,int index,vector<int>& candidates,int target){
    //base case
    if(target==0){
        ans.push_back(arr);
        return;
    }
    if(index>=candidates.size() || target<0){
        return;
    }
    arr.push_back(candidates[index]);
    solve(arr,ans,index,candidates,target-candidates[index]);
    arr.pop_back();
    solve(arr,ans,index+1,candidates,target);
}

    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
       vector<int> arr;
       vector<vector<int>> ans;
       solve(arr,ans,0,candidates,target);
       return ans; 
    }
};