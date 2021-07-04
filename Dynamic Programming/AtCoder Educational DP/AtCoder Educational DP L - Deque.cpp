#include<bits/stdc++.h>
#define ll long long
using namespace std;

ll n,a[3005],dp[3][3005][3005];

ll FuN(int player,int lft,int rgt)
{
    if(lft>rgt)
        return 0;
    if(dp[player][lft][rgt]!=-1)
        return dp[player][lft][rgt];
    ll ret;
    if(player==0)
    {
        ll ret1=0,ret2=0;
        ret1 = a[lft]+FuN(player^1,lft+1,rgt);
        ret2 = a[rgt]+FuN(player^1,lft,rgt-1);
        ret = max(ret1,ret2);
    }
    else
    {
        ll ret1 = 1e15,ret2=1e15;
        ret1 = FuN(player^1,lft+1,rgt);
        ret2 = FuN(player^1,lft,rgt-1);
        ret = min(ret1,ret2);
    }
    return dp[player][lft][rgt] = ret;
}
int main()
{
    ll sum=0;
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
        sum+=a[i];
    }
    memset(dp,-1,sizeof(dp));
    ll ans = FuN(0,1,n);
    cout<<ans - (sum-ans)<<endl;
    return 0;
}

