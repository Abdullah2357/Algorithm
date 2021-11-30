#include<bits/stdc++.h>
#define ll long long
using namespace std;

#define sz 100005


ll n,a[sz];

struct info{
    ll one,two,zero, prop;
}tree[sz*3];

void Init(int node,int b,int e)
{
    if(b==e)
    {
        tree[node].zero = 1;
        tree[node].one = a[b];
        tree[node].two = a[b];
        return ;
    }
    int lft = node*2;
    int rgt = node*2+1;
    int mid = (b+e)/2;

    Init(lft,b,mid);
    Init(rgt,mid+1,e);

    tree[node].zero = tree[lft].zero +tree[rgt].zero;
    tree[node].one = tree[lft].one +tree[rgt].one;
    tree[node].two = tree[lft].two +tree[rgt].two;
}

ll Query(ll node,ll b,int e,ll i,ll j,ll carry = 0)
{
    if(i>e || j<b)
        return 0;
    if(b>=i && e<=j)
        if(carry%3==0)
            return tree[node].zero;
        else if(carry%3==1)
            return tree[node].two;
        else
            return tree[node].one;

    int mid = (b+e)/2;
    int p1 = Query(node*2,b,mid,i,j,(carry+tree[node].prop)%3);
    int p2 = Query(node*2+1,mid+1,e,i,j,(carry+tree[node].prop)%3);

    return p1+p2;
}
void push_down(int node,int b,int e)
{
    tree[node] = tree[node];
}

void Update(ll node,ll b,ll e,ll i,ll j,ll x)
{
    if(i>e || j< b)
        return ;
    if(b>=i && e<=j)
    {
        int temp = tree[node].two;
        tree[node].two = tree[node].one;
        tree[node].one = tree[node].zero;
        tree[node].zero = temp;
        tree[node].prop ++;
        return;
    }

    int mid = (b+e)/2;
    int lft = node*2;
    int rgt = lft+1;

    Update(lft,b,mid,i,j,x);
    Update(rgt,mid+1,e,i,j,x);

    if(tree[node].prop%3 == 1)
    {
        tree[node].zero = tree[lft].two+tree[rgt].two;
        tree[node].two=tree[lft].one+tree[rgt].one;
        tree[node].one=tree[lft].zero+tree[rgt].zero;
    }
    else if(tree[node].prop%3 == 2)
    {
        tree[node].zero=tree[lft].one+tree[rgt].one;
        tree[node].one=tree[lft].two+tree[rgt].two;
        tree[node].two=tree[lft].zero+tree[rgt].zero;
    }
    else
    {
        tree[node].zero=tree[lft].zero+tree[rgt].zero;
        tree[node].one=tree[lft].one+tree[rgt].one;
        tree[node].two=tree[lft].two+tree[rgt].two;
    }

}
void Clean(int n)
{
    for(int i=1;i<=n;i++)
        a[i] = 0;
    for(int i=1;i<=3*n;i++)
    {
        tree[i].zero = 0;
        tree[i].prop = 0;
        tree[i].one = 0;
        tree[i].zero = 0;
    }

}
void Solve(int t)
{

    int i,q,id,j;
    scanf("%d %d",&n,&q);
    Clean(n);
    Init(1,1,n);
    printf("Case %d:\n",t);
    while(q--)
    {
        scanf("%d %d %d",&id,&i,&j);
        i++;
        j++;
        if(id==0)
        {
            Update(1,1,n,i,j,1);
        }
        else
        {
            int ans = Query(1,1,n,i,j,0);
            printf("%d\n",ans);
        }
    }
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

