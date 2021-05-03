#include<bits/stdc++.h>
#define ll long long
using namespace std;

#define sz 100005
ll n,a[sz],hashsum[sz],p = 1e9+7;
const int MOD = 1e9+9;

ll BigMOD(ll a,ll n,ll m)
{
    if(n==0)
        return 1%m;
    if(n==1)
        return a%m;
    if(n%2==0)
    {
        ll temp = BigMOD(a,n/2,m);
        return ((temp%m)*(temp%m))%m;
    }
    else
    {
        ll temp = BigMOD(a,n-1,m);
        return ((a%m)*(temp%m))%m;
    }
}

void Compute_Hash()
{
    for(int i=1;i<=n;i++)
    {
        hashsum[i] = (hashsum[i-1] + BigMOD(p,a[i],MOD))%MOD;
//        cout<<hashsum[i]<< ' ';
    }
//    cout<<endl;
}
ll Hashing(ll l,ll r)
{
    return (hashsum[r]-hashsum[l-1]+MOD)%MOD;
}
int main()
{
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
    }
    Compute_Hash();
    int q;
    cin>>q;
    while(q--)
    {
        ll l,r,l2,r2,H1,H2;
        cin>>l>>r>>l2>>r2;
        H1 = Hashing(l,r);
        H2 = Hashing(l2,r2);
        if(r-l!=r2-l2)
        {
            printf("The subarray is not identical.\n");
            continue;
        }
        if(H1==H2)
        {
            printf("The subarray is identical.\n");
        }
        else
            printf("The subarray is not identical.\n");
    }
}
