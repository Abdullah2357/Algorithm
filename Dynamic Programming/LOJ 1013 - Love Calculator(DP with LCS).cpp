#include<bits/stdc++.h>
#define ll     long long
using namespace std;

#define sz 32

ll d[sz][sz], n, m, dp[2*sz][sz][sz], expectedSize;
string s, s2;

ll FindLCS(int i,int j)
{
    if(i==n || j==m)
        return 0;
    if(d[i][j]!=-1)
        return d[i][j];
    ll ret = 0;
    if(s[i]==s2[j])
    {
        ret = 1+FindLCS(i+1,j+1);
    }
    else
    {
        ret = max(FindLCS(i,j+1),FindLCS(i+1,j));
    }
    return d[i][j] = ret;
}

ll FuN(int pos,int pos1,int pos2)
{
    if(pos1==n)
    {
        return (pos+(m-pos2))==expectedSize;
    }
    if(pos2==m)
    {
        return (pos+(n-pos1))==expectedSize;
    }
    if(dp[pos][pos1][pos2]!=-1)
        return dp[pos][pos1][pos2];

    ll ret = 0;

    if(s[pos1]==s2[pos2])
    {
        ret = FuN(pos + 1, pos1 + 1, pos2 + 1);
    }
    else
    {
        ret = FuN(pos + 1, pos1 + 1, pos2) + FuN(pos + 1, pos1, pos2 + 1);
    }
    return dp[pos][pos1][pos2] = ret;
}
void Solve(int t)
{
    cin>>s>>s2;
    n = s.size();
    m = s2.size();

    memset(d, -1, sizeof(d));
    memset(dp, -1, sizeof(dp));

    expectedSize = n+m-FindLCS(0,0);

    printf("Case %d: %lld %lld\n", t, expectedSize, FuN(0,0,0));
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
