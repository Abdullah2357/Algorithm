#include<bits/stdc++.h>
using namespace std;
#include <ext/pb_ds/assoc_container.hpp>
using namespace __gnu_pbds;
template<typename T> using orderset = tree<T,null_type,less<T>,rb_tree_tag,tree_order_statistics_node_update>;

orderset<int> s;

int main()
{
    long long q,i,x,ans;
    cin>>q;
    while(q--)
    {
        char ch;
        cin>>ch>>x;
        if(ch=='I')
            s.insert(x);
        else if(ch=='D' && *s.find(x))
            s.erase(x);
        else if(ch=='K')
        {
            if(x>s.size())
                cout<<"invalid\n";
            else
                cout<<*s.find_by_order(x-1)<<endl;
        }
        else if(ch=='C')
        {
            cout<<s.order_of_key(x)<<endl;
        }
    }
    return 0;
}
