#include<bits/stdc++.h>
#define ll      long long
using namespace std;


#include <ext/pb_ds/assoc_container.hpp>
using namespace __gnu_pbds;
template<typename T> using orderset = tree<T,null_type,less<T>,rb_tree_tag,tree_order_statistics_node_update>;

#define sz 200005


int n,a[sz];


void Solve(int t)
{
    int q, i, k;
    scanf("%d %d",&n,&q);
    orderset<pair<int,int>> s;
    for(i=1;i<=n;i++)
    {
        scanf("%d",&a[i]);
        s.insert({i,a[i]});
    }
    printf("Case %d:\n",t);
    while(q--)
    {
        char ch;
        cin>>ch;
        scanf("%d",&k);
        if(ch=='a')
        {
            pair<int,int> x = *s.rbegin();
            s.insert({x.first+1,k});
        }
        else
        {
            if(s.size()>=k)
            {
                pair<int,int> x = *s.find_by_order(k-1);
                printf("%d\n",x.second);
                s.erase(x);
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
