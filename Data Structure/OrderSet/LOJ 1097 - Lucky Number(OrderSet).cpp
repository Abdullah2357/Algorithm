#include<bits/stdc++.h>
#define ll      long long
using namespace std;

#include <ext/pb_ds/assoc_container.hpp>
using namespace __gnu_pbds;
template<typename T> using orderset = tree<T,null_type,less<T>,rb_tree_tag,tree_order_statistics_node_update>;

#define sz 200005
orderset<int> s;

int n,a[sz];


void Solve(int t)
{
    int i,j;
    scanf("%d",&n);
    printf("Case %d: %d\n",t,*s.find_by_order(n));

}

void Init()
{
    int mx = 1429435,i,j;
    s.insert(0);
    for(i=1;i<=mx;i+=2)
    {
        s.insert(i);
    }

    for(i=2; ;i++)
    {
        if(i>=s.size())
            break;
        vector<int> v;
        int x = *s.find_by_order(i);
        for(j=x ;j< s.size();j+=x)
        {
            v.push_back(*s.find_by_order(j));
        }
        for(auto it:v)
        {
            s.erase(it);
        }
    }
}
int main()
{
    int t,T=1;
    Init();
    scanf("%d",&T);
    for(t=1;t<=T;t++)
    {
        Solve(t);
    }
    return 0;
}

