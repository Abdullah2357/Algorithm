#include<bits/stdc++.h>
#define ll    long long
using namespace std;

#define sz 200005

const int MOD = 1e9+7;

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
    ll n,ans = 1;
    cin>>n;
    n+=2;
    ans = (n*(n-1))%MOD;
    ans = (ans *(n-2))%MOD;
    ans = (ans * BigMOD(6,MOD-2,MOD))%MOD;
    ans = (ans*2)%MOD;
    printf("Case %d: %lld\n",t,ans);
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
