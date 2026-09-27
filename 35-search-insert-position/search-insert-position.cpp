class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        int start=0;
        int end=nums.size()-1;
        //we need to check the element if start and end are at the same index
        while(start<=end){
            //avoid the potential of integer overflow
            int mid=start+(end-start)/2;
            if(nums[mid]==target){
                return mid;
            }
            //check the right side of the array
            if(nums[mid]<target){
                start=mid+1;
            }
            //check the left side of the array
            else{
                end=mid-1;
            }
        }
        // if target not found then return start because when the loop finishes your start > end and start becomes at the first position where the element is to be inserted
        return start;
       
    }
};