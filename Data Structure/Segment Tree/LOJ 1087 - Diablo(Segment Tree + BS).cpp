#include<bits/stdc++.h>
#define ll      long long
using namespace std;


#define sz 200005


int n,a[sz],tree[sz*3];

void Init(int node,int b,int e)
{
    if(b==e)
    {
        tree[node] = 1;
        return ;
    }
    int lft = node*2;
    int rgt = node*2+1;
    int mid = (b+e)/2;

    Init(lft,b,mid);
    Init(rgt,mid+1,e);

    tree[node] = tree[lft] +tree[rgt];
}

int Query(int node,int b,int e,int i,int j)
{
    if(i>e || j<b)
        return 0;
    if(b>=i && e<=j)
        return tree[node];

    int mid = (b+e)/2;
    int sum1 = Query(node*2,b,mid,i,j);
    int sum2 = Query(node*2+1,mid+1,e,i,j);

    return sum1+sum2;
}

void Update(int node,int b,int e,int i,int x)
{
    if(i>e || i< b)
        return ;
    if(b>=i && e<=i)
    {
        tree[node] = x;
        return;
    }

    int mid = (b+e)/2;

    Update(node*2,b,mid,i,x);
    Update(node*2+1,mid+1,e,i,x);

    tree[node] = tree[node*2] + tree[node*2+1];
}



void Solve(int t)
{
    int q, i, k,pos;
    scanf("%d %d",&n,&q);
    for(i=1;i<=n;i++)
    {
        scanf("%d",&a[i]);
    }
    for(i=n+1;i<=n+q;i++)
        a[i] = 0;
    pos = n+1;
    n = n+q;
    Init(1,1,n);
    printf("Case %d:\n",t);
    while(q--)
    {
        char ch;
        cin>>ch;
        scanf("%d",&k);
        if(ch=='a')
        {
            Update(1,1,n,pos,1);
//            cout<<"Pos "<<pos<<endl;
            a[pos++] = k;
        }
        else
        {
            int lo = 1,hi = pos-1,mid,res =-1;
            while(lo<=hi)
            {
                mid = (lo+hi)/2;
                int found = Query(1,1,n,1,mid);
                if(found>=k)
                {
                    res = mid;
                    hi = mid-1;
                }
                else
                    lo = mid+1;
            }

            if(res!=-1)
            {
//                cout<<res<<endl;
                printf("%d\n",a[res]);
                Update(1,1,n,res,0);
            }
            else
            {
                printf("none\n");
            }
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

