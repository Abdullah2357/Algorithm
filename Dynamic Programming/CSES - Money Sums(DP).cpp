#include<bits/stdc++.h>
#define ll      long long
using namespace std;

#define sz 200005

int n,a[sz],vis[102][1000002];

set<int> s;
void FuN(int pos,int x)
{
    s.insert(x);
    if(pos>n)
        return ;
    if(vis[pos][x])
        return ;

    FuN(pos+1,a[pos]);
    FuN(pos+1,x+a[pos]);
    FuN(pos+1,x);
    vis[pos][x] = 1;
}

int main()
{
    scanf("%d",&n);
    for(int i=1;i<=n;i++)
    {
        scanf("%d",&a[i]);
    }

    FuN(1,0);
    s.erase(0);

    printf("%d\n",s.size());
    for(auto it:s)
        printf("%d ",it);
    printf("\n");
}

