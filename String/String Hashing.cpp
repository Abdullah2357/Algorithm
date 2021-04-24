#include<bits/stdc++.h>
#define ll     long long
using namespace std;

#define sz 100005
const int MOD = 1e9+7;

ll hashsum[sz],p[sz];
ll Hashing(int l,int r)
{
    if(l>0)
        return  (hashsum[r]-hashsum[l-1]+MOD)%MOD;
    else
        return hashsum[r]%MOD;
}

int main()
{
    p[0]=1;
    for(int i=1;i<sz-2;i++)
    {
        p[i] = p[i-1]*31;
        p[i]%=MOD;
    }
    ll n,k,i,ans=0,l1,r1,l2,r2;
    string s;
    cin>>s;
    n = s.size();
    for(i=0;i<n;i++)
    {
        hashsum[i] = ((s[i]-'a'+1)*p[i])%MOD;
        if(i)
            hashsum[i] = (hashsum[i-1]+hashsum[i])%MOD;
    }
    cin>>l1>>r1>>l2>>r2;
    ll h1 = (Hashing(l2,r2))%MOD;
    ll h2 = (Hashing(l1,r1)*p[l2-l1])%MOD;
    if(h1==h2)
        cout<<"YES\n";
    else
        cout<<"NO\n";
}
