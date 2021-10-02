#include<iostream>
#include<bits/stdc++.h>

using namespace std;

vector<int> nextPermutation(vector<int> arr){
        bool res=next_permutation(arr.begin(),arr.end());
        if(res==false){
            sort(arr.begin(),arr.end());
            return arr;
            }
        else
            return arr;
        
}

int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        vector<int>arr(n);
        for(int i=0;i<n;i++)
            cin>>arr[i];
        vector<int>ans=nextPermutation(arr);
        for (int u:ans){
            cout<<u<<" ";
        }
        cout<<"\n";
    }
    return 0;
}