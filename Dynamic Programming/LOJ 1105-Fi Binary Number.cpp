#include<bits/stdc++.h>
#define ll      long long
using namespace std;

#define sz 3005

ll n;
ll fib[50],fibsum[50];

void Fibonacci()
{
    fib[0] = 0;
    fib[1] = 1;
    fibsum[1] = fib[1];
    for(int i=2; ;i++)
    {
        fib[i] = fib[i-1]+fib[i-2];
        fibsum[i] = fibsum[i-1]+fib[i];
        if(fibsum[i]>1e9)
            break;
    }
}

pair<int,int> Find(int n)
{
    pair<int,int> ret;
    for(int i=1;i<=50;i++)
    {
        if(fibsum[i]>=n)
        {
            int digit = i;
            int kth = n-fibsum[i-1];
            ret = {digit,kth};
            break;
        }
    }
    return ret;
}


void FuN(int digit,int kth)
{
    if(digit<=0)
        return ;
    if(kth==1)
    {
        printf("1");
        for(int i=2;i<=digit;i++)
            printf("0");
        printf("\n");
        return ;
    }
    printf("1");
    pair<int,int> p = Find(kth-1);
    for(int i=1;i<=digit-1-p.first;i++)
        printf("0");
    FuN(p.first,p.second);
}

void Solve(int t)
{
    int i, j;
    scanf("%lld",&n);
    pair<int,int> p = Find(n);

    printf("Case %d: ",t);
    FuN(p.first,p.second);
}

int main()
{
    int t,T=1;
    Fibonacci();
    scanf("%d",&T);
    for(t=1;t<=T;t++)
    {
        Solve(t);
    }
    return 0;
}



