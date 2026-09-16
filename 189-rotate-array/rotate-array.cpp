class Solution {
public:
    void rotate(vector<int>& nums, int k) {
       vector<int> temp(nums.size());
       for(int i=0;i<nums.size();i++){
        temp[(i+k)%nums.size()]=nums[i];//temp(3%6=3)=1,temp(4)=6,temp(5)=
       }
       nums=temp;
    }
};