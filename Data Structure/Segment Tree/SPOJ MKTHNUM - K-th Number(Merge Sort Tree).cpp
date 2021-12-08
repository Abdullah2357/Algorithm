#include<bits/stdc++.h>
using namespace std;

#define sz 100005


int n, a[sz];

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

int Query(int node, int b, int e, int i,int j,int v)
{
    if(i>e || j<b)
        return 0;
    if(b>=i && e<=j)
    {
        int lo = 0,hi = tree[node].size()-1,mid,res = 0;
        while(lo<=hi)
        {
            mid = (lo+hi)/2;
            if(tree[node][mid]<=v)
            {
                res = mid+1;
                lo = mid+1;
            }
            else
                hi = mid-1;
        }
        return res;
    }

    int mid = (b+e)>>1;
    int lft = node<<1;
    int rgt = lft+1;

    int p1 = Query(lft, b, mid, i, j, v);
    int p2 = Query(rgt, mid+1, e, i, j, v);

    return p1+p2;
}
void Solve(int t)
{
    int i, j, v, q, k;
    cin>>n>>q;

    for(i=1;i<=n;i++)
    {
        cin>>a[i];
    }
    Init(1,1,n);

    while(q--)
    {
        cin>>i>>j>>k;
        int lo = -1e9,hi = 1e9,mid,res = -1;
        while(lo<=hi)
        {
            mid = (lo+hi)>>1;
            int x = Query(1, 1, n, i, j, mid);
            if(x>=k)
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

int main()
{
    int t,T = 1;
//    scanf("%d",&T);
    for(t=1;t<=T;t++)
    {
        Solve(t);
    }
    return 0;
}
