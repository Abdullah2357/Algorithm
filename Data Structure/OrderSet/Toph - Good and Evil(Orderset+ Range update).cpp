#include<bits/stdc++.h>
#define ll     long long
using namespace std;

/**     Order Set       **/
#include <ext/pb_ds/assoc_container.hpp>
using namespace __gnu_pbds;
template<typename T> using orderset = tree<T,null_type,less<T>,rb_tree_tag,tree_order_statistics_node_update>;

#define sz 200005

void Solve(int t)
{
    ll q,l,r,x,type,cnt = 0;
    cin>>q;
    map<ll,ll> m,m2,m3,m4;
    orderset<pair<ll,ll>> v,v2,v3,v4;
    while(q--)
    {
        cin>>type;
        if(type==1)
        {
            cin>>l>>r;
            ll mid = (l+r)/2;
            v.insert({l,m[l]++});
            v2.insert({mid+1,m2[mid+1]++});
            v3.insert({mid+1,m3[mid+1]++});
            v4.insert({r+1,m4[r+1]++});
        }
        else if(type==2)
        {
            cin>>l>>r;
            ll mid = (l+r)/2;
            v2.insert({l,m2[l]++});
            v.insert({mid+1,m[mid+1]++});
            v4.insert({mid+1,m4[mid+1]++});
            v3.insert({r+1,m3[r+1]++});
        }
        else
        {
            cin>>x;
            ll res = 0, res2 = 0;

            ///find ans for good
            res = v.order_of_key({x+1,0});
            res2 = v2.order_of_key({x+1,0});
            cout<<res-res2<<' ';

            ///find ans for bad
            res = v3.order_of_key({x+1,0});
            res2 = v4.order_of_key({x+1,0});
            cout<<res-res2<<endl;

        }
    }
}
int main()
{
    int t,T=1;
//    scanf("%d",&T);
    for(t=1;t<=T;t++)
    {
        Solve(t);
    }
    return 0;
}
