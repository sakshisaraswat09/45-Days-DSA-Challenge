#include<sstream>
#include<algorithm>
class Solution {
public:
    string reverseWords(string s) {
        stringstream ss(s);
        string token;
        char delimeter = ' ';
        stack<string>st;
        while(getline(ss,token,delimeter)){
            st.push(token);
        }
        string ans;
        while(!st.empty()){
            ans+= st.top();
            st.pop();
            if(!st.empty())ans+=" ";
        }
        return ans;
    }
};
