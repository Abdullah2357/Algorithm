#include<bits/stdc++.h>
using namespace std;

int n,i,mark[3002][1502];
double p[3002],dp[3002][1502];

double FuN(int pos,int head)
{
    if(pos>n)
    {
        return 1.0;
    }
    if(mark[pos][head])
        return dp[pos][head]*1.0;
    double ret=0.0;
    ret += p[pos]*1.0 * FuN(pos+1,head+1);
    if(pos-head-1 < (int)(n/2)){
        ret += (1.0-p[pos])*1.0 * FuN(pos+1,head);
    }
    mark[pos][head] = 1;
    return dp[pos][head] = ret;
}
int main()
{
    cin>>n;
    for(i=1;i<=n;i++)
    {
        cin>>p[i];
    }
    //memset(dp,-1,sizeof(dp));
    memset(mark,0,sizeof(mark));
    double ans = FuN(1,0);
    printf("%.10f\n",ans);
   // cout<<ans<<endl;
    return 0;
}

