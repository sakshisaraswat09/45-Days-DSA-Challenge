class Solution {
public:
    string minWindow(string s, string t) {
        unordered_map<char,int>mp;
        if(s.length()<t.length()) return "";
        for(auto it:t){
            mp[it]++;
        }
        int st = 0;
        int cnt = t.length();
        int i=0,j=0;
        int mini = INT_MAX;
        while(j<s.length()){
            if(mp[s[j]]>0){
                cnt--;
            }
            mp[s[j]]--;

            
            while(cnt==0){
                int len = j-i+1;
                if(len<mini){
                    st = i;
                    mini = len;
                }
                mp[s[i]]++;
                if(mp[s[i]]>0){
                    cnt++;
                }
                i++;
            }
            j++;
        }

        return mini==INT_MAX ? "" : s.substr(st,mini);
    }
};
