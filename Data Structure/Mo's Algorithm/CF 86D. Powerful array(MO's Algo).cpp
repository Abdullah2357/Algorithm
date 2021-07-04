#include<bits/stdc++.h>
#define ll long long
using namespace std;

#define sz 1000005

ll k,a[sz],ans[sz],n,res = 0,fre[sz];

struct Query{
    ll index, l, r;
    bool operator < (const Query &other)const{
        ll Block_own = l/k;
        ll Block_other = other.l/k;
        if(Block_other == Block_own)
            return r < other.r;
        return Block_own < Block_other;
    }
}query[sz];

void Add(int i)
{
    fre[a[i]]++;
    ll x = (fre[a[i]]*fre[a[i]]) - ((fre[a[i]]-1)*(fre[a[i]]-1));
    res += (a[i]*x);
}
void Remove(int i)
{
    ll x = (fre[a[i]]*fre[a[i]]) - (fre[a[i]]-1)*(fre[a[i]]-1);
    fre[a[i]]--;
    res -= (a[i]*x);
}
int main()
{
    ll  i, l = 1, r = 0, q,value=1;
    scanf(" %lld %lld",&n,&q);
    k = sqrt(n);
    for(i=1;i<=n;i++)
    {
        scanf("%lld",&a[i]);
    }
    for(i=1;i<=q;i++)
    {
        scanf("%lld %lld",&query[i].l,&query[i].r);
        query[i].index = i;
    }
    sort(query+1,query+q+1);
    for(i=1;i<=q;i++)
    {
        while(r < query[i].r) Add(++r);
        while(l < query[i].l) Remove(l++);
        while(r > query[i].r) Remove(r--);
        while(l > query[i].l) Add(--l);
        ans[query[i].index] = res;
    }
    for(i=1;i<=q;i++)
    {
        printf("%lld\n",ans[i]);
    }
    return 0;
}

