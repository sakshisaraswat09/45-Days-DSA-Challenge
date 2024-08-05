//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution {
  public:
    void solve(vector<int>arr,int i,vector<vector<int>>& ans){
        if(i>=arr.size()){
            ans.push_back(arr);
            return;
        }
        
        for(int j=i;j<arr.size();j++){
            swap(arr[i],arr[j]);
            solve(arr,i+1,ans);
            swap(arr[i],arr[j]);
        }
    }
    vector<vector<int>> uniquePerms(vector<int> &arr ,int n) {
        vector<vector<int>>ans;
        solve(arr,0,ans);
        sort(ans.begin(),ans.end());
        ans.erase(unique(ans.begin(),ans.end()),ans.end());
        return ans;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        
        cin>>n;
        vector<int> arr(n);
        
        for(int i=0 ; i<n ; i++)
            cin>>arr[i];

        Solution ob;
        vector<vector<int>> res = ob.uniquePerms(arr,n);
        for(int i=0; i<res.size(); i++)
        {
            for(int j=0; j<n; j++)
            {
                cout<<res[i][j]<<" ";
            }
            cout<<"\n";
        }
    }
    return 0;
}
// } Driver Code Ends
