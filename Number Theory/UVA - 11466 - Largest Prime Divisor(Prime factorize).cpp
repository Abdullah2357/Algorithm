#include<bits/stdc++.h>
using namespace std;
vector<int> prime;
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
//vector<long long> factor;
long long primefactorize(long long n)
{
    //factor.clear();
    int i,cnt=0;
    long long LPD;
    for(i=0 ; i < (int)prime.size() && ((long long)prime[i] * (long long)prime[i]) <= (long long)n ; i++)
    {
        if(n%prime[i]==0)
        {
            cnt++;
            while(n%prime[i]==0)
            {
                LPD = prime[i];
                n /= prime[i];
            }
        }
    }
    if(n>1)
        LPD = n,cnt++;
    if(cnt >1)
        return LPD;
    else
        return -1;
}
int main()
{
    long long n,i,s;
    sieve();
    for(i=1 ; ; i++)
    {
        scanf("%lld",&n);
        if(n==0)
            break;
        s = primefactorize(fabs(n));
        printf("%lld\n",s);
    }
    return 0;
}
