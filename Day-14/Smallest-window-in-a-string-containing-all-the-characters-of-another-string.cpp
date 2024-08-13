//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution
{
    public:
    //Function to find the smallest window in the string s consisting
    //of all the characters of string p.
    string smallestWindow (string s, string p)
    {
        if(s.length()<p.length()) return "-1";
        // unordered_map<char,int>mp;
        vector<int>mp(26,0);
        for(int i=0;i<p.size();i++){
            mp[p[i]-'a']++;
        }
        int i=0,j=0;
        int mini = INT_MAX;
        int cnt = p.length();
        int st=-1;
        while(j<s.length()){
            if(mp[s[j]-'a']>0){
                cnt--;
            }
            mp[s[j]-'a']--;
            
            while(cnt==0){
                int len = j-i+1;
                if(len<mini){
                    mini = len;
                    st = i;
                }
                mp[s[i]-'a']++;
                
                if(mp[s[i]-'a']>0) cnt++;
                
                i++;
            }
            j++;
        }
        return (st==-1) ? "-1" : s.substr(st,mini);
    }
};

//{ Driver Code Starts.
int main()
 {
    int t;
    cin>>t;
    while(t--)
    {
        string s;
        cin>>s;
        string pat;
        cin>>pat;
        Solution obj;
        cout<<obj.smallestWindow(s, pat)<<endl;
        
    }
	return 0;
}
// } Driver Code Ends
