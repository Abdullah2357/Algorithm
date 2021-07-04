#include<bits/stdc++.h>
#define ll     long long
using namespace std;

#define sz 100000002
vector<int>Prime;
bool mark[sz];
void sieve(ll n){
    ll i,j;
    mark[1]=1;
    for(i=4; i<=n; i+=2)
        mark[i]=1;
    Prime.push_back(2);
    for(i=3; i<=n; i+=2)
    {
        if(!mark[i])
        {
            Prime.push_back(i);
            if(i*i<=n)
            {
                for(j=i*i; j<=n; j+=(i*2))
                    mark[j]=1;
            }
        }
    }
}
ll ans[sz];
const ll MOD = 4294967296;
void Solve(int t)
{
    int n;

    scanf("%d",&n);

    printf("Case %d: %lld\n",t,ans[n]);
}
int main()
{
    sieve(sz-2);

    for(int i=0;i<sz;i++)
    {
        ans[i] = 1;
    }

    for(int i=0;i<Prime.size();i++)
    {
        ll x = Prime[i];
        while(x<sz)
        {
            ans[x] = (ans[x] * Prime[i])%MOD;
            x*=Prime[i];
        }
    }

    for(int i=2;i<sz;i++)
    {
        ans[i]= (ans[i] * ans[i-1])%MOD;
    }


    int t,T=1;
    scanf("%d",&T);
    for(t=1;t<=T;t++)
    {
        Solve(t);
    }
    return 0;
}

