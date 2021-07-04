#include<bits/stdc++.h>
#define ll    unsigned long long
using namespace std;

int Set(int N, int pos) {return  N = N | (1<<pos);}
bool Cheek(int N, int pos) {return  (bool)(N & (1<<pos));}

#define sz 17

ll dp[1<<sz][21];
int base,k,n;
string s;

ll power(int a,int b)
{
    ll ret = 1;
    for(int i=1;i<=b;i++)
    {
        ret *= a;
    }
    return ret;
}
ll FuN(int mask,int num)
{
    int usedbit = __builtin_popcount(mask);
    if(usedbit==n)
    {
        return num%k==0;
    }
    if(dp[mask][num] != -1)
        return dp[mask][num];
    ll ret = 0;
    for(int i=0;i<n;i++)
    {
        if(Cheek(mask,i))
            continue;

        ll x;
        if(s[i]-'0'<=9)
            x = (s[i]-'0') * power(base,usedbit);
        else
            x = ((s[i]-'A')+10)*power(base,usedbit);

        ret += FuN(Set(mask,i),(num+ x)%k);
    }
    return dp[mask][num] = ret;
}

void Solve(int t)
{
    scanf("%d %d",&base,&k);
    cin>>s;
    n = s.size();

    memset(dp, -1, sizeof(dp));
    ll ans = FuN(0,0);
    printf("Case %d: %llu\n", t, ans);
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
