#include<bits/stdc++.h>
#define ll long long
using namespace std;


vector<ll>Prime;
bool mark[10000003];
void sieve(ll n){
    ll i,j;
    mark[1]=1;
    for(i=4; i<=n; i+=2)
        mark[i]=1;
    Prime.push_back(2);
    for(i=3; i<=n; i+=2)
    {
        if(!mark[i])
        {
            Prime.push_back(i);
            if(i*i<=n)
            {
                for(j=i*i; j<=n; j+=(i*2))
                    mark[j]=1;
            }
        }
    }
}
int main()
{
    sieve(10000);
    cout<<mark[9]<<endl;
}
