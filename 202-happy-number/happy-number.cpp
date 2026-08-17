class Solution {
public:
int squarenumber(int n){
    int sum=0;
    while(n>0){
        int digit=n%10;
        sum+=digit*digit;
        n=n/10;
        
    }
    return sum;
}
    bool isHappy(int n) {
        int slow=squarenumber(n);
        int fast=squarenumber(squarenumber(n));
        while(fast!=slow){
            slow=squarenumber(slow);
            fast=squarenumber(squarenumber(fast));
        }
        if(slow==1){
            return true;
            }
        else{
            return false;
        }
    }
};