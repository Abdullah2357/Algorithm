
#include<bits/stdc++.h>
#define ll     long long
using namespace std;

#define sz 1000003
const ll MOD = 1e9+7;

ll hashsum[sz],p[sz];

ll Hashing(ll l,ll r)
{
    return (hashsum[r]-hashsum[l-1]+MOD)%MOD;
}
set<ll> st[1002];

int main()
{
    p[0]=1;
    ll n,k,i,ans=0,l,r,h1,h2,m;
    for(i=1;i<=sz-2;i++)
    {
        p[i] = p[i-1]*269;
        p[i]%=MOD;
    }
    string s,s2;
    cin>>s;
    ll len = s.size();
    for(i=1;i<=len;i++)
    {
        hashsum[i] = (hashsum[i-1]+((ll)s[i-1])*p[i])%MOD;
    }
    scanf("%lld",&n);
    while(n--)
    {
        cin>>s2;
        m = s2.size();
        h1 = 0;
        for(i=1;i<=m;i++)
        {
            h1 = (h1+ ((ll)s2[i-1]*p[i]))%MOD;
        }
        h1 = (h1*p[len-1])%MOD;
        bool fg=0;
        if(st[m].size()>0)
        {
            if(st[m].find(h1)!=st[m].end())
                fg=1;
        }
        else
        {
            for(i=1;i<=len;i++)
            {
                l = i;
                r = i+m-1;
                if(r>len)
                    break;
                h2 = (Hashing(l,r)*p[len-i])%MOD;
                st[m].insert(h2);
                if(h1==h2)
                {
                    fg=1;
                    break;
                }
            }
        }
        if(fg)
            printf("Y\n");
        else
            printf("N\n");
    }
    return 0;
}
