#include<bits/stdc++.h>
using namespace std;
int n,h[100005];
int dp[100005];

int FuN(int pos)
{
    if(pos>=n)
        return 0;
    if(dp[pos]!=-1)
        return dp[pos];
    int res=2e9,res2=2e9;
    if(pos+1<=n)
        res = min(res,abs(h[pos]-h[pos+1])+FuN(pos+1));
    if(pos+2<=n)
        res2=min(res2,abs(h[pos]-h[pos+2])+FuN(pos+2));
    return dp[pos] = min(res,res2);
}
int main()
{
    cin>>n;
    memset(dp,-1,sizeof(dp));
    for(int i=1;i<=n;i++)
    {
        cin>>h[i];
    }
    int ans=FuN(1);
    cout<<ans<<endl;
    return 0;
}
