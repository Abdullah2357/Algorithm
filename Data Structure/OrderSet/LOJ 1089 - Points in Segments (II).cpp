#include<bits/stdc++.h>
using namespace std;

/**     Order Set       **/
#include <ext/pb_ds/assoc_container.hpp>
using namespace __gnu_pbds;
template<typename T> using orderset = tree<T,null_type,less<T>,rb_tree_tag,tree_order_statistics_node_update>;


void Solve(int t)
{
    int n, q, ans = 0, i,a,b;

    orderset<pair<int,int>> st,en;
    map<int,int> m,m2;

    scanf("%d %d",&n,&q);
    for( i = 0; i < n ;i++)
    {
        scanf("%d %d",&a,&b);
        st.insert({a,m[a]++});
        en.insert({b+1,m2[b]++});
    }
    printf("Case %d:\n",t);

    while(q--)
    {
        int point;
        scanf("%d", &point);

        ans = st.order_of_key({point+1,0}) - en.order_of_key({point+1,0});
        printf("%d\n", ans);

    }

}


int main()
{
    int t,T = 1;
    scanf("%d",&T);
    for(t=1;t<=T;t++)
    {
        Solve(t);
    }
    return 0;
}

