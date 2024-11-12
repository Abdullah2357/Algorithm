#include<bits/stdc++.h>
#define ll                  long long
#define endl                '\n'
#define F                   first
#define S                   second
#define all(a)              (a.begin()),(a.end())
#define UNIQUE(X)           (X).erase(unique(all(X)),(X).end())
#define SORT_UNIQUE(c)      (sort(c.begin(),c.end()), c.resize(distance(c.begin(),unique(c.begin(),c.end()))))
#define ms(a,b)             memset(a, b, sizeof(a))
#define MOD                 10000007
#define sz                  1000005
using namespace std;


vector<ll>Prime;
bool mark[1000003];
void sieve(ll n){
    ll i,j;
    mark[1]=1;
    for(i=4; i<=n; i+=2)
        mark[i]=1;
    Prime.push_back(2);
    for(i=3; i<=n; i+=2){
        if(!mark[i]){
            Prime.push_back(i);
            if(i*i<=n){
                for(j=i*i; j<=n; j+=(i*2))
                    mark[j]=1;
            }
        }
    }
}

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

ll FactorFrequency(ll n, ll p)
{
    ll res = 0;
    while(n >= p)
    {
        res += n/p;
        n /= p;
    }
    return res;
}


void Solve()
{
    ll n;
    while(cin>>n && n!=0){
        ll ans = 1;

        for(int i = 0; i < Prime.size(); i++)
        {
            ll Fre = FactorFrequency(n, Prime[i]);
            if(Fre > 0)
                ans = (ans * (((Fre+1)*(Fre+2))/2)%MOD )%MOD;
        }
        cout<<ans<<endl;
    }
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    sieve(1000000);
    Solve();
    return 0;
}
