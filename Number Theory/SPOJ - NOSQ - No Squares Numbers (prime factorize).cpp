#include<bits/stdc++.h>
#define ll     long long
using namespace std;

int SF[100005];
void FuN()
{
    for( int i = 2 ; i * i <= 100000 ; i ++ ){
        if( !SF[i] ){
            for( int j = i ; j <= 100000 ; j += i ){
                if( !SF[j] ) SF[j] = i ;
            }
        }
    }
    for( int i = 2 ; i <= 1e5 ; i ++ ) if( !SF[i] ) SF[i] = i ;
}
map<int,int> Factor;
vector<int> sqfree[12];
void GetFactor(int n)
{
    Factor.clear();
    while(n!=1)
    {
        Factor[SF[n]]++;
        n/=SF[n];
    }
}

void Calculation()
{
    for(int i=1;i<=100000;i++)
    {
        GetFactor(i);
        bool fg=1;
        for(auto it:Factor)
        {
            if(it.second>1)
            {
                fg=0;
            }
        }
        if(!fg)
            continue;
        int n = i;
        while(n!=0)
        {
            sqfree[n%10].push_back(i);
            n/=10;
        }
    }
    for(int i=0;i<10;i++)
    {
        sqfree[i].erase(unique(sqfree[i].begin(),sqfree[i].end()),sqfree[i].end());
    }
}
void Solve(int t)
{
    int n,a,b,d,ans=0;
    scanf("%d %d %d",&a,&b,&d);
    ans = upper_bound(sqfree[d].begin(),sqfree[d].end(),b) - lower_bound(sqfree[d].begin(),sqfree[d].end(),a);
    cout<<ans<<endl;
}
int main()
{
    int t,T=1;
    FuN();
    Calculation();
    scanf("%d",&T);
    for(t=1;t<=T;t++)
    {
        Solve(t);
    }
    return 0;
}

