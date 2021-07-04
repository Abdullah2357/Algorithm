#include<bits/stdc++.h>
using namespace std;


double FuN(int n,int k)
{
    int cnt = 0;
    while(n>k)
    {
        cnt++;
        n/=k;
    }
    return (double)(cnt+(double)n/k);
}
void Solve(int t)
{
    int n,k,i;
    scanf("%d %d",&n,&k);
    double  ans = 0;
    for(i=1;i<=n;i++)
    {
        ans += FuN(i,k);
    }
    ans+=1;
    printf("Case %d: %d\n",t,ans);
}
int main()
{
    int t,T;
    cout<<FuN(9,10)<<endl;
    scanf("%d",&T);
    for(t=1;t<=T;t++)
    {
        Solve(t);
    }
    return 0;
}
