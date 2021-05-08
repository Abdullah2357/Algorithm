#include<bits/stdc++.h>
using namespace std;
vector<int> prime;
bool mark[1000005];
void sieve()
{
    int n = 1000000;
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
vector<int> factor;
void primefactorize(long long n)
{
    factor.clear();
    int i;
    for(i=0;i<(int)prime.size() && (long long)prime[i]*prime[i] <= (long long)n;i++)
    {
        if(n%prime[i]==0)
        {
            while(n%prime[i]==0)
            {
                factor.push_back(prime[i]);
                n /= prime[i];
            }
        }
    }
    if(n>1)
        factor.push_back(n);
}
int main()
{
    long long n,i,j,T,t;
    sieve();
    scanf("%lld",&T);
    for(t=1;t<=T;t++)
    {
        scanf("%lld",&n);
        map<long long , long long> m;
        map<long long , long long> :: iterator it;
        primefactorize(n);
        for(i=0;i<(int)factor.size();i++)
        {
            m[factor[i]]++;
        }
        long long NOD=1;
        for(it = m.begin() ; it != m.end() ; it++)
        {
            NOD *= (it -> second+1);
        }
        printf("Case %lld: %lld\n",t,NOD-1);
    }
    return 0;
}
