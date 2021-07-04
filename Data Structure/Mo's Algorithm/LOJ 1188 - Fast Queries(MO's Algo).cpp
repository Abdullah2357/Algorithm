
#include<bits/stdc++.h>
using namespace std;

#define sz 100005


int k,a[sz],ans[sz],Distinct=0;
int fre[sz];

struct Query{
    int index, l, r;
    bool operator < (const Query &other)const{
        int Block_own = l/k;
        int Block_other = other.l/k;
        if(Block_other == Block_own)
            return r < other.r;
        return Block_own < Block_other;
    }
}query[sz];

void Add(int i)
{
    if(fre[a[i]]==0)
        Distinct++;
    fre[a[i]]++;
}
void Remove(int i)
{
    fre[a[i]]--;
    if(fre[a[i]]==0)
        Distinct--;
}
void Solve(int t)
{
    int n, i, l = 0, r = -1, q;
    scanf("%d %d",&n,&q);
    memset(fre,0,sizeof(fre));
    Distinct = 0;
    k = sqrt(n);
    for(i=0;i<n;i++)
    {
        scanf("%d",&a[i]);
    }
    for(i=0;i<q;i++)
    {
        scanf("%d %d",&query[i].l,&query[i].r);
        query[i].l--;
        query[i].r--;
        query[i].index = i;
    }
    sort(query,query+q);
    for(i=0;i<q;i++)
    {
        while(r < query[i].r) Add(++r);
        while(l > query[i].l) Add(--l);
        while(l < query[i].l) Remove(l++);
        while(r > query[i].r) Remove(r--);
        ans[query[i].index] = Distinct;
    }
    printf("Case %d:\n",t);
    for(i=0;i<q;i++)
    {
        printf("%d\n",ans[i]);
    }
}
int main()
{
    int t,T;
    scanf("%d ",&T);
    for(t=1;t<=T;t++)
    {
        Solve(t);
    }
    return 0;
}

