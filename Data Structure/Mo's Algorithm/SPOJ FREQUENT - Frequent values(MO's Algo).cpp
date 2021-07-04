#include<bits/stdc++.h>
using namespace std;

#define sz 200005

int k,a[sz],ans[sz],most_fre=0,n,fre[sz],freoffre[sz];

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
    fre[a[i]]++;
    freoffre[fre[a[i]]]++;
    most_fre = max(most_fre,fre[a[i]]);
}
void Remove(int i)
{
    freoffre[fre[a[i]]]--;
    fre[a[i]]--;
    if(freoffre[most_fre]==0)
        most_fre--;
}
void Clean()
{
    most_fre =0;
    for(int i=0;i<=n+3;i++)
    {
        ans[i] = 0;
        fre[i] = freoffre[i] = 0;
    }
}
void Solve()
{
    int  i, l = 1, r = 0, q,value=1;
    scanf("%d",&q);
    k = sqrt(n);
    map<int,int> m;
    for(i=1;i<=n;i++)
    {
        scanf("%d",&a[i]);
        if(m[a[i]]==0)
            a[i] = m[a[i]] = value++;
        else
            a[i] = m[a[i]];
    }
    for(i=1;i<=q;i++)
    {
        scanf("%d %d",&query[i].l,&query[i].r);
        query[i].index = i;
    }
    sort(query+1,query+q+1);
    for(i=1;i<=q;i++)
    {
        while(r < query[i].r) Add(++r);
        while(l < query[i].l) Remove(l++);
        while(r > query[i].r) Remove(r--);
        while(l > query[i].l) Add(--l);
        ans[query[i].index] = most_fre;
    }
    for(i=1;i<=q;i++)
    {
        printf("%d\n",ans[i]);
    }
    Clean();
}
int main()
{
    while(1)
    {
        scanf("%d",&n);
        if(n==0)
            break;
        Solve();
    }
}
