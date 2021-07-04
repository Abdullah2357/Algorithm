
#include<bits/stdc++.h>
#define ll     long long
using namespace std;

#define sz 200005
string  a,b,ans = "";
int n,m,dp[2][1<<19];

bool Check(int mask,int pos)
{
    return (bool)(mask&(1<<pos));
}
int Set(int mask,int pos)
{
    return (mask|(1<<pos));
}


ll FuN(int isSmall, int mask)
{
    int taken = 0;
    for(int i=0;i<n;i++)
    {
        if(Check(mask,i))
            taken++;
    }
    if(taken==n)
        return 1;
    if(dp[isSmall][mask] != -1)
        return dp[isSmall][mask];
    int ret = 0;
    for(int i=0;i<n;i++)
    {
        if(Check(mask,i))
            continue;
        if(isSmall)
            ret |= FuN(isSmall , Set(mask , i));
        else if(a[i] <= b[taken])
            ret |= FuN(isSmall|(a[i]<b[taken]) , Set(mask , i));
        if(ret){
            ans+=a[i];
            break;
        }
    }
    return dp[isSmall][mask] = ret;
}
void Solve(int t)
{
    cin>>a>>b;
    n = a.size();
    m = b.size();
    sort(a.begin(),a.end());
    reverse(a.begin(),a.end());
    if(n<m)
    {
        cout<<a<<endl;
    }
    else
    {
        memset(dp,-1,sizeof(dp));
        int ret = FuN(0,0);
        reverse(ans.begin(),ans.end());
        cout<<ans<<endl;
    }
}
int main()
{
    int T=1,t;
//    scanf("%d",&T);
    for(t=1;t<=T;t++)
    {
        Solve(t);
    }
    return 0;
}
