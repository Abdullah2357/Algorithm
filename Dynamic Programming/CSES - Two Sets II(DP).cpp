#include<bits/stdc++.h>
#define ll     long long
using namespace std;

#define sz 200005
const int MOD = 1e9+7;

ll n,dp[505][125255];

ll FuN(int pos,ll sum1)
{
    if(pos>n)
    {
        ll sum2 = (n*(n+1))/2 - sum1;
        return sum1==sum2;
    }
    if(dp[pos][sum1]!=-1)
        return dp[pos][sum1];
    ll ret = 0;
    ret = (ret + FuN(pos+1,sum1+pos))%MOD;
    ret = (ret + FuN(pos+1,sum1))%MOD;
    return dp[pos][sum1] = ret;
}

ll BigMOD(ll a,ll n,ll m)
{
    if(n==0)
        return 1%m;
    if(n==1)
        return a%m;
    if(n%2==0)
    {
        ll temp = BigMOD(a,n/2,m);
        return ((temp%m)*(temp%m))%m;
    }
    else
    {
        ll temp = BigMOD(a,n-1,m);
        return ((a%m)*(temp%m))%m;
    }
}

void Solve(int t)
{
    scanf("%lld",&n);
    memset(dp,-1,sizeof(dp));
    ll ans = FuN(1,0);
    ans = (ans * BigMOD(2,MOD-2,MOD))%MOD;
    printf("%lld\n",ans);

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
