#include<bits/stdc++.h>
#define ll long long
using namespace std;

ll n,k,a[405],sum[405],dp[404][405];

ll FuN(int lft,int rgt)
{
    if(lft==rgt)
        return 0;
    if(dp[lft][rgt]!=-1)
        return dp[lft][rgt];
    ll ret1=1e15,ret2=1e15;
    for(int i=1; ;i++)
    {
        if(lft+i>rgt)
            break;
        ret1 = sum[rgt]-sum[lft-1] + FuN(lft+i,rgt) + FuN(lft,lft+i-1);
        ret2 = min(ret1,ret2);
    }
    return dp[lft][rgt] = ret2;
}

int main()
{
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
        sum[i] = sum[i-1]+a[i];
    }
    memset(dp,-1,sizeof(dp));
    ll ans = FuN(1,n);
    cout<<ans<<endl;

}

