class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
       int n=nums.size();
       vector<int> res(n,1);
       //multiplicative identity
       int prefix=1;
       for(int i=0;i<n;i++){
        //store the prefix in the resultant array and then use for calculating the suffix
        res[i]=prefix;
        //multiplying the prefix with the nums[i]
        prefix=prefix*nums[i];
       }
       //calculating the suffix
       int post=1;
       for(int j=n-1;j>=0;j--){
        //res[j]=prefix*suffix
        res[j]*=post;
        post=post*nums[j];
       }
       return res;

    }
};