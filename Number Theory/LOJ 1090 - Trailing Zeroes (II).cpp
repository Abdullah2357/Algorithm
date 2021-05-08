#include<bits/stdc++.h>
using namespace std;
pair<int , int> fun(int n)
{
    int i,x=5,ans1=0,ans2=0;
    for(i=1;i <= 10 && x<=n;i++)
    {
        ans1 += (n/x);
        x *= 5;
    }
    x=2;
    for(i=1;i<=20;i++)
    {
        ans2 += (n/x);
        x*=2;
    }
    return make_pair(ans1 , ans2);
}
int main()
{
    int n,r,p,q,t,T;
    scanf("%d",&T);
    for(t=1;t<=T;t++)
    {
        scanf("%d %d %d %d",&n,&r,&p,&q);
        int ans,x=0,y=0,num_2,num_5;
        num_2 = fun(n).second;
        num_5 = fun(n).first;
        num_2 -= fun(r).second;
        num_5 -= fun(r).first;
        num_2 -= fun(n-r).second;
        num_5 -= fun(n-r).first;
        //printf("2: %d 5: %d\n",num_2,num_5);
        while(p%2==0)
        {
            x++;
            p /= 2;
        }
        while(p%5==0)
        {
            y++;
            p/=5;
        }
        //printf("x:%d y:%d\n",x,y);
        num_2 += (x*q);
        num_5 += (y*q);
        ans = min(num_2,num_5);
        printf("Case %d: %d\n",t,ans);
    }
    return 0;
}
