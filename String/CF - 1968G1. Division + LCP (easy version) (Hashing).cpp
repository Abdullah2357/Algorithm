#include<bits/stdc++.h>
#define ll      long long
#define MOD     1000000007
#define sz      200005
using namespace std;

ll n, hashsum[sz], p[sz];

ll Hashing(ll l, ll r)
{
    if(l>0)
        return (hashsum[r]-hashsum[l-1] + MOD)%MOD;
    else
        return hashsum[r]%MOD;
}

bool OK(ll value, ll k)
{
    ll cnt=1,First = Hashing(0,value-1);
    for(int i = value;i<n;i++)
    {
        if(i+value-1>=n)
            break;
        ll cur = Hashing(i,i+value-1);
        if((First*p[i])%MOD==cur)
        {
            cnt++;
            i = i+value-1;
        }
    }
    if(cnt>=k)
        return 1;
    else
        return 0;
}

void Solve(int t)
{
    ll i, j, ans =0, fg=0,l,r;
    cin>>n>>l>>r;
    string s;
    cin>>s;

    for(int i=0;i<n;i++)
    {
        hashsum[i] = ((s[i]-'a'+1)*p[i])%MOD;
        if(i)
            hashsum[i] = (hashsum[i-1] + hashsum[i]) %MOD;
    }

    ll lo = 1, hi = n, mid,res = 0;
    while(lo<=hi)
    {
        mid = (lo+hi)/2;
        if(OK(mid,l))
        {
            res = mid;
            lo = mid+1;
        }
        else
            hi = mid-1;
    }
    cout<<res<<endl;
}

int main()
{
    p[0] = 1;
    for(int i=1;i<sz;i++)
    {
        p[i] = (p[i-1]*199999)%MOD;
    }

    int t,T=1;
    scanf("%d",&T);
    for(t=1;t<=T;t++)
    {
        Solve(t);
    }
    return 0;
}

