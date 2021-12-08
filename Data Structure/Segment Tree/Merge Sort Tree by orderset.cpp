#include<bits/stdc++.h>
using namespace std;

#define sz 100005



/**     Order Set       **/
#include <ext/pb_ds/assoc_container.hpp>
using namespace __gnu_pbds;
template<typename T> using orderset = tree<T,null_type,less<T>,rb_tree_tag,tree_order_statistics_node_update>;

int n, a[sz];

orderset<pair<int,int>> s[400005];
map<int,int> m;

void Union(int node,int lft,int rgt)
{
    for(auto it:s[lft])
    {
        s[node].insert(it);
    }
    for(auto it:s[rgt])
    {
        s[node].insert(it);
    }
}
void Init(int node,int b,int e)
{
    if(b==e)
    {
        s[node].insert(make_pair(a[b],m[a[b]]++));
        return ;
    }
    int mid = (b+e)>>1;
    int lft = node<<1;
    int rgt = lft+1;

    Init(lft,b,mid);
    Init(rgt,mid+1,e);

    Union(node,lft,rgt);
//    merge(s[lft].begin(),s[lft].end(),s[rgt].begin(),s[rgt].end(),back_inserter(s[node]));
}

int Query(int node, int b, int e, int i,int j,int v)
{
    if(i>e || j<b)
        return 0;
    if(b>=i && e<=j)
    {
        int l = s[node].order_of_key({v+1,0});
        return l;
    }

    int mid = (b+e)>>1;
    int lft = node<<1;
    int rgt = lft+1;

    int p1 = Query(lft, b, mid, i, j, v);
    int p2 = Query(rgt, mid+1, e, i, j, v);

    return p1+p2;
}
void Solve(int t)
{
    int i, j, v, q, k;
    cin>>n>>q;

    for(i=1;i<=n;i++)
    {
        cin>>a[i];
    }
    Init(1,1,n);

    while(q--)
    {
        cin>>i>>j>>k;
        int res = Query(1,1,n,i,j,k);
        cout<<res<<endl;
    }
}

int main()
{
    int t,T = 1;
//    scanf("%d",&T);
    for(t=1;t<=T;t++)
    {
        Solve(t);
    }
    return 0;
}
