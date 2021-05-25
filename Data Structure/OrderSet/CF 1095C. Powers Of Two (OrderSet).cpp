#include<bits/stdc++.h>
using namespace std;

#include <ext/pb_ds/assoc_container.hpp>
using namespace __gnu_pbds;
template<typename T> using orderset = tree<T,null_type,less<T>,rb_tree_tag,tree_order_statistics_node_update>;

int main()
{
    int n,k,i,x=1;
    orderset<int> s;
    cin>>n>>k;
    priority_queue<int> pq;
    for(i=0;i<=30;i++)
    {
        s.insert(x);
        x*=2;
    }
    while(n>0)
    {
        x = s.order_of_key(n);
        if(*s.find_by_order(x)<=n)
        {
            pq.push(*s.find_by_order(x));
            n-=*s.find_by_order(x);
        }
        else
        {
            pq.push(*s.find_by_order(x-1));
            n-=*s.find_by_order(x-1);
        }
    }
    while(k>pq.size())
    {
        int x= pq.top();
        pq.pop();
        if(x==1)
            break;
        pq.push(x/2);
        pq.push(x/2);
    }
    if(pq.size()==k)
    {
        cout<<"YES\n";
        while(!pq.empty()){
            cout<<pq.top()<< ' ';
            pq.pop();
        }
        cout<<endl;
    }
    else
        cout<<"NO\n";
    return 0;
}
