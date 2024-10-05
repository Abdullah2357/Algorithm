#include<bits/stdc++.h>
#define ll                  long long
#define endl                '\n'
#define sz                  200005
using namespace std;
 
typedef long double T;
 
struct pt {
    long long x, y;
};
long long cross(pt v, pt w) {return v.x*w.y - v.y*w.x;}
 
vector<pt> p;
int n;
 
long long area_of_polygon(vector<pt> p){
    long long area = 0.0;
    for(int i = 0; i < p.size(); i++){
        area += cross(p[i], p[(i+1)%n]);
    }
    return abs(area);
}
int main()
{
    int i, u, v;
    cin>>n;
    for(i = 1; i <= n; i++)
    {
        cin>>u>>v;
        p.push_back({u, v});
    }
    cout<< (ll)area_of_polygon(p)<<endl;
}
