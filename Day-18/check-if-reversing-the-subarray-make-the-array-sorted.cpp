#include <bits/stdc++.h> 
bool sortArr(int n, vector<int> &arr){
    vector<int>temp(arr.begin(),arr.end());
    sort(temp.begin(),temp.end());
    int i=0;
    while(i<n && arr[i]==temp[i]) i++;
    int j=n-1;
    while(j>=0 && arr[j]==temp[j]) j--;

    if(i>j) return true;

    for(int k=i;k<j;k++){
        if(arr[k+1]>arr[k]) return false;
    }

    return true;
}
