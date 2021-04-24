#include<bits/stdc++.h>
#define ll     long long
using namespace std;

#define sz 1000009
const ll MOD = 1e9+7;

ll hashsum[sz],p[sz],hashsum2[sz];

ll Hashing(ll l,ll r)
{
    return (hashsum[r]-hashsum[l-1]+MOD)%MOD;
}
ll Hashing2(ll r)
{
    return (hashsum2[r])%MOD;
}

int main()
{
    p[0]=1;
    ll n,k,i,ans=0,l,r,h1,h2,m;
    for(i=1;i<sz-2;i++)
    {
        p[i] = p[i-1]*269;
        p[i]%=MOD;
    }
    while(scanf("%lld",&n) != EOF){
        //cin>>n;
        string needle, haystack;
        cin>>needle>>haystack;
        bool fg=0;
        h1 = 0;
        m = haystack.size();
        for(i=1;i<=n;i++)
            h1 = (h1+(needle[i-1]*p[i]))%MOD;
        h1 = (h1*p[m-1])%MOD;
        for(i=1;i<=m;i++)
        {
            hashsum[i] = (hashsum[i-1]+((ll)haystack[i-1])*p[i])%MOD;
        }
        for(i=1;i<=m;i++)
        {
            l = i,r = i+n-1;
            if(r>m)
                break;
            h2 = (Hashing(l,r)*p[m-i])%MOD;
            if(h1==h2)
            {
                cout<<i-1<<endl;
                fg=1;
            }
        }
        if(!fg)
            cout<<endl;
    }
    return 0;
}
