class Solution {
public:
    int majorityElement(vector<int>& nums) {
      int n=nums.size();
      int candidate=-1;
      int count=0;
        for(int arr:nums){
            if(count==0){
                candidate=arr;
                count=1;
            }
            else if(arr==candidate){
                count++;
            }
            else{
                count--;
            }
        }
        count=0;
        for(int arr:nums){
            if(arr==candidate){
                count++;
            }
        }
        if(count>n/2){
            return candidate;
        }
        else{
            return -1;
        }
    }
};