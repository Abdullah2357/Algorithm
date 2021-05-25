#include<bits/stdc++.h>
using namespace std;
#include <ext/pb_ds/assoc_container.hpp>
using namespace __gnu_pbds;
template<typename T> using orderset = tree<T,null_type,less<T>,rb_tree_tag,tree_order_statistics_node_update>;

orderset<long long> s;

int main()
{
    long long n,t,i,a[200005],ans=0,tot=0;
    cin>>t;
    cout<<'\n';
    while(t--)
    {
        cin>>n;
        tot=0;
        for(i=1;i<=n;i++)
        {
            cin>>a[i];
            tot+=s.order_of_key(a[i]);
            s.insert(a[i]);
        }
        cout<<'\n';
        ans=(n*(n-1))/2 - tot;
        cout<<ans<<endl;
        s.clear();
    }
    return 0;
}
