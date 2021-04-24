#include<bits/stdc++.h>
#define ll     long long
using namespace std;

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
int main()
{
    ll a,b,n;
    cin>>a>>n;
    cout<<BigMOD(a,n,MOD)<<endl;
}
