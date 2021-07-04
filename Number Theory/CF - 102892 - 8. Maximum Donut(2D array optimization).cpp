#include<bits/stdc++.h>
using namespace std;

#define sz 401

int n,a[sz][sz],rowSum[sz][sz],colSum[sz][sz],mx[sz][sz][sz];


void Solve(int t)
{
    int i, j, fg = 0, x, y, ans = -1e9;
    cin>>n;
    for(i=1;i<=n;i++)
    {
        for(j=1;j<=n;j++)
        {
            cin>>a[i][j];
            rowSum[i][j] = rowSum[i][j-1]+a[i][j];
            colSum[i][j] = colSum[i-1][j]+a[i][j];
            for(int k=0;k<=n;k++)
            {
                mx[i][j][k] = -1e9;
            }
        }
    }

    for(int x1=1;x1<=n;x1++)
    {
        for(int x2 = x1+2;x2<=n; x2++)
        {
            for(i=1;i<=n;i++)
            {
                x = rowSum[x1][n]-rowSum[x1][i-1]+rowSum[x2][n]-rowSum[x2][i-1];
                x += colSum[x2-1][i]-colSum[x1][i];
                mx[x1][x2][i] = max(mx[x1][x2][i-1],x);
            }
            for(i=3;i<=n;i++)
            {
                x = colSum[x2-1][i] - colSum[x1][i];
                x -= rowSum[x1][n]-rowSum[x1][i]+rowSum[x2][n]-rowSum[x2][i];

                ans = max(ans,mx[x1][x2][i-2]+x);
            }
        }
    }
    cout<<ans<<endl;
}
int main()
{
    int t,T=1;
//    scanf("%d",&T);
    for(t=1;t<=T;t++)
    {
        Solve(t);
    }
    return 0;
}
