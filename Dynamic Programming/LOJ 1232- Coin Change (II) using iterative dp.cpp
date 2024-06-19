#include<bits/stdc++.h>
#define ll      long long
#define MOD     1000000007
#define sz      200005
using namespace std;

int n, k, a[105];
int dp[10005];

void Solve(int t)
{
    int i, j, ans =0, fg=0;
    cin>>n>>k;
    for(i=0;i<n;i++)
    {
        cin>>a[i];
    }
    memset(dp,0,sizeof(dp));
    dp[0] = 1;
    for(i = 0; i < n; i++)
    {
        for( j= a[i]; j <= k; j++)
        {
            dp[j] = (dp[j] + dp[j - a[i]])%100000007;
        }
    }
    cout<<"Case "<<t<<": "<<dp[k]<<'\n';
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int t,T=1;
    cin>>T;
    for(t=1;t<=T;t++)
    {
        Solve(t);
    }
    return 0;
}

