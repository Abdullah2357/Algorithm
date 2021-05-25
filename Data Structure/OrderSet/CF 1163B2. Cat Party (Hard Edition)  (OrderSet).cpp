#include<bits/stdc++.h>
using namespace std;

#include <ext/pb_ds/assoc_container.hpp>
using namespace __gnu_pbds;
template<typename T> using orderset = tree<T,null_type,less<T>,rb_tree_tag,tree_order_statistics_node_update>;
    orderset<int> s[100005];

int main()
{
    long long n,k,i,x=1,a[100005],ans=-1;
    orderset<int> st;
    map<int,int> m;
    cin>>n;
    x=0;
    for(i=1;i<=n;i++)
    {
        cin>>a[i];
        if(*s[m[a[i]]].find(a[i])){
            s[m[a[i]]].erase(a[i]);
            if(s[m[a[i]]].size()==0){
                st.erase(m[a[i]]);
                x--;
            }
        }
        m[a[i]]++;
        if(s[m[a[i]]].size()==0)
            x++;
        s[m[a[i]]].insert(a[i]);
        st.insert(m[a[i]]);
        if(x==2)
        {
            if(s[*st.find_by_order(0)].size()==1 && (*st.find_by_order(0)-1==*st.find_by_order(1) || *st.find_by_order(0)-1==0))
                ans=i;
            if(s[*st.find_by_order(1)].size()==1 && (*st.find_by_order(1)-1==*st.find_by_order(0) || *st.find_by_order(1)-1==0))
                ans=i;
        }
        if(x==1 && (s[*st.find_by_order(0)].size()==1 || *st.find_by_order(0)==1))
            ans=i;
    }
    cout<<ans<<endl;
    return 0;
}
