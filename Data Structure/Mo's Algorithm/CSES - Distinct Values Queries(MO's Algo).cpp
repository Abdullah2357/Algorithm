
#include<bits/stdc++.h>
using namespace std;

#define sz 100005


int k,a[sz],ans[sz],Distinct=0;
map<int,int> fre;
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

int main()
{
    int n, i, l = 0, r = -1, q;
    cin>>n;
    cin>>q;
    k = sqrt(n);
    for(i=0;i<n;i++)
    {
        cin>>a[i];
    }
    for(i=0;i<q;i++)
    {
        cin>>query[i].l>>query[i].r;
        query[i].l--;
        query[i].r--;
        query[i].index = i;
    }
    sort(query,query+q);
    for(i=0;i<q;i++)
    {
        while(r < query[i].r) Add(++r);
        while(l < query[i].l) Remove(l++);
        while(r > query[i].r) Remove(r--);
        while(l > query[i].l) Add(--l);
        ans[query[i].index] = Distinct;
//        cout<<query[i].l<< ' '<<query[i].r<<endl;
    }
    for(i=0;i<q;i++)
    {
        cout<<ans[i]<<endl;
    }
    return 0;
}
