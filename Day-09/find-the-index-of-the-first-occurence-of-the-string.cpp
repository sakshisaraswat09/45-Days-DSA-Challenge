class Solution {
public:
    int strStr(string haystack, string needle) {
        if(haystack==needle) return 0;
        int i=0;
        int l = needle.length();
        while(i<haystack.size()){
            if(haystack[i]==needle[0]){
                string s = haystack.substr(i,l);
                if(s==needle) return i;
                else i++;
            }else i++;
        }
        return -1;
    }
};
