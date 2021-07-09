#include<bits/stdc++.h>
#define ll     long long
using namespace std;

#define sz 15

bool Check(int mask,int pos)
{
    return (bool)(mask&(1<<pos));
}
int Set(int mask,int pos)
{
    return (mask|(1<<pos));
}

int n, dp[1<<17], a[sz][sz];

int FuN(int mask)
{
    if(dp[mask] != -1)
        return dp[mask];
    int ret = 1e9;
    for(int i=0;i<n;i++)
    {
        if(Check(mask,i))
            continue;
        int SubCharge = 0;
        for(int j=0;j<n;j++)
        {
            if(Check(mask,j))
                SubCharge += a[i][j];
        }
        ret = min(ret, a[i][i]+SubCharge+FuN(Set(mask,i)));
    }
    if(ret==1e9)
        return 0;
    return dp[mask]= ret;
}

void Solve(int t)
{
    int i, j;
    cin>>n;
    for(i=0;i<n;i++)
    {
        for(j=0;j<n;j++)
        {
            scanf("%d",&a[i][j]);
        }
    }
    memset(dp,-1,sizeof(dp));
    int ans = FuN(0);
    printf("Case %d: %d\n", t, ans);
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
