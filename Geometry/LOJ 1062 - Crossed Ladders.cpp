#include<bits/stdc++.h>
#define ll                  long long
#define endl                '\n'
#define MOD                 1000000007
#define sz                  200005
using namespace std;


void Solve(int t)
{
    double x, y, h;
    cin>>x>>y>>h;

    double lo  = 0.0, hi = min(x, y), mid, res;
    while(hi - lo >0.00000001)
    {
        mid = (lo+hi)/2.0;
        double h1 = sqrt(y*y - mid*mid);
        double h2 = sqrt(x*x - mid*mid);
        double hh = (h1*h2)/(h1+h2);
        if(hh<=h)
        {
            res = mid;
            hi = mid;
        }
        else
            lo = mid;
    }
    cout<<"Case "<<t<<": "<<fixed<<setprecision(8)<<res<<endl;
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int t, T = 1;
    cin>>T;
    for(t = 1; t <= T; t++)
        Solve(t);
    return 0;
}
