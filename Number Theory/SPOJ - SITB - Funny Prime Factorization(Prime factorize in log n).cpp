#include<bits/stdc++.h>
using namespace std;
int SF[10000005];
void fun()
{
    int n = 10000000,i,j;
    ///memset(SF,0,sizeof(SF));
    for(i=2;i*i<=n;i++)
    {
        if(SF[i]==0)
        {
            for(j=i;j<=n;j+=i)
            {
                if(SF[j]==0)
                    SF[j] = i;
            }
        }
    }
    for(i=2;i<=n;i++)
    {
        if(SF[i]==0)
            SF[i] = i;
    }
}
vector<int> factor;
void getfactor(int n)
{
    factor.clear();
    while(n != 1)
    {
        factor.push_back(SF[n]);
        n /= SF[n];
    }
}
int main()
{
    fun();
    int n,i;
    while(scanf("%d",&n) != EOF)
    {
        getfactor(n);
        printf("%d = %d",n,factor[0]);
        for(i=1;i<(int)factor.size();i++)
        {
            printf(" x %d",factor[i]);
        }
        printf("\n");
    }
    return  0;
}

