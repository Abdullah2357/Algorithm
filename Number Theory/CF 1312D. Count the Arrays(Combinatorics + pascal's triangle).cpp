#include<bits/stdc++.h>
#define ll      long long
using namespace std;

#define sz 200005
const ll MOD = 998244353;

ll  a[sz],fact[sz];

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
ll NCR(ll n,ll r)
{
    ll nominator = fact[n];
    ll denominator = (fact[r]*fact[n-r])%MOD;
    return (nominator*(BigMOD(denominator,MOD-2,MOD)))%MOD;
}
void Solve(int t)
{
    ll i, j, x,  y, fg = 0, ans=0,n,m;
    cin>>n>>m;
    ans = NCR(m,n-1);
    ans = (ans*(n-2))%MOD;

    if(n>2)
        ans = (ans*BigMOD(2,n-3,MOD))%MOD; /// row sum of pascal's triangle
    /// sum of nC0 + nC1 + nC3+ .... nCn = 2^n
    cout<<ans<<endl;
}

int main()
{
    int t,T=1;
    fact[0] = 1;
    for(int i=1;i<sz;i++)
    {
        fact[i] = (i*fact[i-1])%MOD;
    }

//    scanf("%d",&T);
    for(t=1;t<=T;t++)
    {
        Solve(t);
    }
    return 0;
}
