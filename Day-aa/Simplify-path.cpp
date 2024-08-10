class Solution {
public:
    string simplifyPath(string path) {
        stack<string>st;
        stringstream ss(path);
        string token;
        char d = '/';
        while(getline(ss,token,d)){
            if(token=="." || token=="") continue;
            else if(token==".."){
                if(!st.empty()) st.pop();
            } 
            else st.push(token);
        }
        string ans = "";
        if(st.empty()){
            ans="/";
        }
        while(!st.empty()){
            ans="/"+st.top()+ans;
            st.pop();
        }
        
        return ans;
    }
};
