#include<bits/stdc++.h>
using namespace std;
int SOD[1000000];
void SODF()
{
    memset(SOD,0,sizeof(SOD));
    int i,j;
    for(i=1;i<=1e6;i++)
    {
        for(j=i;j<=1e6;j+=i)
        {
            SOD[j] += i;
        }
    }
}
long long a[1000005];
void ans()
{
    a[0]=0;
    a[1] = 0;
    SODF();
    int i;
    for(i=2;i<=1000000;i++)
    {
        a[i] = a[i-1]+SOD[i]-i;
    }
}
int main()
{
    long long t,n;
    ans();
    scanf("%lld",&t);
    while(t--)
    {
        scanf("%lld",&n);
        printf("%lld\n",a[n]);
    }
    return 0;
}
