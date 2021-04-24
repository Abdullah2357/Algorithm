#include<bits/stdc++.h>
#define ll     long long
using namespace std;

#define sz 1200005

const ll MOD = 1e9+7;
ll hashsum[sz],power[sz],patternHash[sz];
string s,p;

ll Hashing (ll l,ll r)
{
    return (hashsum[r]-hashsum[l-1]+MOD)%MOD;
}
ll Hashing2 (ll l,ll r)
{
    return (patternHash[r]-patternHash[l-1]+MOD)%MOD;
}

void Solve(int t)
{
    ll k,i;
    cin>>s>>p>>k;
    ll n = s.size(),n2 = p.size(),ans=0;
    for(i=1;i<=n;i++)
    {
        hashsum[i] = (hashsum[i-1]+((ll)s[i-1]*power[i])%MOD)%MOD;
    }
    for(i=1;i<=n2;i++)
    {
        patternHash[i] = (patternHash[i-1]+((ll)p[i-1]*power[i])%MOD)%MOD;
    }
    for(i=1;i<=n-n2+1;i++)
    {
        ll l = i,r = i+n2-1,l2 = 1,r2 = n2,lo = 1,hi = n2,mid,res,H1,H2;
        H1 = (Hashing(l,r)*power[sz-5-l])%MOD;
        H2 = (Hashing2(l2,r2)*power[sz-5-l2])%MOD;
        if(H1==H2)
        {
            ans++;
            continue;
        }
        for(int used = 1;used <=k; used ++)
        {
            res=-1;
            while(lo<=hi)
            {
                mid = (lo+hi)/2;
                H1 = (Hashing(l,l+(mid-l2))*power[sz-5-l])%MOD;
                H2 = (Hashing2(l2,mid)*power[sz-5-l2])%MOD;
                if(H1!=H2)
                {
                    res = mid;
                    hi = mid-1;
                }
                else
                    lo = mid+1;
            }
            if(res==-1){
                l = 1e9;
                ans++;
                break;
            }
            ll x = res-l2+1;
            l2 += x ;
            l += x;
            if(l>r){
             ans++;
                break;
            }
            lo = l2,hi= r2;
        }
        if(l<=r)
        {
            H1 = (Hashing(l,r)*power[sz-5-l])%MOD;
            H2 = (Hashing2(l2,r2)*power[sz-5-l2])%MOD;
            if(H1==H2)
                ans++;
        }
    }
    printf("Case %d: %lld\n",t,ans);
}
int main()
{
    int t,T=1,i;
    scanf("%d",&T);
    power[0] = 1;
    for(i=1;i<sz;i++)
    {
        power[i] = (power[i-1]*269)%MOD;
    }
    for(t=1;t<=T;t++)
    {
        Solve(t);
    }
    return 0;
}
