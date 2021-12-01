#include<bits/stdc++.h>
#define ll long long
using namespace std;

#define sz 100005


int n,a[sz];

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
    int lft = node<<1;
    int rgt = (node<<1)+1;
    int mid = (b+e)>>1;

    Init(lft,b,mid);
    Init(rgt,mid+1,e);

    tree[node].sum = tree[lft].sum +tree[rgt].sum;
}

void push_down(int node,int b,int e)
{
    tree[node].sum = tree[node].sum + tree[node].prop*(e-b+1);
    if(b!=e)
    {
        tree[node<<1].prop += tree[node].prop;
        tree[(node<<1)+1].prop += tree[node].prop;
    }
        tree[node].prop = 0;
}

ll Query(int node,int b,int e,int i,int j)
{
    if(tree[node].prop != 0)
        push_down(node, b, e);
    if(i>e || j<b)
        return 0;


    if(b>=i && e<=j)
        return tree[node].sum;

    int mid = (b+e)>>1;
    ll sum1 = Query(node<<1,b,mid,i,j);
    ll sum2 = Query((node<<1)+1,mid+1,e,i,j);

    return sum1+sum2;
}

void Update(int node,int b,int e,int i,int j,int x)
{
    if(tree[node].prop != 0){
        push_down(node, b, e);
    }
    if(i>e || j< b)
        return ;


    if(b>=i && e<=j)
    {
        tree[node].sum += x*(e-b+1);
        if(b!= e)
        {
            tree[node<<1].prop += x;
            tree[(node<<1)+1].prop += x;
        }
        return;
    }

    int mid = (b+e)>>1;

    Update(node<<1,b,mid,i,j,x);
    Update((node<<1)+1,mid+1,e,i,j,x);

    tree[node].sum = tree[node<<1].sum + tree[(node<<1)+1].sum;
}

void Solve(int t)
{

    int i,q,id,j,v;
    scanf("%d %d",&n,&q);

    for(i=1;i<=n;i++)
        a[i] = 0;
    for(i=1;i<=3*n;i++)
    {
        tree[i].sum = 0;
        tree[i].prop = 0;
    }

    Init(1,1,n);

    printf("Case %d:\n",t);
    while(q--)
    {
        scanf("%d",&id);
        if(id==0)
        {
            scanf("%d %d %d",&i,&j,&v);
            i++,j++;
            Update(1,1,n,i,j,v);
        }
        else
        {
            scanf("%d %d",&i,&j);
            i++,j++;
            ll ans = Query(1,1,n,i,j);
            printf("%lld\n",ans);
        }
    }
}

int main()
{
    int t,T=1;
    scanf("%d",&T);
    for(t=1;t<=T;t++)
    {
        Solve(t);
    }
    return 0;
}
