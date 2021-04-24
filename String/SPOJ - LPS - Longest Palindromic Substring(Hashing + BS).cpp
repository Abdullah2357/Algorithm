
#include<bits/stdc++.h>
#define ll     long long
using namespace std;

#define sz 1000005
const ll MOD = 1e9+7;

ll hashsum[sz],p[sz],hashsum2[sz],n;

ll Hashing(ll l,ll r)
{
    return (hashsum[r]-hashsum[l-1]+MOD)%MOD;
}
ll Hashing2(ll l,ll r)
{
    return (hashsum2[r]-hashsum2[l+1]+MOD)%MOD;
}

bool possible(ll value)
{
    ll l,r,h1,h2;
    for(l=1;l<=n;l++)
    {
        r = l+value-1;
        if(r>n)
            break;
        h1 = (Hashing(l,r)*p[sz-5-l])%MOD;
        h2 = (Hashing2(r,l)*p[sz-5-(n-r+1)])%MOD;
        if(h1==h2)
            return 1;
    }
    return 0;
}
int main()
{
    ll i,ans;
    p[0]=1;
    for(i=1;i<=sz-2;i++)
    {
        p[i] = p[i-1]*269;
        p[i]%=MOD;
    }
    string s;
    cin>>n;
    cin>>s;
    for(i=1;i<=n;i++)
    {
        hashsum[i] = (hashsum[i-1]+((ll)(s[i-1]))*p[i])%MOD;
    }
    for(i=n;i>=1;i--)
    {
        hashsum2[i] = (hashsum2[i+1]+((ll)(s[i-1]))*p[n-i+1])%MOD;
    }
    ll lo = 1,hi = n/2,mid,res=0;
    while(lo<=hi)
    {
        mid = (lo+hi)/2;
        if(possible(mid*2))
        {
            res = mid*2;
            lo = mid+1;
        }
        else
            hi = mid-1;
    }
    ans = res;
    lo = 1,hi = n/2+1;
    res = 0;
    while(lo<=hi)
    {
        mid = (lo+hi)/2;
        if(possible(mid*2-1))
        {
            res = mid*2-1;
            lo = mid+1;
        }
        else
            hi = mid-1;
    }
    ans = max(ans,res);
    printf("%lld\n",ans);
    return 0;
}
