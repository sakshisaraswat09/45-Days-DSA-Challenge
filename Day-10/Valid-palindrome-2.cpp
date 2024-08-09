class Solution {
public:
    bool solve(string& s,int count,int i,int j){
        if(i>=j) return true;
        if(count>=1 && s[i]!=s[j]) return false;
        bool a=0,b=0;
        if(s[i]==s[j]) return solve(s,count,i+1,j-1);
        else{
            a = solve(s,count+1,i+1,j);
            b = solve(s,count+1,i,j-1);
        }
        return a||b;
    }
    bool validPalindrome(string s) {
        int i=0,j=s.length()-1;
        return solve(s,0,i,j);
    }
};
