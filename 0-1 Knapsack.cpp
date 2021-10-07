int dp[1001][1001];
int knap(vector<int> &A, vector<int> &B, int n,int C)
{
    if(n==0)
        return 0;
    if(dp[n][C]!=-1)
        return dp[n][C];
    if(B[n-1]<=C)
    {
        return dp[n][C]=max(A[n-1]+knap(A,B,n-1,C-B[n-1]),knap(A,B,n-1,C));
    }
    else
        return dp[n][C]=knap(A,B,n-1,C);
}
int Solution::solve(vector<int> &A, vector<int> &B, int C) {
    int n=A.size();
    for(int i=0;i<=n;i++)
        for(int j=0;j<=C;j++)
            dp[i][j]=-1;
    return knap(A,B,n,C);
}