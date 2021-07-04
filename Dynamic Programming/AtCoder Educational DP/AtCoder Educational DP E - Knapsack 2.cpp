/// Knapsack 2

#include<bits/stdc++.h>
using namespace std;

long long n,w,wt[105],v[105];
long long dp[105][100005],mx=0;

long long FuN(long long pos,long long price)
{
    if(pos>n){
        if(price==0)
            return 0;
        return 2e9;
    }
    if(dp[pos][price]!=-1)
        return dp[pos][price];
    long long ret1=1e9,ret2=1e9;
    ret1 = wt[pos]+FuN(pos+1,price-v[pos]);
    ret2 = FuN(pos+1,price);

    return dp[pos][price] = min(ret1,ret2);
}

int main()
{
    cin>>n>>w;
    for(int i=1;i<=n;i++)
    {
        cin>>wt[i]>>v[i];
    }
    memset(dp,-1,sizeof(dp));
    int ans=0;
    for(int i=100000;i>=0;i--)
    {
        if(FuN(1,i) <= w){
            ans = i;
            break;
        }
    }
    cout<<ans<<endl;
    return 0;
}
