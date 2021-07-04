#include<bits/stdc++.h>
using namespace std;

int a[1005],ans[305];

int ok(int n,int k,int value)
{
    int i,cnt=1, sum = 0;
    for(i=1;i<=n;i++)
    {
        if(a[i]>value)
            return 0;
        if(sum+a[i]<=value)
            sum+=a[i];
        else
        {
            cnt++;
            sum = a[i];
        }
    }
    if(cnt<=k)
        return 1;
    return 0;
}
void FindAns(int n,int k,int value)
{
    int sum = 0,cnt = 0;
    for(int i=1;i<=n;i++)
    {
        if(sum+a[i]<=value)
            sum += a[i];
        else
        {
            printf("%d\n",sum);
            cnt++;
            sum = a[i];
        }
        if(n-i+1==k-cnt)
        {
            printf("%d\n",sum);
            for(int j=i+1;j<=n;j++)
            {
                printf("%d\n",a[j]);
            }
            return;
        }
    }
}
int main()
{
    int t,T,i,n,k;
    scanf("%d",&T);
    for(t=1;t<=T;t++)
    {
        scanf("%d %d",&n,&k);
        n++,k++;
        for(i=1;i<=n;i++)
        {
            scanf("%d",&a[i]);
        }
        vector<int> v;
        int lo=0,hi=1e7,mid,res=-1;
        while(lo<=hi)
        {
            mid = (lo+hi)/2;
            if(ok(n,k,mid))
            {
                res=mid;
                hi=mid-1;
            }
            else
                lo=mid+1;
        }
        printf("Case %d: %d\n",t,res);
        FindAns(n, k, res);
    }
    return 0;
}

