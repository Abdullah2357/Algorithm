 #include<bits/stdc++.h>
using namespace std;
const int MOD = 1000003;
long long BigMod(long long a,long long n)
{
    if(n == 0) return (1%MOD);
    if(n == 1)
        return a%MOD;
    if(n%2==0)
    {
        long long temp = BigMod(a,n/2);
        return ((temp%MOD) * (temp%MOD))%MOD;
    }
    else
    {
        long long temp = BigMod(a,n-1);
        return ((a%MOD) * (temp%MOD))%MOD;
    }
}
long long fac[1000005];
void factorialF()
{
    int i=1;
    fac[0] = 1;
    for(i=1;i<=1e6;i++)
    {
        fac[i] = ((fac[i-1]%MOD)*(i%MOD))%MOD;
    }
}
long long ncr(int n,int r)
{
    long long ans,a,b,b_inv;
    a = fac[n];
    b = ((fac[n-r]%MOD)* (fac[r]%MOD))%MOD;
    b_inv = BigMod(b,MOD-2);
    ans = ((a%MOD)*(b_inv%MOD))%MOD;
    return ans;
}
int main()
{
    int t,T,a,b,ans;
    factorialF();
    scanf("%d",&T);
    for(t=1;t<=T;t++)
    {
        scanf("%d %d",&a,&b);
        ans = ncr(a,b);
        printf("Case %d: %d\n",t,ans);
    }
    return 0;
}
