#include<bits/stdc++.h>
#define ll      long long
using namespace std;

#define sz 300005

int n,a[sz];
vector<int> tree[sz*4];


void Init(int node,int b,int e)
{
    if(b==e)
    {
        tree[node].push_back(a[b]);
        return ;
    }
    int mid = (b+e)>>1;
    int lft = node<<1;
    int rgt = lft+1;

    Init(lft,b,mid);
    Init(rgt,mid+1,e);

    merge(tree[lft].begin(),tree[lft].end(),tree[rgt].begin(),tree[rgt].end(),back_inserter(tree[node]));
}

int Query(int node,int b,int e,int i,int j,int k)
{
    if(b>j || e<i)
        return 0;

    if(b>=i && e<=j)
    {
        ll lo =0,hi=  tree[node].size()-1,mid,res = 0;
        while(lo<=hi)
        {
            mid = (lo+hi)/2;
            if(tree[node][mid]>k)
            {
                res = tree[node].size()-mid;
                hi = mid-1;
            }
            else
                lo = mid+1;
        }
        return res;
    }

    int mid = (b+e)>>1;
    int lft = node<<1;
    int rgt = lft+1;

    int p1 = Query(lft,b,mid,i,j,k);
    int p2 = Query(rgt,mid+1,e,i,j,k);

    return p1+p2;
}


void Solve(int t)
{
    int i, j, q,k ;
    cin>>n;
    for(i=1;i<=n;i++)
    {
        cin>>a[i];
    }
    cin>>q;

    Init(1,1,n);

    while(q--)
    {
        cin>>i>>j>>k;

        int ans = Query(1,1,n,i,j,k);
        cout<<ans<<endl;
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

