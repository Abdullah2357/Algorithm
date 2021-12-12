#include<bits/stdc++.h>
#define ll      long long
using namespace std;

#define sz 50005

ll n,a[sz];
struct info{
    ll sum,BSS,BPS,maxsum;
}tree[sz*4];


info combine(info left,info right)
{
    info res;
    res.sum=left.sum+right.sum;
    res.BPS=max(left.BPS,left.sum+right.BPS);
    res.BSS=max(right.BSS,right.sum+left.BSS);
    res.maxsum = max({res.BSS, res.BPS, left.maxsum, right.maxsum, left.BSS+right.BPS });
//    res.maxsum=max(max(left.maxsum,right.maxsum),left.BSS+right.BPS);
    return res;
}
info make_data(ll val)
{
    info res;
    res.sum=val;
    res.BPS=val;
    res.BSS=val;
    res.maxsum=val;
    return res;
}

void Init(int node,int b,int e)
{
    if(b==e)
    {
        tree[node] = make_data(a[b]);
        return ;
    }
    int mid = (b+e)>>1;
    int lft = node<<1;
    int rgt = lft+1;

    Init(lft,b,mid);
    Init(rgt,mid+1,e);

    tree[node] = combine(tree[lft],tree[rgt]);
}

info Query(int node,int b,int e,int i,int j)
{
    if(b>j || e<i)
        return make_data(-1e10);

    if(b>=i && e<=j)
    {
        return tree[node];
    }

    int mid = (b+e)>>1;
    int lft = node<<1;
    int rgt = lft+1;

    info p1 = Query(lft,b,mid,i,j);
    info p2 = Query(rgt,mid+1,e,i,j);

    return combine(p1,p2);
}

void update(int node,int b,int e,int i,int v)
{
    if(b>i || e<i)
        return ;

    if(b>=i && e<=i)
    {
        tree[node] = make_data(v);
        return ;
    }

    int mid = (b+e)>>1;
    int lft = node<<1;
    int rgt = lft+1;

    update(lft,b,mid,i,v);
    update(rgt,mid+1,e,i,v);

    tree[node] = combine(tree[lft], tree[rgt]);
}

void Solve(int t)
{
    ll i, j, q,id;
    cin>>n;
    for(i=1;i<=n;i++)
    {
        cin>>a[i];
    }
    cin>>q;

    Init(1,1,n);

    while(q--)
    {
        cin>>id>>i>>j;

        if(id==0)
        {
            update(1,1,n,i,j);
        }
        else
        {
            info ans = Query(1,1,n,i,j);
            cout<<ans.maxsum<<endl;
        }

    }

}

int main()
{
    int t,T=1;
//    scanf("%d",&T);
    for(t=1;t<=T;t++)
    {
        Solve(t);
    }
    return 0;
}


