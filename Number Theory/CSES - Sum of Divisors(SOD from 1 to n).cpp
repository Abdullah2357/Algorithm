#include<bits/stdc++.h>
#define ll                  long long
#define endl                '\n'
#define F                   first
#define S                   second
#define all(a)              (a.begin()),(a.end())
#define UNIQUE(X)           (X).erase(unique(all(X)),(X).end())
#define SORT_UNIQUE(c)      (sort(c.begin(),c.end()), c.resize(distance(c.begin(),unique(c.begin(),c.end()))))
#define ms(a,b)             memset(a, b, sizeof(a))
#define MOD                 1000000007
#define sz                  200005
using namespace std;

ll BigMOD(ll a, ll b, ll m){
    if(b == 0)
        return 1%m;
    ll temp = BigMOD(a, b/2, m)%m;
    temp = (temp*temp) % m;
    if(b%2){
        temp = (temp * a)%m;
    }
    return temp;
}


int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    ll n, i, ans = 0;
    cin>>n;
    for(i = 1; i*i <= n; i++){
        ans += (i*(n/i))%MOD;
        ans %= MOD;
    }

    ll l=(ll)sqrt(n);
    for(ll i=1;i<=sqrt(n);i++)
    {
        ll r = n/i;
        ll sum = ((((r%MOD)*((r+1)%MOD))%MOD)*BigMOD(2, MOD-2, MOD))%MOD;
        sum %= MOD;
        sum -= ((((l%MOD)*((l+1)%MOD))%MOD)*BigMOD(2, MOD-2, MOD))%MOD;
        sum = (sum + MOD)%MOD;
        ans = (ans + sum)%MOD;
    }
    cout<<ans<<endl;

    return 0;
}
