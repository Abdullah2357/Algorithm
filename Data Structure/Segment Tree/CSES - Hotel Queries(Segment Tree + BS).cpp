#include<bits/stdc++.h>
#define ll int
using namespace std;
#define sz 200005
int a[sz],tree[3*sz];

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
    tree[node] = max(tree[left], tree[right]);
}

int Query(int node, int b, int e, int i, int j)
{
    if(i > e || j < b)
        return 0;
    if(b >= i && e <= j)
        return tree[node];
    int left = node*2;
    int right = node*2+1;
    int mid = (b+e)/2;
    int p1 = Query(left, b, mid, i, j);
    int p2 = Query(right, mid + 1, e, i, j);
    return max(p1, p2);
}
void Update(int node,int b,int e,int i,int newvalue)
{
    if(i>e || i<b)
        return ;
    if(b>=i && e<=i)
    {
        tree[node] = newvalue;
        return ;
    }
    int left = node*2;
    int right = node*2+1;
    int mid = (b+e)/2;
    Update(left,b,mid,i,newvalue);
    Update(right,mid+1,e,i,newvalue);
    tree[node] = max(tree[left] , tree[right]);
}

void Solve(int t)
{
    int ans = 0,fg = 0,x,y,i,j,k,q,n;
    scanf("%d %d",&n,&q);
    for(i=1;i<=n;i++)
    {
        scanf("%d",&a[i]);
    }
    init(1,1,n);
    while(q--)
    {
        scanf("%d",&x);
        int lo=1,hi=n,mid,res=0;
        while(lo<=hi)
        {
            mid = (lo+hi)/2;
            if(Query(1, 1, n, 1, mid)>=x)
            {
                res = mid;
                hi = mid-1;
            }
            else
                lo = mid+1;
        }
        if(res!=0){
            a[res]-=x;
            Update(1, 1, n, res, a[res]);
        }
        printf("%d ",res);
    }
    printf("\n");
}

int main()
{
    int t,T;
    T=1;
//    cin>>T;
    for(t=1;t<=T;t++)
    {
        Solve(t);
    }
    return 0;
}

