#include<bits/stdc++.h>
using namespace std;

long long n,w,wt[105],v[105];
long long dp[105][100005];

long long FuN(long long pos,long long capacity)
{
    if(pos>n)
        return 0;
    if(dp[pos][capacity]!=-1)
        return dp[pos][capacity];
    long long ret1=0,ret2=0;
    if(wt[pos]<=capacity)
        ret1 = v[pos]+FuN(pos+1,capacity-wt[pos]);
    ret2 = FuN(pos+1,capacity);
    return dp[pos][capacity] = max(ret1,ret2);
}

int main()
{
    cin>>n>>w;
    for(int i=1;i<=n;i++)
    {
        cin>>wt[i]>>v[i];
    }
    memset(dp,-1,sizeof(dp));
    cout<<FuN(1,w)<<endl;
    return 0;
}
