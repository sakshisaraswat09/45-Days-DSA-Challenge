class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        string ans=strs[0];
        for(int i=1;i<strs.size();i++){
            int j=0;
            string temp = ans;
            while(j<strs[i].length() && j<ans.length()){
                if(temp[j]==strs[i][j]) j++;
                else{
                    break;
                }
            }
            ans = temp.substr(0,j);
        }
        return ans;
    }
};
