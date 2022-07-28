#include<bits/stdc++.h>
#define ll     long long
#define ull unsigned long long
using namespace std;

#define sz 5000005

int phi[sz];
ull phisum[sz];

void Calculate_Phi()
{
    for(int i=2;i<sz;i++)
        phi[i] = i;
    for(int i=2;i<sz;i++)
    {
        if(phi[i]==i)
        {
            for(int j = i;j<sz;j+=i)
                phi[j] -= phi[j]/i;
        }
    }
    for(int i=2;i<sz;i++)
        phisum[i] = phisum[i-1]+((ull)phi[i]*phi[i]);
}

void Solve(int t)
{
    int a,b;
    scanf("%d %d", &a, &b);
    ull ans = phisum[b] - phisum[a-1];
    printf("Case %d: %llu\n", t, ans);

}
int main()
{
    int t,T=1;

    Calculate_Phi();

    scanf("%d",&T);
    for(t=1;t<=T;t++)
    {
        Solve(t);
    }
    return 0;
}

