#include<bits/stdc++.h>
#define ll              long long
#define Input           freopen("input.txt","r",stdin)
#define Output          freopen("output.txt","w",stdout)
#define gcd(a,b)        __gcd(a,b)
#define lcm(a,b)        (a)*(b)/gcd(a,b)
#define PI              2*acos(0.0)
#define MOD             1000000007

using namespace std;

/** Sieve, PrimeFactorize, BigMOD, primefactorize in log n **/
vector<ll>Prime;
bool mark[10000003];
void sieve(ll n){ll i,j;mark[1]=1;for(i=4; i<=n; i+=2)mark[i]=1;Prime.push_back(2);for(i=3; i<=n; i+=2){if(!mark[i]){Prime.push_back(i);if(i*i<=n){for(j=i*i; j<=n; j+=(i*2))mark[j]=1;}}}}
map<ll,ll>Factor;
void Primefactorize(ll n){for(ll i=0; i<Prime.size() && Prime[i]*Prime[i]<=n; i++){if(n%Prime[i] == 0){while(n%Prime[i] == 0){Factor[Prime[i]]++;n/=Prime[i];}}}if(n>1){Factor[n]++;}}
//ll BigMod(ll a,ll b){if(b == 0)return 1%MOD;else if(b%2 == 0){ll temp=BigMod(a,b/2);return ((temp%MOD)*(temp%MOD))%MOD;}else{return ((a%MOD)*BigMod(a,b-1)%MOD)%MOD;}}
//int SF[10000005];
//void FuN(){for( int i = 2 ; i * i <= 10000000 ; i ++ ){if( !SF[i] ){for( int j = i ; j <= 10000000 ; j += i ){if( !SF[j] ) SF[j] = i ;}}for( int i = 2 ; i <= 1e7 ; i ++ ) if( !SF[i] ) SF[i] = i ;}
//vector<int> Factor;/**map<int,int> Factor;**/
//void GetFactor(int n){Factor.clear();while(n!=1){/**Factor[SF[n]]++;**/Factor.push_back(SF[n]);n/=SF[n];}}

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

ll l,lc;

ll Power(ll a,ll b)
{
    ll res = 1;
    while(b--)
    {
        res*=a;
    }
    return res;
}

void Solve(int t)
{
    ll a,b;
    scanf("%lld %lld %lld",&a,&b,&l);
    lc = lcm(a,b);
//    cout<<lc<<endl;
    Factor.clear();
    Primefactorize(lc);
    map<ll,ll> m = Factor;
    Factor.clear();
    Primefactorize(l);
    ll ans = 1,fg=1;
//    for(auto it:Factor)
//        cout<<it.first<< ' '<<it.second<<endl;
    for(auto it:Factor)
    {
        if(it.second==m[it.first])
            m[it.first] = 0;
        else if(it.second>m[it.first]){
            ans *= Power(it.first,it.second);
            m[it.first] = 0;
        }
        else
            fg=0;
    }
    for(auto it:m)
    {
        if(it.second>0)
            fg=0;
    }
    if(fg)
        printf("Case %d: %lld\n",t,ans);
    else
        printf("Case %d: impossible\n",t);
}
int main()
{
    int t,T=1;
    sieve(1000000);
    scanf("%d",&T);
    for(t=1;t<=T;t++)
    {
        Solve(t);
    }
    return 0;
}

