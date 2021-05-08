#include<bits/stdc++.h>
using namespace std;
vector<int> prime;
bool mark[100000005];
void sieve()
{
    int n = 100000000;
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
int main()
{
    sieve();
    for(int i=0;i<(int)prime.size();i+=100)
    {
        printf("%d\n",prime[i]);
    }
    return 0;
}

