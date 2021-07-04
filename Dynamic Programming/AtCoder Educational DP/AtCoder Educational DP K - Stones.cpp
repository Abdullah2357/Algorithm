#include<bits/stdc++.h>
using namespace std;

int n,k,a[105],dp[4][100005];

int FuN(int player,int baki)
{
    if(baki==0)
    {
        if(player==0)
            return 0;
        else
            return 1;
    }
    if(dp[player][baki]!=-1)
        return dp[player][baki];
    int ret1=0,ret2=0,ret3=1,ret4=1;
    for(int i=1;i<=n;i++)
    {
        if(a[i]<=baki)
        {
            if(player==0)
            {
                ret1 = 1*(FuN(player^1,baki-a[i]));
                ret2 = max(ret1,ret2);
            }
            else
            {
                ret3 = 1*FuN(player^1,baki-a[i]);
                ret4 = min(ret3,ret4);
            }
        }
    }
    if(player==0)
        return dp[player][baki] = ret2;
    else
        return dp[player][baki] = ret4;
}

int main()
{
    cin>>n>>k;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
    }
    memset(dp,-1,sizeof(dp));
    int ans=FuN(0,k);
    if(ans==1)
        cout<<"First\n";
    else
        cout<<"Second\n";

}

