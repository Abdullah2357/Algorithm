#include<bits/stdc++.h>
using namespace std;

#define N 100005
int STMN[20][N],STMX[20][N];
int a[N];

void Compute_ST(int n)
{
    for(int i=0;i<n;i++) STMN[0][i] = a[i],STMX[0][i] = a[i];

    for(int k=1 ; (1<<k) < n; k++)
    {
        for(int i=0; i+(1<<k)<=n ; i++)
        {
            int x = STMN[k-1][i];
            int y = STMN[k-1][i+(1<<k-1)];
            STMN[k][i] = min(x, y);
            x = STMX[k-1][i];
            y = STMX[k-1][i+(1<<k-1)];
            STMX[k][i] = max(x, y);
        }
    }
}

int RMNQ(int i, int j)
{
    int k = log2(j-i);
    int x = STMN[k][i];
    int y = STMN[k][j - (1<<k)+1];
    return min(x, y);
}

int RMXQ(int i, int j)
{
    int k = log2(j-i);
    int x = STMX[k][i];
    int y = STMX[k][j - (1<<k)+1];
    return max(x, y);
}

void Solve(int t)
{
    int n, d, ans = 0, i;

    scanf("%d %d",&n,&d);
    for( i = 0; i < n ;i++)
    {
        scanf("%d",&a[i]);
    }

    Compute_ST(n);

    for(i=0;i<n;i++)
    {
        if(i+d-1>=n)
            break;
        int mn = RMNQ(i,i+d-1);
        int mx = RMXQ(i,i+d-1);
        ans = max(ans,mx-mn);
    }

    printf("Case %d: %d\n",t,ans);
}


int main()
{
    int t,T = 1;
    scanf("%d",&T);
    for(t=1;t<=T;t++)
    {
        Solve(t);
    }
    return 0;
}

