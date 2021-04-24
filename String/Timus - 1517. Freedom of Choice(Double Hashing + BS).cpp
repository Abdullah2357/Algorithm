#include<bits/stdc++.h>
#define ll    unsigned long long
using namespace std;

#define sz 100005

ll n,hashsum[sz][2],p[sz],hashsum2[sz][2],p2[sz];
pair<ll,ll> ans;
const ll MOD = 1e9+7;
const ll MOD2 = 1e9+9;
ll possible(ll value)
{
    ll l,r,H1,H2;
    set<pair<ll,ll>> st;
    for(l=1;l<=n-value+1;l++)
    {
        r = l+value-1;
        H1 = ((hashsum[r][0]-hashsum[l-1][0]+MOD)%MOD*p[sz-l-5])%MOD;
        H2 = ((hashsum[r][1]-hashsum[l-1][1]+MOD2)%MOD2*p2[sz-l-5])%MOD2;
        st.insert(make_pair(H1,H2));
    }
    for(l=1;l<=n-value+1;l++)
    {
        r = l+value-1;
        H1 = ((hashsum2[r][0]-hashsum2[l-1][0]+MOD)%MOD*p[sz-l-5])%MOD;
        H2 = ((hashsum2[r][1]-hashsum2[l-1][1]+MOD2)%MOD2*p2[sz-l-5])%MOD2;
        if(st.find(make_pair(H1,H2))!=st.end())
        {
            ans = make_pair(l,r);
            return 1;
        }
    }
    return 0;
}
int main()
{
    p[0]=1;
    p2[0]=1;
    ll i,lo,hi,res=0,H,mid,l,r;
    for(i=1;i<=sz-2;i++)
    {
        p[i] = (p[i-1]*269)%MOD;
        p2[i] = (p2[i-1]*269)%MOD2;
    }
    cin>>n;
    string s1,s2;
    cin>>s1>>s2;
    for(i=1;i<=n;i++)
    {
        hashsum[i][0] = (hashsum[i-1][0]+((ll)s1[i-1]*p[i])%MOD)%MOD;
        hashsum[i][1] = (hashsum[i-1][1] +((ll)s1[i-1]*p2[i])%MOD2)%MOD2;
    }
    for(i=1;i<=n;i++)
    {
        hashsum2[i][0] = (hashsum2[i-1][0]+((ll)s2[i-1]*p[i])%MOD)%MOD;
        hashsum2[i][1] = (hashsum2[i-1][1]+((ll)s2[i-1]*p2[i])%MOD2)%MOD2;
    }
    lo = 1,hi=n;
    while(lo<=hi)
    {
        mid = (lo+hi)/2;
        if(possible(mid))
        {
            res = mid;
            lo = mid+1;
        }
        else
        {
            hi=  mid-1;
        }
    }
    if(res)
    {
        for(i=ans.first;i<=ans.second;i++)
        {
            cout<<s2[i-1];
        }
        cout<<endl;
    }
    else
        cout<<endl;
    return 0;
}
