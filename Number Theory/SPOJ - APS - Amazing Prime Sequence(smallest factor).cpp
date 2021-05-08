#include<bits/stdc++.h>
using namespace std;
int SF[10000010];
void fun()
{
    int n = 10000001,i,j;
    memset(SF,0,sizeof(SF));
    for(i=2;i*i <= n;i++)
    {
        for(j=i;j<=n;j+=i)
        {
            if(SF[j] == 0)
                SF[j] = i;
        }
    }
    for(i=2;i<=n;i++)
    {
        if(SF[i]==0)
            SF[i] = i;
    }
}
long long a[10000005];
void info()
{
    a[0] = 0;
    a[1] = 0;
    fun();
    int i,n=10000000;
    for(i=2;i<=n;i++)
    {
        a[i] = a[i-1]+ SF[i];
    }
}
int main()
{
    long long t,n,ans;
    info();
    scanf("%lld",&t);
    while(t--)
    {
        scanf("%lld",&n);
        ans = a[n];
        printf("%lld\n",ans);
    }
    return 0;
}
