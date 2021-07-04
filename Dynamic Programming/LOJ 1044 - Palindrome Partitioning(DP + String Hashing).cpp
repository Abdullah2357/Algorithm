#include<bits/stdc++.h>
#define ll     long long
using namespace std;

#define sz 1005
const int MOD = 1e9+7;

string s;
int n,dp[sz];



ll hashsum[sz],p[sz],hashsum2[sz];

ll Hashing(ll l,ll r)
{
    return (hashsum[r]-hashsum[l-1]+MOD)%MOD;
}
ll Hashing2(ll l,ll r)
{
    return (hashsum2[r]-hashsum2[l+1]+MOD)%MOD;
}

bool isPalindrome(int i,int j)
{
    string a,b;
    a = s.substr(i,j-i+1);
    b = a;
    reverse(a.begin(),a.end());
    return a==b;
}
int FuN(int pos)
{
    if(pos>=n)
        return 0;
    if(dp[pos]!=-1)
        return dp[pos];
    int ret = 1e9;
    ret = 1+FuN(pos+1);
    for(int i=pos+1;i<n;i++)
    {
        ll l = pos+1,r = i+1;
        ll H1 = (Hashing(l,r)*p[sz-5-l])%MOD;
        ll H2 = (Hashing2(r,l)*p[sz-5-(n-r+1)])%MOD;

        if(H1==H2)
            ret = min(ret,1+FuN(i+1));
//        if(isPalindrome(pos,i))
//            ret = min(ret,1+FuN(i+1));
    }
    return dp[pos] = ret;
}
void BuildHash(int n)
{
    int i;
    for(i=1;i<=n;i++)
    {
        hashsum[i] = (hashsum[i-1]+((ll)(s[i-1]))*p[i])%MOD;
    }
    hashsum2[n+1] = 0;
    for(i=n;i>=1;i--)
    {
        hashsum2[i] = (hashsum2[i+1]+((ll)(s[i-1]))*p[n-i+1])%MOD;
    }

}
void Solve(int t)
{
    cin>>s;
    n = s.size();
    BuildHash(n);
    memset(dp,-1,sizeof(dp));
    int ans = FuN(0);
    printf("Case %d: %d\n",t,ans);
}
int main()
{
    int t,T=1;
    p[0]=1;
    for(int i=1;i<=sz-1;i++)
    {
        p[i] = (p[i-1]*269)%MOD;
    }
    scanf("%d",&T);
    for(t=1;t<=T;t++)
    {
        Solve(t);
    }
    return 0;
}

