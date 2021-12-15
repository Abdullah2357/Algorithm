#include<bits/stdc++.h>
#define ll     long long
using namespace std;

#define sz 200005
const int MOD = 1e9+7;

int n,dp[505][505],a,b;

int FuN(int w,int h)
{
    if(w == h)
    {
        return 0;
    }

    if(dp[w][h] != -1)
        return dp[w][h];

    int ret = 1e9;
    for(int i = 1; i < w; i++)
    {
        ret = min(ret, FuN(i,h) + FuN(w-i,h) + 1);
    }

    for(int i = 1; i < h; i++)
    {
        ret = min(ret, FuN(w,i) + FuN(w,h-i) + 1);
    }

    return dp[w][h] = ret;
}


void Solve(int t)
{
    scanf("%d %d",&a,&b);
    memset(dp,-1,sizeof(dp));

    int ans = FuN(a,b);
    printf("%d\n",ans);

}
int main()
{
    int t,T=1;
//    scanf("%d",&T);
    for(t=1;t<=T;t++)
    {
        Solve(t);
    }
    return 0;
}

