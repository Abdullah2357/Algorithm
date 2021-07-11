#include<bits/stdc++.h>
#define ll     long long
using namespace std;

#define sz 400005


ll ST[20][sz], a[sz];

void Compute_ST(int n)
{
    for(int i=0;i<n;i++)
        ST[0][i] = a[i];
    for(int k=1;(1<<k) < n;k++)
    {
        for(int i=0;i+(1<<k)<=n;i++)
        {
            ll x = ST[k-1][i];
            ll y = ST[k-1][i+(1<<k-1)];
            ST[k][i] = __gcd(x,y);
        }
    }
}

ll Query(int l,int r)
{
    ll k = log2(r-l);
    ll x = ST[k][l];
    ll y = ST[k][r-(1<<k)+1];
    return __gcd(x,y);
}
void Solve(int t)
{
    ll i, ans = 0, gcd = 0,n;

    cin>>n;

    for(i=0;i<n;i++)
    {
        cin>>a[i];
        gcd = __gcd(gcd,a[i]);
    }

    for(i=0;i<n;i++)
    {
        a[i]/=gcd;
        a[i+n] = a[i];
    }

    Compute_ST(2*n);

    for(i=0;i<2*n;i++)
    {
        ll lo = i,hi = 2*n-1,mid,res = 2*n-1;

        while(lo<=hi)
        {
            mid = (lo+hi)/2;
            if(Query(i,mid)==1)
            {
                res = mid;
                hi = mid-1;
            }
            else
                lo = mid+1;
        }

        ans = max(ans,res-i);
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
