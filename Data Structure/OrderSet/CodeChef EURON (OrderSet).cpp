#include<bits/stdc++.h>
using namespace std;

#include <ext/pb_ds/assoc_container.hpp>
using namespace __gnu_pbds;
template<typename T> using orderset = tree<T,null_type,less<T>,rb_tree_tag,tree_order_statistics_node_update>;

int main()
{
    long long n,k,i,x=1,a[100005],tot=0;
    orderset<pair<int,int>> s;
    map<int,int> m;
    cin>>n;
    for(i=1;i<=n;i++)
    {
        cin>>a[i];
        m[a[i]]++;
        tot+=s.order_of_key(make_pair(a[i],m[a[i]]));
        s.insert(make_pair(a[i],m[a[i]]));
    }
    cout<<(long long)(n*(n-1))/2 - tot<<endl;
    return 0;
}
