#include<bits/stdc++.h>
#define ll              long long
#define Input           freopen("input.txt","r",stdin)
#define Output          freopen("output.txt","w",stdout)
#define gcd(a,b)        __gcd(a,b)
#define lcm(a,b)         (a)*(b)/gcd(a,b)
#define PI              2*acos(0.0)
#define MOD             1000000007

using namespace std;

/** Sieve, PrimeFactorize, BigMOD **/
//vector<ll>Prime;
//bool mark[10000003];
//void sieve(ll n){ll i,j;mark[1]=1;for(i=4; i<=n; i+=2)mark[i]=1;Prime.push_back(2);for(i=3; i<=n; i+=2){if(!mark[i]){Prime.push_back(i);if(i*i<=n){for(j=i*i; j<=n; j+=(i*2))mark[j]=1;}}}}
//map<ll,ll>Factor;
//void Primefactorize(ll n){for(ll i=0; i<Prime.size() && Prime[i]*Prime[i]<=n; i++){if(n%Prime[i] == 0){while(n%Prime[i] == 0){Factor[Prime[i]]++;n/=Prime[i];}}}if(n>1){Factor[n]++;}}
//ll BigMod(ll a,ll b){if(b == 0)return 1%MOD;else if(b%2 == 0){ll temp=BigMod(a,b/2);return ((temp%MOD)*(temp%MOD))%MOD;}else{return ((a%MOD)*BigMod(a,b-1)%MOD)%MOD;}}
/**     Order Set       **/
//#include <ext/pb_ds/assoc_container.hpp>
//using namespace __gnu_pbds;
//template<typename T> using orderset = tree<T,null_type,less<T>,rb_tree_tag,tree_order_statistics_node_update>;
int Set(int N, int pos) {return  N = N | (1<<pos);}
int Reset(int N, int pos) {return  N = N & ~(1<<pos);}
bool Cheek(int N, int pos) {return  (bool)(N & (1<<pos));}
///const int fx[] = {+1,-1,+0,+0};
///const int fy[] = {+0,+0,+1,-1};

#define sz 200005

ll n,a[sz];

void Solve(int t)
{
    ll i, j, fg = 0, x, y, ans = 0;
    cin>>n;
    for(i=1;i<=n;i++)
    {
        cin>>a[i];
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
