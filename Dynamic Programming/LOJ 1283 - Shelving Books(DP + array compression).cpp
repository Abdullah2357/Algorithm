#include<bits/stdc++.h>
#define ll     long long
using namespace std;

#define sz 102

int n,a[sz],dp[sz][sz][sz];
map<int,int> m;
set<int> s;

int FuN(int pos,int lft,int rgt)
{
    if(pos>n)
        return 0;
    if(dp[pos][lft][rgt]!=-1)
        return dp[pos][lft][rgt];
    int ret = 0;
    ret = FuN(pos+1,lft,rgt);
    if(a[pos]>=lft && a[pos]<=rgt){
        ret = max(ret, 1 + FuN(pos+1,a[pos],rgt));
        ret = max(ret, 1 + FuN(pos+1,lft,a[pos]));
    }
    return dp[pos][lft][rgt] = ret;
}

void Solve(int t)
{
    int i,cnt=1;

    scanf("%d",&n);
    m.clear(),s.clear();
    for(i=1;i<=n;i++)
    {
        scanf("%d",&a[i]);
        s.insert(a[i]);
    }

    for(auto it:s)
    {
        if(!m[it])
            m[it] = cnt++;
    }
    for(i=1;i<=n;i++)
    {
        a[i] = m[a[i]];
    }

    memset(dp,-1,sizeof(dp));
    int ans = FuN(1,0,101);

    printf("Case %d: %d\n",t,ans);
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
