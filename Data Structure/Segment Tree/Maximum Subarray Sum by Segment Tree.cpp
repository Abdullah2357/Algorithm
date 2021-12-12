#include<bits/stdc++.h>
#define ll      long long
using namespace std;

#define sz 50005

ll n,a[sz];
struct info{
    ll sum,suff,pref,maxsum;
}tree[sz*4];


info combine(info left,info right)
{
    info res;
    res.sum=left.sum+right.sum;
    res.pref=max(left.pref,left.sum+right.pref);
    res.suff=max(right.suff,right.sum+left.suff);
    res.maxsum = max({res.suff, res.pref, left.maxsum, right.maxsum, left.suff+right.pref });
//    res.maxsum=max(max(left.maxsum,right.maxsum),left.suff+right.pref);
    return res;
}

info make_data(ll val)
{
    info res;
    res.sum=val;
    res.pref=val;
    res.suff=val;
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
            /// update the value of index i to j
            update(1,1,n,i,j);
        }
        else
        {
            /// find maximum subarray sum in range i to j
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


