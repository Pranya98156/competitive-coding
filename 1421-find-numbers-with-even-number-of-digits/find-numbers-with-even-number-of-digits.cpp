class Solution {
public:
    int findNumbers(vector<int>& nums) {
        int n=nums.size();
        int even=0;
        for(int i=0;i<n;i++){
            int count=0;
            int num=nums[i];
            while(num>0){
                count++;
                num=num/10;
            }
            if(count%2==0){
                even++;
            }
        }
        return even;
    }
};