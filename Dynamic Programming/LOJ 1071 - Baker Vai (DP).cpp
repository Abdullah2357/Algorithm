#include<bits/stdc++.h>
#define ll     long long
using namespace std;

#define sz 105

int n, m, a[sz][sz], dp[sz][sz][sz];

bool valid(int x,int y,int x2,int y2)
{
    return (bool) (x<n && y<m && x2<n && y2<m);
}
int FuN(int x,int y,int x2)
{
    if(x==n && y==m)
        return 0;

    if(dp[x][y][x2]!=-1)
        return dp[x][y][x2];

    int y2 = x+y-x2;
    int ret = 0,CurPeople = a[x][y]+a[x2][y2];

    if(valid(x+1,y,x2,y2+1))
        ret = max(ret,CurPeople+FuN(x+1,y,x2));

    if(valid(x,y+1,x2,y2+1))
        ret = max(ret,CurPeople+FuN(x,y+1,x2));

    if(valid(x+1,y,x2+1,y2))
        ret = max(ret,CurPeople+FuN(x+1,y,x2+1));

    if(valid(x,y+1,x2+1,y2) && (x!=x2+1 || y+1!=y2))
        ret = max(ret,CurPeople+FuN(x,y+1,x2+1));

    return dp[x][y][x2] = max(ret,CurPeople);
}
void Solve(int t)
{
    int i, j, ans = 0;

    scanf("%d %d",&n,&m);

    for(i=0;i<n;i++)
    {
        for(j=0;j<m;j++)
        {
            scanf("%d",&a[i][j]);
        }
    }

    memset(dp,-1,sizeof(dp));
    ans = FuN(1,0,0) + a[0][0] + a[n-1][m-1];

    printf("Case %d: %d\n",t,ans);
}
int main()
{
    int t,T=1;
    scanf("%d",&T);
    for(t=1;t<=T;t++)
    {
        Solve(t);
    }
    return 0;
}
