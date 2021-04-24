#include<bits/stdc++.h>
#define ll     long long
using namespace std;

#define sz 100009
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
char ss[sz];
int main()
{
    p[0]=1;
    ll n,k,i,ans=0,l1,r1,l2,r2,h1,h2;
    for(i=1;i<sz-2;i++)
    {
        p[i] = p[i-1]*269;
        p[i]%=MOD;
    }
    while(scanf("%s",ss) != EOF){
    //cin>>s;
    string s;
    n = strlen(ss);
    for(i=0;i<n;i++)
        s+=ss[i];
    hashsum2[n+1]=0;
    for(i=1;i<=n;i++)
    {
        hashsum[i] = (hashsum[i-1]+((ll)s[i-1])*p[i])%MOD;
    }
    for(i=n;i>=1;i--)
    {
        hashsum2[i] = (hashsum2[i+1] + ((ll)s[i-1])*p[n-i+1])%MOD;
    }
    for(i=1;i<=n;i++)
    {
        l1 = i,r1 = n;
        r2 = n,l2 = i;
        h1 = Hashing(l1,r1)%MOD;
        h2 = (Hashing2(l2)*p[l1-1])%MOD;
        if(h1==h2)
        {
            ans = i-1;
            break;
        }
    }
    string temp;
    for(i=0;i<ans;i++)
    {
        temp += s[i];
    }
    reverse(temp.begin(),temp.end());
    s+=temp;
    cout<<s<<endl;
    }
    return 0;
}
