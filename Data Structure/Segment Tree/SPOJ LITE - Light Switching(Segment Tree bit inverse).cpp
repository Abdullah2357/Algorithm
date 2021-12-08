#include<bits/stdc++.h>
using namespace std;

#define sz 100005

int n, m, a[sz], tree[sz*3],lazy[sz*3];

void push_down(int node,int b,int e)
{
    tree[node] = (e-b+1) - tree[node];
    if(b!=e)
    {
        lazy[node<<1] ^= 1;
        lazy[(node<<1)+1] ^= 1;
    }
    lazy[node] = 0;
}

void Update(int node,int b,int e,int i,int j)
{
    if(lazy[node]!=0)
        push_down(node, b, e);
    if(i>e || j<b)
        return ;
    if(b>=i && e<=j)
    {
        tree[node] = (e-b+1) - tree[node];
        if(b!=e)
        {
            lazy[node<<1] ^= 1;
            lazy[(node<<1)+1] ^= 1;
        }
        return ;
    }

    int mid = (b+e)>>1;
    int lft = node<<1;
    int rgt = lft+1;

    Update(lft,b,mid,i,j);
    Update(rgt,mid+1,e,i,j);
    tree[node] = tree[lft] + tree[rgt];
}

int Query(int node,int b,int e,int i,int j)
{
    if(lazy[node]!=0)
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


int main()
{
    int i, j, id;
    cin>>n>>m;
    while(m--)
    {
        cin>>id>>i>>j;
        if(id==0)
        {
            Update(1,1,n,i,j);
        }
        else
        {
            cout<<Query(1,1,n,i,j)<<endl;
        }
    }
    return 0;
}
