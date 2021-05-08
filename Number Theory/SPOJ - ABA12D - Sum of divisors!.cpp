#include<bits/stdc++.h>
using namespace std;
vector<long long> prime;
bool mark[10000005];
void sieve()
{
    int n = 10000000;
    int  sqrtn = sqrt(n),i,j;
    mark[1] = 1;
    prime.push_back(2);
    for(i=4;i<=n;i+=2)
    {
        mark[i] = 1;
    }
    for(i=3;i<=n;i+=2)
    {
        if(mark[i]==0)
        {
            prime.push_back(i);
            if(i<=sqrtn+2)
            {
                for(j=i*i ; j<=n ; j += (2*i))
                {
                    mark[j] = 1;
                }
            }
        }
    }
}
int SOD[1000010];
void SODF()
{
    memset(SOD,0,sizeof(SOD));
    int i,j;
    for(i=1;i<=1000000;i++)
    {
        for(j=i;j<=1000000;j+=i)
        {
            SOD[j] += i;
        }
    }
}
int main()
{
    int t,a,b,c,i;
    SODF();
    sieve();
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d %d",&a,&b);
        c=0;
        for(i=a;i<=b;i++)
        {
            if(mark[SOD[i]] == 0)
            {
                c++;
            }
        }
        printf("%d\n",c);
    }
    return 0;
}
