#include<bits/stdc++.h>
#define ll      long long
using namespace std;

#define sz 100005

ll n,a[sz],tree[sz*4];

void init(int node, int b, int e)
{
    if(b == e)
    {
        tree[node] = a[b];
        return;
    }
    int left = node*2;
    int right = node*2+1;
    int mid = (b+e)/2;
    init(left,b,mid);
    init(right,mid+1,e);

    tree[node] = tree[left] + tree[right];
}

void Update(int node,int b, int e,int pos)
{
    if(pos>e || pos<b)
        return ;
    if(b>=pos && e<=pos)
    {
        tree[node]++;
        return ;
    }
    int mid = (b+e)>>1;
    int lft = node*2;
    int rgt = lft+1;

    Update(lft,b,mid,pos);
    Update(rgt,mid+1,e,pos);

    tree[node] = tree[lft]+tree[rgt];
}

int Query(int node,int b,int e,int i,int j)
{
    if(b>j || e<i)
        return 0;
    if(b>=i && e<=j)
    {
        return tree[node];
    }

    int mid = (b+e)>>1;
    int lft = node*2;
    int rgt = lft+1;

    return Query(lft,b,mid,i,j) + Query(rgt,mid+1,e,i,j);
}

void Solve(int t)
{
    ll i, j, x, y, fg=0, ans = 0,q;
    cin>>q;
    n = 1e5;
//    init(1,1,n);
    while(q--)
    {
        int id,value;
        cin>>id;
        if(id==1) /// Update
        {
            cin>>value;
            Update(1,1,n,value);
        }
        else
        {
            cin>>value;
            ll lo = 1,hi= n,mid,res=-1;
            while(lo<=hi)
            {
                mid = (lo+hi)/2;
                if(Query(1,1,n,1,mid)>=value)
                {
                    res = mid;
                    hi = mid-1;
                }
                else
                    lo = mid+1;
            }
            cout<<res<<endl;
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
