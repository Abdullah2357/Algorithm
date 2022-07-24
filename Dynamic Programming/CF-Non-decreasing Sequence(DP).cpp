///link https://codeforces.com/gym/390737/problem/E

#include<bits/stdc++.h>
#define ll      long long
using namespace std;

#define sz 3005

ll n,a[sz],sum[sz];
ll dp[sz][sz];
///dpi,j means maximum number of sub-array from index i to n

ll SUM(int i,int j)
{
    return sum[j]-sum[i-1];
}

ll FuN(int i,int j)
{
    if(j>=n)
        return 0;
    if(dp[i][j]!=-1)
        return dp[i][j];
    ll ret = 0;
    ll lo=j+1,hi=n,mid,res=-1;
    while(lo<=hi)
    {
        mid = (lo+hi)/2;
        if(SUM(j+1,mid)>=SUM(i,j))
        {
            res = mid;
            hi =mid-1;
        }
        else
            lo = mid+1;
    }
    if(res!=-1)
        ret = max(ret,1+FuN(j+1,res));
    ret = max(ret,FuN(i,j+1));
    return dp[i][j]=ret;

}

void Solve(int t)
{
    ll i, j, x=0, y=0, fg=0, ans = 0;
    scanf("%lld",&n);
    for(i=1;i<=n;i++)
    {
        scanf("%lld",&a[i]);
        sum[i] = sum[i-1]+a[i];
    }
    memset(dp,-1,sizeof(dp));
    ans = 1+FuN(1,1);
    printf("%lld\n",n-ans);


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



