class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n=nums.size();
        vector<int> res(n,1);
        int pref=1;
        //step 1 for prefix
        for(int i=0;i<n;i++){
            res[i]=pref;
            pref=pref*nums[i];        
        }
        int post=1;

        //step 2 for sufix
        for(int j=n-1;j>=0;j--){
            res[j]*=post;
            post=post*nums[j];
        }
        

        //step 3 multiple the prefix and suffix
        return res;
    }
};