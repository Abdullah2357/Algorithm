#include<bits/stdc++.h>
#define ll long long
using namespace std;

#define sz 100005


ll n,a[sz];

struct info{
    ll sum, prop;
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

ll Query(ll node,ll b,int e,ll i,ll j,ll carry = 0)
{
    if(i>e || j<b)
        return 0;
    if(b>=i && e<=j)
        return tree[node].sum + carry*(e-b+1);

    ll mid = (b+e)/2;
    ll sum1 = Query(node*2,b,mid,i,j,carry+tree[node].prop);
    ll sum2 = Query(node*2+1,mid+1,e,i,j,carry+tree[node].prop);

    return sum1+sum2;
}

void Update(ll node,ll b,ll e,ll i,ll j,ll x)
{
    if(i>e || j< b)
        return ;
    if(b>=i && e<=j)
    {
        tree[node].sum += ((e-b+1)*x);
        tree[node].prop += x;
        return;
    }

    ll mid = (b+e)/2;

    Update(node*2,b,mid,i,j,x);
    Update(node*2+1,mid+1,e,i,j,x);

    tree[node].sum = tree[node*2].sum + tree[node*2+1].sum + (e-b+1)*tree[node].prop;
}
void Solve(int t)
{

    ll i,c,id,p,q,v;
    cin>>n>>c;
    for(i=1;i<=n;i++)
        a[i] = 0;
    for(i=1;i<=3*n;i++)
    {
        tree[i].sum = 0;
        tree[i].prop = 0;
    }
    Init(1,1,n);
    while(c--)
    {
        cin>>id;
        if(id==0)
        {
            cin>>p>>q>>v;
            Update(1,1,n,p,q,v);
        }
        else
        {
            cin>>p>>q;
            cout<<Query(1,1,n,p,q,0)<<endl;
        }
    }
}
int main()
{
    int t,T;
    cin>>T;
    for(t=1;t<=T;t++)
    {
        Solve(t);
    }
    return 0;
}
