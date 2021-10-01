int getLowValue(set<int>&A,int n){
    auto it = A.lower_bound(n);
    it--;
    return *it;
}
int Solution::solve(vector<int> &A) {
    int msum = INT_MIN;
    int i,j,ans=0;
    int n = A.size();
    int sar[n+1];
    //Maximum suffix array
    sar[n]=0;
    for(int i=n-1;i>=0;i--)
        sar[i] = max(sar[i+1],A[i]);
        
    set<int>S;
    S.insert(INT_MIN);
    for(i=0;i<n-1;i++){
        if(sar[i+1]>A[i])
            ans = max(ans,getLowValue(S,A[i])+sar[i+1]+A[i]);
        S.insert(A[i]);
    }
    return ans;
}
