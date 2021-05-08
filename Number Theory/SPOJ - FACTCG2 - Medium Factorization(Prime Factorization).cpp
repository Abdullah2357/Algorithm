#include<bits/stdc++.h>
using namespace std;
vector<int> prime;
bool mark[4005];
void sieve()
{
    int n = 4000;
    int sqrtn = sqrt(n),i,j;
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
            if(i<=sqrtn)
            {
                for(j=i*i;j<=n;j+=(2*i))
                {
                    mark[j] = 1;
                }
            }
        }
    }
}
vector<int> factor;
void primefactorize(int n)
{
    factor.clear();
    int i;
    for(i=0;i<(int)prime.size()&& prime[i]*prime[i]<=n;i++)
    {
        if(n%prime[i]==0)
        {
            while(n%prime[i]==0)
            {
                factor.push_back(prime[i]);
                n/=prime[i];
            }
        }
    }
    if(n>1)
        factor.push_back(n);
}
int main()
{
    sieve();
    int n,i;
    while(scanf("%d",&n) != EOF)
    {
        primefactorize(n);
        printf("1");
        for(i=0;i<factor.size();i++)
        {
            printf(" x %d",factor[i]);
        }
        printf("\n");
    }
    return 0;
}

