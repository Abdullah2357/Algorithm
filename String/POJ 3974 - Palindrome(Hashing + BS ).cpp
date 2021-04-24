#include<iostream>
#include<string.h>
#include<cstdio>

#define ull unsigned long long

#define sz 1000005

ull hashsum[sz],p[sz],hashsum2[sz],n;

ull Hashing(ull l,ull r)
{
    return (hashsum[r]-hashsum[l-1]);
}
ull Hashing2(ull l,ull r)
{
    return (hashsum2[r]-hashsum2[l+1]);
}

bool possible(ull value)
{
    ull l,r;
    ull h1,h2;
    for(l=1;l<=n;l++)
    {
        r = l+value-1;
        if(r>n)
            break;
        h1 = (Hashing(l,r)*p[sz-5-l]);
        h2 = (Hashing2(r,l)*p[sz-5-(n-r+1)]);
        if(h1==h2)
            return 1;
    }
    return 0;
}
char s[sz];

int main()
{
    int t=1,T,i;
    p[0]=1;
    for(i=1;i<=sz-2;i++)
    {
        p[i] = (p[i-1]*269);
    }
    scanf("%s",s);
    while(s[0] !='E'){
        n = strlen(s);
        ull lo = 1,hi = n/2,mid,res=0,ans;
        for(i=1;i<=n;i++)
        {
            hashsum[i] = (hashsum[i-1]+((ull)(s[i-1]))*p[i]);
        }
        hashsum2[n+1] = 0;
        for(i=n;i>=1;i--)
        {
            hashsum2[i] = (hashsum2[i+1]+((ull)(s[i-1]))*p[n-i+1]);
        }
        while(lo<=hi)
        {
            mid = (lo+hi)/2;
            if(possible(mid*2))
            {
                res = mid*2;
                lo = mid+1;
            }
            else
                hi = mid-1;
        }
        ans = res;
        lo = 1,hi = n/2+1;
        res = 0;
        while(lo<=hi)
        {
            mid = (lo+hi)/2;
            if(possible(mid*2-1))
            {
                res = mid*2-1;
                lo = mid+1;
            }
            else
                hi = mid-1;
        }
        ans = std::max(ans,res);
        printf("Case %d: %llu\n",t++,ans);
        scanf("%s",s);
    }
    return 0;
}

