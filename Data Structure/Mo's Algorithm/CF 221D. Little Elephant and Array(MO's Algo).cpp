#include<bits/stdc++.h>
#define ll long long
using namespace std;

#define sz 100005

int BlockSZ,a[sz],ans[sz],n,cnt = 0;
unordered_map<int,int> fre;

struct Query{
    int index, l, r;
    bool operator < (const Query &other)const{
        int Block_own = l/BlockSZ;
        int Block_other = other.l/BlockSZ;
        if(Block_other == Block_own)
            return r < other.r;
        return Block_own < Block_other;
    }
}query[sz];

void Add(int i)
{
    if(fre[a[i]]==a[i])
        cnt--;
    fre[a[i]]++;
    if(a[i]==fre[a[i]])
        cnt++;
}
void Remove(int i)
{
    if(a[i]==fre[a[i]])
        cnt--;
    fre[a[i]]--;
    if(fre[a[i]]==a[i])
        cnt++;
}
int main()
{
    int  i, l = 1, r = 0, q;
    scanf("%d %d",&n,&q);
    BlockSZ = sqrt(n);
    for(i=1;i<=n;i++)
    {
        scanf("%d",&a[i]);
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
        ans[query[i].index] = cnt;
    }
    for(i=1;i<=q;i++)
    {
        printf("%d\n",ans[i]);
    }
    return 0;
}

