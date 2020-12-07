#include<bits/stdc++.h>
using namespace std;
int main()
{
    long long n,a[100005],q,k,i,ans=0,j;
    cin>>n;
    for(i=0;i<n;i++)
    {
        cin>>a[i];
    }
    cin>>q;
    for(i=0;i<q;i++)
    {
        cin>>k;
        for(j=0;j<n;j++)
        {
            if(a[j] !=0 && k != 0 )
            {
                if(a[j]%k==0 || k%a[j]==0)
                    ans++;
            }
        }
        cout<<"Query "<<i+1<<": "<<ans<<endl;
        ans=0;
    }
    return 0;
}
