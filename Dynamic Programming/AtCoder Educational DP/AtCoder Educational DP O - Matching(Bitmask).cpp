#include<bits/stdc++.h>
#define ll long long
using namespace std;

bool check(int pos,int mask)
{
    return (bool)(mask &(1<<pos));
}
int Set(int pos,int mask)
{
    return (mask|(1<<pos));
}

const int MOD = 1e9+7;
ll n,a[23][23],dp[22][2097155];

ll FuN(int pos,int mask)
{
    if(pos==n)
        return 1;
    if(dp[pos][mask]!=-1)
        return dp[pos][mask];
    ll ret=0;
    for(int i=0;i<n;i++)
    {
        if(a[pos][i]==0 || check(i,mask))
            continue;
        if(a[pos][i] && !check(i,mask))
        {
            ret += FuN(pos+1,Set(i,mask));
        }
        ret%=MOD;
    }
    return dp[pos][mask] = ret;
}
int main()
{
    cin>>n;
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            cin>>a[i][j];
        }
    }
    memset(dp,-1,sizeof(dp));
    ll ans = FuN(0,0);
    cout<<ans<<endl;
    return 0;
}


