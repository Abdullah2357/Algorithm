#include<bits/stdc++.h>
using namespace std;
long long calculate(int n,int m)
{
    long long ans,i,x=1,j=1;
    for(i=(n-m)+1 ; i<= n;i++)
    {
        x *= i;
        x /= j;
        j++;
    }
    return x;
}
int main()
{
    int n,m,i;
    for(i=1; ;i++)
    {
        scanf("  %d  %d",&n,&m);
        if(n==0 && m==0)
            break;
        printf("%d things taken %d at a time is %lld exactly.\n",n,m,calculate(n,m));
    }
    return 0;
}
