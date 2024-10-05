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

int n = 4;
vector<pt> p;

long long area_of_polygon(vector<pt> p){
    long long area = 0;
    for(int i = 0; i < p.size(); i++){
        area += cross(p[i], p[(i+1)%n]);
    }
    return abs(area)/2;
}

void Solve(int t)
{
    ll ax, ay, bx, by, cx, cy, dx, dy;
    cin>> ax>>ay>> bx>>by>> cx>>cy;
    dx = ax + (cx- bx);
    dy = ay + (cy - by);
    vector<pt> p;
    p.push_back({ax, ay});
    p.push_back({bx, by});
    p.push_back({cx, cy});
    p.push_back({dx, dy});
    cout<<"Case "<<t<<": "<<dx<< ' '<<dy<< ' '<< area_of_polygon(p)<<endl;
}
int main()
{
    int i, tc;
    cin>>tc;
    for(i = 1; i <= tc; i++)
        Solve(i);
}