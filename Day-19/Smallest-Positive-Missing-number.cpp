//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution
{
    public:
    //Function to find the smallest positive number missing from the array.
    int missingNumber(int arr[], int n) 
    { 
        vector<int>a(n,0);
        for(int i=0;i<n;i++){
            a[i]=arr[i];
        }
        
        sort(a.begin(),a.end());
        a.erase(unique(a.begin(),a.end()),a.end());
        int i=0;
        while(a[i]<1) i++;
        if(a[i]!=1) return 1;
        
        int ele = 1;
        
        while(i<n){
            if(a[i]!=ele) return ele;
            ele++;
            i++;
        }
        
        return ele;
    } 
};

//{ Driver Code Starts.

int missingNumber(int arr[], int n);

int main() { 
    
    //taking testcases
    int t;
    cin>>t;
    while(t--){
        
        //input number n
        int n;
        cin>>n;
        int arr[n];
        
        //adding elements to the array
        for(int i=0; i<n; i++)cin>>arr[i];
        
        Solution ob;
        //calling missingNumber()
        cout<<ob.missingNumber(arr, n)<<endl;
    }
    return 0; 
} 
// } Driver Code Ends
