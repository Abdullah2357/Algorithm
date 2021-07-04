#include<bits/stdc++.h>
#define ll     long long
using namespace std;

#define sz 1005
const int MOD = 998244353;
ll dp[sz][2*sz][3][3];
ll n,k;

ll FuN(int pos,int taken,int one,int two)
{
    if(pos>n)
    {
        taken++;
        if(one!=two)
            taken++;
        return taken==(k);
    }
    if(dp[pos][taken][one][two] != -1)
        return dp[pos][taken][one][two];
    ll ret = 0;
    if(one==0 && two==0){
        ret =  FuN(pos+1,taken+1,1,1);
        ret += FuN(pos+1,taken, 1, 0);
        ret %= MOD;
        ret += FuN(pos+1,taken, 0, 1);
        ret += FuN(pos+1,taken, 0, 0);
    }
    else if(one==1 && two==1)
    {
        ret =  FuN(pos+1,taken+1,0,0);
        ret += FuN(pos+1,taken, 1, 0);
        ret %= MOD;
        ret += FuN(pos+1,taken, 0, 1);
        ret += FuN(pos+1,taken, 1, 1);
    }
    else if(one==1 && two==0)
    {
        ret =  FuN(pos+1, taken+1, 1, 1);
        ret += FuN(pos+1, taken, 1, 0);
        ret %= MOD;
        ret += FuN(pos+1, taken+2, 0, 1);
        ret += FuN(pos+1, taken+1, 0, 0);
    }
    else if(one==0 && two==1)
    {
        ret =  FuN(pos+1,taken+1, 1,1);
        ret += FuN(pos+1,taken+2, 1, 0);
        ret %= MOD;
        ret += FuN(pos+1,taken, 0, 1);
        ret += FuN(pos+1,taken+1, 0, 0);
    }
    else
    {
        ret += FuN(pos+1,taken,1,0);
        ret += FuN(pos+1,taken,1,1);
        ret %= MOD;
        ret += FuN(pos+1,taken,0,0);
        ret += FuN(pos+1,taken,0,1);
    }
    ret %= MOD;
    return dp[pos][taken][one][two] = ret;
}
int main()
{
    cin>>n>>k;
    memset(dp,-1,sizeof(dp));
    ll ans = FuN(1,0,2,2);
    cout<<ans<<endl;
}

