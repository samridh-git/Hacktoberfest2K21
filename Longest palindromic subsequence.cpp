int dp[1006][1006];
int solve1(string A,int n,int m)
{
    if(n==m)
        return 1;
    if(n>m)
        return 0;
    if(dp[n][m]!=-1)
        return dp[n][m];
    if(A[n-1]==A[m-1])
        return dp[n][m]=2+solve1(A,n+1,m-1);
    else
        return dp[n][m]=max(solve1(A,n+1,m),solve1(A,n,m-1));
}
int Solution::solve(string A) {
    int n=A.length(),m=A.length();
    for(int i=0;i<=n;i++)
        for(int j=0;j<=m;j++)
            dp[i][j]=-1;
    return solve1(A,1,m);
}