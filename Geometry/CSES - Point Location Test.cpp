#include<bits/stdc++.h>
#define ll                  long long
#define endl                '\n'
#define sz                  200005
using namespace std;
 
void Solve(int t)
{
    ll x1, x2, x3, y1, y2, y3;
    cin>>x1>>y1>>x2>>y2>>x3>>y3;
    ll a = y1 - y2;
    ll b = -(x1 - x2);
    ll c = x1*(y1 - y2) - y1*(x1 - x2);
    ll L = a*x3 + b*y3 - c;
    if(L==0)
        cout<<"TOUCH\n";
    else if(L > 0)
        cout<<"LEFT\n";
    else
        cout<<"RIGHT\n";
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