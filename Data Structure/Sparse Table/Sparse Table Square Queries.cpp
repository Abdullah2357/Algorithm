#include<bits/stdc++.h>
#define ll long long
using namespace std;

ll ST[505][12][505];
ll a[505][505];

void Compute_ST(ll row , ll n)
{
    for(ll i=0;i<n;i++) ST[row][0][i] = a[row][i];
    for(ll k=1 ; (1<<k) < n; k++)
    {
        for(ll i=0; i+(1<<k)<=n ; i++)
        {
            ll x = ST[row][k-1][i];
            ll y = ST[row][k-1][i+(1<<k-1)];
            ST[row][k][i] = max(x, y);
        }
    }
}
ll RMQ(ll row, ll i, ll j)
{
    ll k = log2(j-i);
    ll x = ST[row][k][i];
    ll y = ST[row][k][j - (1<<k)+1];
    return max(x, y);
}
void Solve(int t)
{
    ll n,i,j,q;
    scanf("%lld %lld",&n,&q);
    for(i = 0; i < n ;i++)
    {
        for(j = 0 ; j < n ; j++ ){
            scanf("%lld",&a[i][j]);
        }
    }
    for(i=0;i<n;i++) {
        Compute_ST(i, n);
    }
    printf("Case %d:\n",t);
    while(q--)
    {
        ll s, l, r;
        scanf("%lld %lld %lld",&l,&r,&s);
        l--,r--;
        ll ans = 0;
        for(i=l;i<=l+s-1;i++)
        {
            if(r==r+s-1)
                ans = max(ans, a[i][r]);
            else
                ans = max(ans, RMQ(i, r , r+s-1));
        }
        printf("%lld\n",ans);
    }
}
int main()
{
    int T,t;
    scanf("%d",&T);
    for(t=1;t<=T;t++)
    {
        Solve(t);
    }
    return 0;
}

