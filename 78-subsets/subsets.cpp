class Solution {
public:
void solve(vector<int>& arr,vector<vector<int>>& ans,int index,vector<int>& nums){
    //base case
    if(index==nums.size()){
        ans.push_back(arr);
        return;
    }
    arr.push_back(nums[index]);
    //inclusion call
    solve(arr,ans,index+1,nums);
    //exclusion call
    arr.pop_back();
    solve(arr,ans,index+1,nums);

}
    vector<vector<int>> subsets(vector<int>& nums) {
       vector<int> arr;
       vector<vector<int>> ans;
       solve(arr,ans,0,nums);
       return ans;
    }
};