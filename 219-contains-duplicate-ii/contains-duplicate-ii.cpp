class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        int n=nums.size();
        unordered_map<int,int> mp;
        
        for(int i=0;i<n;i++){
           if(mp.count(nums[i]) && i-mp[nums[i]]<=k)
            return true;
            mp[nums[i]]=i;
        }
        return false;
        // int n=nums.size();
        // unordered_set<int> st;
        // for(int i=0;i<n;i++){
        //     if(i>k){
        //         st.erase(nums[i-k-1]);
        //     }
        //     if(st.count(nums[i])){
        //         return true;
                
        //     }
        //     st.insert(nums[i]);
        // }
        // return false;
    }
};