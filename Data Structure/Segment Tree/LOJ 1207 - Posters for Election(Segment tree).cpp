#include<bits/stdc++.h>
using namespace std;

#define sz 200005

int n, m, a[sz], tree[sz*4],lazy[sz*4];

void push_down(int node,int b,int e)
{
    tree[node] = lazy[node]*(e-b+1);
    if(b!=e)
    {
        lazy[node<<1] = lazy[node];
        lazy[(node<<1)+1] = lazy[node];
    }
    lazy[node] = -1;
}

void Update(int node,int b,int e,int i,int j,int v)
{
    if(lazy[node]!=-1)
        push_down(node, b, e);
    if(i>e || j<b)
        return ;
    if(b>=i && e<=j)
    {
        tree[node] = (e-b+1) *v;
        if(b!=e)
        {
            lazy[node<<1] = v;
            lazy[(node<<1)+1] = v;
        }
        return ;
    }

    int mid = (b+e)>>1;
    int lft = node<<1;
    int rgt = lft+1;

    Update(lft,b,mid,i,j,v);
    Update(rgt,mid+1,e,i,j,v);
    tree[node] = tree[lft] + tree[rgt];
}

int Query(int node,int b,int e,int i,int j)
{
    if(lazy[node]!=-1)
        push_down(node, b, e);
    if(i>e || j<b)
        return 0;
    if(b>=i && e<=j)
    {
        return tree[node];
    }

    int mid = (b+e)>>1;
    int lft = node<<1;
    int rgt = lft+1;

    int p1 = Query(lft,b,mid,i,j);
    int p2 = Query(rgt,mid+1,e,i,j);

    return p1+p2;
}

void Solve(int t)
{
    int i, j, l,r;
    scanf("%d",&n);
    for(i=1;i<=8*n;i++)
    {
        tree[i] = 0;
        lazy[i] = -1;
    }
    for(i=1;i<=n;i++)
    {
        scanf("%d %d",&l,&r);
        Update(1,1,2*n,l,r,i);
    }
    set<int> s;
    for(i=1;i<=2*n;i++)
    {
        int x = Query(1,1,2*n,i,i);
        s.insert(x);
//        cout<<x<< ' ';
    }
//    cout<<endl;
    s.erase(0);
    printf("Case %d: %d\n",t,s.size());

}
int main()
{
    int t,T;
    scanf("%d",&T);
    for(t=1;t<=T;t++)
    {
        Solve(t);
    }
    return 0;
}
