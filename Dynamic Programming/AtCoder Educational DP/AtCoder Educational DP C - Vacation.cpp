#include<bits/stdc++.h>
using namespace std;
#define sz 100005

int n,a[sz],b[sz],c[sz];
int dp[sz][3][3][3];

int FuN(int pos,int swim,int catch_bug,int homework)
{
    if(pos > n)
        return 0;
    if(dp[pos][swim][catch_bug][homework] != -1)
        return dp[pos][swim][catch_bug][homework];
    int ret1 = 0 , ret2 = 0 , ret3 = 0 ;
    if(swim < 1)
        ret1 = a[pos] + FuN(pos+1,swim+1,0,0);
    if(catch_bug < 1)
        ret2 = b[pos] + FuN(pos+1,0,catch_bug+1,0);
    if(homework < 1)
        ret3 = c[pos] + FuN(pos+1,0,0,homework+1);
    return dp[pos][swim][catch_bug][homework] = max(ret1,max(ret2,ret3));
}
int main()
{
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i]>>b[i]>>c[i];
    }
    memset(dp,-1,sizeof(dp));
    cout<<FuN(1,0,0,0)<<endl;
    return 0;
}
