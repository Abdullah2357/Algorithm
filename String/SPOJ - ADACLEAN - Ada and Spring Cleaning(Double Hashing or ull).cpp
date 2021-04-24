#include<bits/stdc++.h>
#define ll     long long
using namespace std;

#define sz 100005
const ll MOD = 1e9+9;
const ll MOD2 = 1e9+7;

ll hashsum[sz],p[sz],hashsum2[sz],p2[sz];
ll Hashing(ll l,ll r)
{
    return (hashsum[r]-hashsum[l-1]+MOD)%MOD;
}
ll Hashing2(ll l,ll r)
{
    return (hashsum2[r]-hashsum2[l-1]+MOD2)%MOD2;
}
void Solve()
{
    string s;
    ll n,k,i,ans=0,l,r;
    cin>>n>>k>>s;
    for(i=1;i<=n;i++)
    {
        hashsum[i] = hashsum[i-1]+((s[i-1]-'a'+1)*p[i])%MOD;
        hashsum[i]%=MOD;
        hashsum2[i] = hashsum2[i-1] + ((s[i-1]-'a'+1)*(p2[i]))%MOD2;
        hashsum2[i] %=MOD2;
        ///cout<<hashsum[i]<< ' '<<hashsum2[i]<<endl;
    }
    set<pair<ll,ll>> st;
    for(i=1;i+k-1<=n;i++)
    {
        l = i,r=i+k-1;
        ll a = Hashing(l,r);
        ll b = p[n-i]%MOD;
        ll h1 = (a*b)%MOD;
        a = Hashing2(l,r);
        b = p2[n-i]%MOD2;
        ll h2 = (a*b)%MOD2;
        st.insert(make_pair(h1,h2));
        //cout<<(a*b)%MOD<<endl;
    }
    cout<<st.size()<<endl;
}

int main()
{
    p[0]=1;
    p2[0]= 1;
    for(int i=1;i<=sz-2;i++)
    {
        p[i] = p[i-1]*31;
        p[i]%=MOD;
        p2[i] = p2[i-1]*31;
        p2[i]%=MOD2;
    }
    int T;
    scanf("%d",&T);
    while(T--)
    {
        Solve();
    }
}
//#include<bits/stdc++.h>
//#define ull    unsigned long long
//using namespace std;
//
//#define sz 100005
//
//ull hashsum[sz],p[sz];
//ull Hashing(ull l,ull r)
//{
//    return (hashsum[r]-hashsum[l-1]);
//}
//void Solve()
//{
//    string s;
//    ull n,k,i,ans=0,l,r;
//    cin>>n>>k>>s;
//    for(i=1;i<=n;i++)
//    {
//        hashsum[i] = hashsum[i-1]+(((ull)s[i-1])*p[i]);
//    }
//    set<ull> st;
//    for(i=1;i<=n-k+1;i++)
//    {
//        l = i,r=i+k-1;
//        ull H = (Hashing(l,r)*p[n-i]);
//        st.insert(H);
//    }
//    cout<<st.size()<<endl;
//}
//
//int main()
//{
//    p[0]=1;
//    for(int i=1;i<=sz-2;i++)
//    {
//        p[i] = p[i-1]*269;
//    }
//    int T;
//    scanf("%d",&T);
//    while(T--)
//    {
//        Solve();
//    }
//}
