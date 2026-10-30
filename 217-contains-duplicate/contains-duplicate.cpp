class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        int n=nums.size();
        unordered_map<int,int> mp(n);
        for(int i=0;i<n;i++){
           if(mp.find(nums[i])!=mp.end()){
            return true;
           }
           mp[nums[i]]++;
        }
        return false;
    }
};