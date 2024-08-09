class Solution {
public:
    static int sum(string a){
        int sum=0;
        for(int i=0;i<a.length();i++){
            sum+=a[i];
        }
        return sum;
    }
    static bool cmp(string& a,string &b){
        return sum(a)<sum(b);
    }
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<vector<string>>ans;
        sort(strs.begin(),strs.end(),cmp);
        for(auto it:strs){
            
        }
        return ans;
    }
};
