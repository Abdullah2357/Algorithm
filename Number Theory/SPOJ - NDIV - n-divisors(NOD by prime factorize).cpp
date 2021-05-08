#include<bits/stdc++.h>
using namespace std;
vector<int> prime;
bool mark[100005];
void sieve()
{
    int n = 100000;
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
void primefactorize(int n)
{
    factor.clear();
    int i;
    for(i=0;i<(int)prime.size() && ((long long)prime[i]*(long long)prime[i]) <= (long long)n;i++)
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
    int a,b,n,i,j,ans=0;
    sieve();
    scanf("%d %d %d",&a,&b,&n);
    for(j=a;j<=b;j++)
    {
        map<int , int> m;
        map<int , int> :: iterator it;
        primefactorize(j);
        for(i=0;i<(int)factor.size();i++)
        {
            m[factor[i]]++;
        }
        int NOD = 1;
        for(it = m.begin() ; it != m.end() ; it++)
        {
            NOD *= (it -> second+1);
        }
        if(NOD == n)
            ans++;
    }
    printf("%d\n",ans);
    return 0;
}
