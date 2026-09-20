class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        int n=nums.size();
        unordered_map<int,int> prefix;
     
        int currsum=0;
        int count=0;
        for(int i=0;i<n;i++){
            currsum+=nums[i];
        if(currsum==k){
            count++;
        }
        if(prefix.find(currsum-k)!=prefix.end()){
            count+=prefix[currsum-k];
        }
         prefix[currsum]++;
    }
        return count;

    }
};