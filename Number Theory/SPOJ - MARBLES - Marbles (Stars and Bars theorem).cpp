#include<bits/stdc++.h>
#define ll    long long
using namespace std;

#define sz 200005

ll n,a[sz],k;

void Solve(int t)
{
    ll i, j, fg = 0, x, y, ans = 1;
    cin>>n>>k;
    n--,k--;
    ll r = min(k,n-k);
    x = 1;
    for(i=n-r+1;i<=n;i++)
    {
        ans *= i;
        ans/=x;
        x++;
    }
    cout<<ans<<endl;
}
int main()
{
    int t,T=1;
    scanf("%d",&T);
    for(t=1;t<=T;t++)
    {
        Solve(t);
    }
    return 0;
}
