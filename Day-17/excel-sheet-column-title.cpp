class Solution {
public:
    string convertToTitle(int columnNumber) {
        int n = columnNumber;
        string ans = "";

        while(n){
            n--;
            int rem = n%26;
            ans+=rem+'A';
            n=n/26;
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }
};
