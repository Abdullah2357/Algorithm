#include<bits/stdc++.h>
#define ll     long long
using namespace std;

#define sz 100005
const int MOD = 1e9+7;
ll n,d;
ll dp[2][2][sz][105];
    string s;

ll FuN(int isStart,int isSmall, int pos, int num)
{
    if(pos==n)
    {
        if(num%d==0 && !isStart)
            return 1;
        return 0;
    }
    if(dp[isStart][isSmall][pos][num] != -1)
        return dp[isStart][isSmall][pos][num];
    ll ret = 0,canbeput = s[pos]-'0';
    if(isSmall)
        canbeput = 9;
    if(isStart)
    {
        ret += FuN(1,1,pos+1,num);
        ret %= MOD;
        for(int i=1;i<=canbeput;i++)
        {
            ret += FuN(0,isSmall|(i<(s[pos]-'0')), pos+1,(num+i)%d);
            ret %= MOD;
        }
    }
    else
    {
        for(int i=0;i<=canbeput;i++)
        {
            ret += FuN(0,isSmall|(i<(s[pos]-'0')), pos+1,(num+i)%d);
            ret %= MOD;
        }
    }
    return dp[isStart][isSmall][pos][num] = ret;
}
void Solve(int t)
{
    cin>>s>>d;
    n = s.size();
    memset(dp,-1,sizeof(dp));
    ll ans = FuN(1,0,0,0);
    cout<<ans<<endl;
}
int main()
{
    int t,T=1;
//    scanf("%d",&T);
    for(t=1;t<=T;t++)
    {
        Solve(t);
    }
    return 0;
}

