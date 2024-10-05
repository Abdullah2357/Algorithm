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
 
long long area_of_polygon(vector<PT> p){
    ll area = 0;
    for(int i = 0, n = p.size(); i < p.size(); i++){
        area += cross(p[i], p[(i+1)%n]);
    }
    return abs(area);// returns 2*area
}
 
int main()
{
    ll n, i, boundary = 0, inside = 0;
    cin>>n;
    vector<PT> p;
    for(i = 0; i < n; i++)
    {
        ll x1, y1;
        cin>>x1>>y1;
        p.push_back({x1, y1});
    }
    for(i=0;i<n;i++)
    {
        ll j = (i+1)%n;
        PT diff = p[j] - p[i];
        ll g = __gcd(abs(diff.x), abs(diff.y));
        boundary += g;
    }
    ll area = area_of_polygon(p);
    //Pick's Theoream
    // Area = inside + boundary/2 - 1;
    // 2*Area = 2*inside + boundary -2;
    // inside = (2*Area - boundary + 2)/2;
 
    inside = (area - boundary + 2)/2;
    cout<< inside<< ' '<< boundary<<endl;
}