#include<bits/stdc++.h>
#define ll     long long
using namespace std;

#define sz 200005

ll n,a[sz],dp[sz][30],next[sz];
string s;

ll FuN(int pos,int last)
{
    if(pos==n)
        return 0;
    if(dp[pos][last]!=-1)
        return dp[pos][last];
    ll ret = 0;
    if(s[pos]-'a'>=last){
        ret = 1+FuN(pos+1,s[pos]-'a');
    }
    ret = max(ret,FuN(pos+1,last));
    return dp[pos][last] = ret;
}

void Print(int pos,int last)
{
    if(pos==n){
        printf("\n");
        return ;
    }
    ll ret1 = 0,ret2 = 0;
    if(s[pos]-'a'>=last){
        ret1 = 1 + dp[pos+1][s[pos]-'a'];
        ret2 = dp[pos+1][last];
        if(ret1>ret2)
        {
            printf("%c",s[pos]);
            Print(pos+1,s[pos]-'a');
        }
        else
        {
            Print(pos+1,last);
        }
    }
    else{
        ret2 = dp[pos+1][last];
        Print(pos+1,last);
    }
    return ;
}

void Solve(int t)
{
    ll i, j, fg = 0, x, y, ans = 0;
    cin>>s;
    n =s.size();
    memset(dp,-1,sizeof(dp));
    ans = FuN(0,0);

    cout<<ans<<endl;
    Print(0,0);
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
