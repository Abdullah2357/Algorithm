#include<bits/stdc++.h>
using namespace std;

#include <ext/pb_ds/assoc_container.hpp>
using namespace __gnu_pbds;
template<typename T> using orderset = tree<T,null_type,less<T>,rb_tree_tag,tree_order_statistics_node_update>;

orderset<pair<int,int>> s;
int a[200005];

int main()
{
    int n, q, i, l, r, k, x = 1;
    scanf("%d %d",&n,&q);
    for(i=1;i<=n;i++)
    {
        scanf("%d",&a[i]);
        s.insert(make_pair(a[i],i));
    }
    while(q--)
    {
        char ch;
        cin>>ch;
        if(ch=='!')
        {
            scanf("%d %d",&k,&x);
            s.erase({a[k],k});
            a[k] = x;
            s.insert(make_pair(a[k],k));
        }
        else
        {
            scanf("%d %d",&l,&r);
            int ans = s.order_of_key({r,200005}) - s.order_of_key({l,0});
            printf("%d\n",ans);
        }
    }
}
