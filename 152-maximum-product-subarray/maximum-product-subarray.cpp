class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int best=nums[0];
        int worst=nums[0];
        int ans=nums[0];
        for(int i=1;i<nums.size();i++){
            int a=nums[i]*best;
            int b=nums[i]*worst;
            int c=nums[i];
            best=max(a,max(b,c));
            worst=min(a,min(b,c));
            ans=max(ans,best);
        }
        return ans;
    }
};