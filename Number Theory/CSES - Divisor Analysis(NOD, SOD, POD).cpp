#include<bits/stdc++.h>
#define ll                  long long
#define endl                '\n'
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
    ll n, i, x, k, NOD = 1, SOD = 1, POD = 1,  div=1;
    cin>>n;
    for(i = 1; i <= n; i++)
    {
        cin>>x>>k;
        NOD  = (NOD * (k+1))%MOD;
        SOD *= (BigMOD(x, k+1, MOD) - 1 +MOD)%MOD;
        SOD %= MOD;
        SOD *= BigMOD(x-1, MOD-2, MOD);
        SOD %= MOD;

        POD = BigMOD(POD, k+1, MOD);
        POD %= MOD;
        POD *= BigMOD(BigMOD(x, (k*(k+1))/2, MOD), div, MOD);
        POD %= MOD;
        div = (div*(k+1))%(MOD-1);
    }

    cout<<NOD<< ' ' <<SOD<< ' '<<POD<<endl;
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int t, T = 1;
    // cin>>T;
    for(t = 1; t <= T; t++)
        Solve(t);
    return 0;
}
