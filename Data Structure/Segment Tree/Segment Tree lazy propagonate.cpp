#include<bits/stdc++.h>
using namespace std;

#define sz 100005


int n,a[sz];

struct info{
    int sum,int prop;
}tree[sz*3];

void Init(int node,int b,int e)
{
    if(b==e)
    {
        tree[node].sum = a[b];
        return ;
    }
    int lft = node*2;
    int rgt = node*2+1;
    int mid = (b+e)/2;

    Init(lft,b,mid);
    Init(rgt,mid+1,e);

    tree[node].sum = tree[lft].sum +tree[rgt].sum;
}

int Query(int node,int b,int e,int i,int j,int carry = 0)
{
    if(i>e || j<b)
        return 0;
    if(b>=i && e<=j)
        return tree[node].sum + carry*(e-b+1);

    int mid = (b+e)/2;
    int sum1 = Query(node*2,b,mid,i,j,carry+tree[node].prop);
    int sum2 = Query(node*2+1,mid+1,e,i,j,carry+tree[node].prop);

    return sum1+sum2;
}

void Update(int node,int b,int e,int i,int j,int x)
{
    if(i>e || j< b)
        return ;
    if(b>=i && e<=j)
    {
        tree[node].sum += ((e-b+1)*x);
        tree[node].prop += x;
        return;
    }

    int mid = (b+e)/2;

    Update(node*2,b,mid,i,j,x);
    Update(node*2+1,mid+1,e,i,j,x);

    tree[node].sum = tree[node*2].sum + tree[node*2+1].sum + (e-b+1)*tree[node].prop;
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
