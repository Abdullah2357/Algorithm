#include<bits/stdc++.h>
#define ll     long long
using namespace std;

ll Mul(ll a,ll b,ll m)
{
    if(a==0)
        return 0;
    if(b==1)
        return a%m;
    if(b%2==0)
    {
        ll temp = Mul(a,b/2,m);
        return (temp+temp)%m;
    }
    else
    {
        ll temp = Mul(a,b-1,m);
        return (temp+a)%m;
    }
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
        return Mul(temp,temp,m);
    }
    else
    {
        ll temp = BigMOD(a,n-1,m);
        return Mul(temp,a,m);
    }
}
int main()
{
    ll a,n,m;
    cin>>a>>n>>m;
    cout<<BigMOD(a,n,m)<<endl;
}
