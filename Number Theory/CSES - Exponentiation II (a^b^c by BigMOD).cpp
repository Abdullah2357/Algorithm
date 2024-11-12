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
void Solve(int t)
{
    ll a, b, c;
    cin>>a>>b>>c;
    ll ans = BigMOD(b, c, MOD - 1);
    ans = BigMOD(a, ans, MOD);
    cout<<ans<<endl;
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int t, T = 1;
    cin>>T;
    for(t = 1; t <= T; t++)
        Solve(t);
    return 0;
}
