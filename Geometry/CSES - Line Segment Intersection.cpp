#include<bits/stdc++.h>
#define ll          long long
#define endl        '\n'
#define MOD         1000000007
#define sz          200005
using namespace std;
 
typedef ll T;
typedef complex<T> PT;
#define x real()
#define y imag()
 
 
ll dot(PT a, PT b)
{
    return a.x*b.x + a.y*b.y;
}
ll cross(PT a, PT b)
{
    return a.x*b.y - a.y*b.x;
}
void Solve(){
    long long x1, x2, x3, x4, y1, y2, y3, y4;
    cin>>x1>>y1>>x2>>y2>>x3>>y3>>x4>>y4;
    PT a{(T)x1,(T) y1}, b{(T)x2,(T) y2}, c{(T)x3, (T)y3}, d{(T)x4, (T)y4};
    if(cross(b-a, d-c) == 0)//parallel
    {
        if(cross(b-a, c-b) != 0){ // Non - Colinear
            cout<<"NO\n";
            return ;
        }
        if(max(a.x, b.x) < min(c.x, d.x) || max(a.y, b.y) < min(c.y, d.y)){
            cout<<"NO\n";
            return ;
        }
        swap(a, c);
        swap(b, d);
        if(max(a.x, b.x) < min(c.x, d.x) || max(a.y, b.y) < min(c.y, d.y)){
            cout<<"NO\n";
            return ;
        }
        cout<<"YES\n";
    }
    else // Non Parallel
    {
        ll c1 = cross(b-a, c-b);
        ll c2 = cross(b-a, d-b);
        if((c1 < 0 && c2<0) || (c1> 0 && c2>0)){
            cout<<"NO\n";
            return ;
        }
        swap(a, c);
        swap(b, d);
         c1 = cross(b-a, c-b);
         c2 = cross(b-a, d-b);
        if((c1 < 0 && c2<0) || (c1> 0 && c2>0)){
            cout<<"NO\n";
            return ;
        }
        cout<<"YES\n";
    }
}
 
int main()
{
    int t;
    cin>>t;
    while(t--)
        Solve();
}