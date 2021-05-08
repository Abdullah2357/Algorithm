#include<bits/stdc++.h>
using namespace std;
long long BigMod(long long a,long long n,long long m)
{
    if(n == 0) return (1%m);
    if(n == 1)
        return a%m;
    if(n%2==0)
    {
        long long temp = BigMod(a,n/2,m);
        return ((temp%m) * (temp%m))%m;
    }
    else
    {
        long long temp = BigMod(a,n-1,m);
        return ((a%m) * (temp%m))%m;
    }
}
int main()
{
    long long a,n,m;
    while(scanf("%lld %lld %lld",&a,&n,&m) != EOF)
    {
        //scanf("");
        printf("%lld\n",BigMod(a,n,m));
    }
    return 0;
}
