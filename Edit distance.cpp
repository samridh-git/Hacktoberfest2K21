int Solution::minDistance(string A, string B) {
    vector<vector<int>>t(B.size()+1,vector<int>(A.size()+1,-1));
    int n=B.size(),m=A.size();
    for(int i=0;i<n+1;i++)
    for(int j=0;j<m+1;j++)
    {
        if(i==0)
            t[i][j]=j;
        else if(j==0)
            t[i][j]=i;
        else if(A[j-1]==B[i-1])
        {
            t[i][j]=t[i-1][j-1];
        }
        else
        {
            t[i][j]=1+min(t[i-1][j],min(t[i][j-1],t[i-1][j-1]));
        }
    }
    return t[n][m];
}
