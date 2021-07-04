#include<bits/stdc++.h>
using namespace std;
int n,h[100005],k;
int dp[100005];

int FuN(int pos)
{
    if(pos>=n)
        return 0;
    if(dp[pos]!=-1)
        return dp[pos];
    int res=2e9,res2=2e9;
    for(int i=1;i<=k;i++)
    {
        if(pos+i<=n)
        {
            res=min(res,abs(h[pos]-h[pos+i])+FuN(pos+i));
            res2=min(res2,res);
        }
    }
    return dp[pos] = res2;
}
int main()
{
    cin>>n>>k;
    memset(dp,-1,sizeof(dp));
    for(int i=1;i<=n;i++)
    {
        cin>>h[i];
    }
    int ans=FuN(1);
    cout<<ans<<endl;
    return 0;
}
