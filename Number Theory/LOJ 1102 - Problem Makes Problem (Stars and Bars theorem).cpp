#include<bits/stdc++.h>
#define ll     long long
using namespace std;

#define sz 2000005
const int MOD = 1e9+7;

ll Fac[sz];

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
    int n,k;
    scanf("%d %d",&n,&k);

    ll nominator = Fac[n+k-1];
    ll denominator = (Fac[n]*Fac[k-1])%MOD;

    ll ans = (nominator * (BigMOD(denominator,MOD-2,MOD)))%MOD;

    printf("Case %d: %lld\n",t,ans);
}
int main()
{
    int t,T=1;
    Fac[0] = 1;
    for(int i=1;i<sz;i++)
    {
        Fac[i] = (Fac[i-1]*i)%MOD;
    }
    scanf("%d",&T);
    for(t=1;t<=T;t++)
    {
        Solve(t);
    }
    return 0;
}
