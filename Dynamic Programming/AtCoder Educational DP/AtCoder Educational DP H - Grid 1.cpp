#include<bits/stdc++.h>
#define ll long long
using namespace std;

const int MOD = 1e9+7;

ll h,w,dp[1005][1005];
char grid[1005][1005];

ll FuN(int i,int j)
{
    if(i==h && j==w)
    {
        return 1;
    }
    if(dp[i][j]!=-1)
        return dp[i][j];
    int ret=0;
    if(i+1<=h && grid[i+1][j]!='#')
        ret += FuN(i+1,j);
    ret%=MOD;
    if(j+1<=w && grid[i][j+1]!='#')
        ret += FuN(i,j+1);
    ret%=MOD;
    return dp[i][j] = ret;
}
int main()
{
    cin>>h>>w;
    for(int i=1;i<=h;i++)
    {
        for(int j=1;j<=w;j++)
        {
            cin>>grid[i][j];
        }
    }
    memset(dp,-1,sizeof(dp));
    ll ans = FuN(1,1);
    cout<<ans<<endl;
    return 0;
}


