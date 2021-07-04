#include<bits/stdc++.h>
#define ll     long long
using namespace std;

#define sz 200005


void Solve(int n)
{
    ll i, j, fg = 0, x, y, ans = 0,m;
    for(i=1;i<=n;i++)
    {
        x = n-i;
        if((x-1)/2 - i>0)
            ans += max((x-1)/2 -i,0LL);
        else
            break;
    }
    cout<<ans<<endl;
}
int main()
{
    int t=1,T=1;
//    scanf("%d",&T);
    while(1)
    {
        int n;
        cin>>n;
        if(n==0)
            break;
        printf("Case %d: ",t++);
        Solve(n);
    }
    return 0;
}

