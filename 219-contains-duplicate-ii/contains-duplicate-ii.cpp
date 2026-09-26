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
    // //step 1 create set
    //     unordered_set<int> st;

    //     for(int i=0;i<n;i++){
    //         if(i>k){
    //             if(st.count[nums[i]] && )
    //         }
       // }
    }
};