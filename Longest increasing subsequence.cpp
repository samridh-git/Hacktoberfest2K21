int Solution::lis(const vector<int> &A) {
    int n=A.size();
    int ma=1;
    if(n==1||n==0)
        return n;
    vector<int>inc(n,1);
    for(int k=0;k<n;k++)
    {
        for(int i=0;i<k;i++)
        {
            if(A[i]<A[k])
            {
                inc[k]=max(inc[k],inc[i]+1);
                ma=max(ma,inc[k]);
            }
        }
    }
    return ma;
}
