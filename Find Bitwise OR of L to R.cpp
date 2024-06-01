#include<bits/stdc++.h>
#define ll      long long
#define MOD     1000000007
#define sz      200005
using namespace std;

ll n, m;

ll MSB(ll x)
{
    ll msb_p = -1;
    while(x)
    {
        msb_p++;
        x = x>>1;
    }
    return msb_p;
}


/// Returns the Bitwise OR of all
/// integers between L and R
ll FindBitwiseOR(ll l, ll r)
{
    if(l==r) return l;
    ll res = 0;
    ll msb_p1 = MSB(l); /// MSB position of l
    ll msb_p2 = MSB(r); /// MSB position of r
    while(msb_p1==msb_p2)
    {
        ll cur = (1<<msb_p1);
        res += cur;
        l -= cur;
        r -= cur;
        msb_p1 = MSB(l);
        msb_p2 = MSB(r);
    }

    for(int i = max(msb_p1,msb_p2);i>=0;i--)
    {
        ll cur = (1<<i);
        res += cur;
    }
    return res;
}


void Solve(int t)
{
    ll i, j, ans =0, fg=0;
    ll l,r;
    cin>>l>>r;
    ans = FindBitwiseOR(l, r);
    cout<<ans<<endl;
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int t,T=1;
    cin>>T;
    for(t=1;t<=T;t++)
    {
        Solve(t);
    }
    return 0;
}
