class Solution {
public:
bool solve(string& s,string& p,int i,int j){
    //empty strings
    if(i<0 && j<0){
        return true;
    }
    //first string mai hai character and second string empty
    if(i>=0 && j<0){
        return false;
    }
    //agar pehle string mai elments check karliye koi match nhi kar rhe toh check karenge ki pattern mai * toh nhi hai
    if(i<0 && j>=0){
        for(int k=0;k<=j;k++){
            if(p[k]!='*'){
                return false;
            }
        }
        return true;
    }
    //match ki condition
    if(s[i]==p[j] || p[j]=='?'){
        return solve(s,p,i-1,j-1);
    }
    else if(p[j]=='*'){
        return (solve(s,p,i-1,j)|| solve(s,p,i,j-1));
    }
    else{
        return false;
    }
}
bool solveMem(string& s,string& p,int i,int j,vector<vector<int>>& dp){
    //empty strings
    if(i<0 && j<0){
        return true;
    }
    //first string mai hai character and second string empty
    if(i>=0 && j<0){
        return false;
    }
    //agar pehle string mai elments check karliye koi match nhi kar rhe toh check karenge ki pattern mai * toh nhi hai
    if(i<0 && j>=0){
        for(int k=0;k<=j;k++){
            if(p[k]!='*'){
                return false;
            }
        }
        return true;
    }
     if(dp[i][j]!=-1){
        return dp[i][j];
    }
    //match ki condition
    if(s[i]==p[j] || p[j]=='?'){
        return dp[i][j]=solveMem(s,p,i-1,j-1,dp);
    }
    else if(p[j]=='*'){
        return dp[i][j]=(solveMem(s,p,i-1,j,dp)|| solveMem(s,p,i,j-1,dp));
    }
    else{
        return false;
    }
}
    bool isMatch(string s, string p) {
       //return solve(s,p,s.length()-1,p.length()-1);
     vector<vector<int>> dp(s.length(),vector<int>(p.length(),-1));
       return solveMem(s,p,s.length()-1,p.length()-1,dp);
    }
};