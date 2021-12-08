#include<bits/stdc++.h>
using namespace std;

#define sz 100005


int n,a[sz],tree[sz*3];

void Init(int node,int b,int e)
{
    if(b==e)
    {
        tree[node] = a[b];
        return ;
    }
    int lft = node*2;
    int rgt = node*2+1;
    int mid = (b+e)/2;

    Init(lft,b,mid);
    Init(rgt,mid+1,e);

    tree[node] = tree[lft] +tree[rgt];
}

int Query(int node,int b,int e,int i,int j)
{
    if(i>e || j<b)
        return 0;
    if(b>=i && e<=j)
        return tree[node];

    int mid = (b+e)/2;
    int sum1 = Query(node*2,b,mid,i,j);
    int sum2 = Query(node*2+1,mid+1,e,i,j);

    return sum1+sum2;
}

void Update(int node,int b,int e,int i,int x)
{
    if(i>e || i< b)
        return ;
    if(b>=i && e<=i)
    {
        tree[node] = x;
        return;
    }

    int mid = (b+e)/2;

    Update(node*2,b,mid,i,x);
    Update(node*2+1,mid+1,e,i,x);

    tree[node] = tree[node*2] + tree[node*2+1];
}
int main()
{
    int i;
    cin>>n;
    for(i=1;i<=n;i++)
    {
        cin>>a[i];
    }
    Init(1,1,n);
    cout<<Query(1,1,n,2,5)<<endl;
    Update(1,1,n,2,5);
    cout<<Query(1,1,n,2,4)<<endl;
    return 0;
}
