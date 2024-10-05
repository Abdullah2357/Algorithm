#include <bits/stdc++.h>
using namespace std;
#define pb      push_back
#define sz      200005
const double eps = 1e-9;
const double PI = acos((double)-1.0);
int sign(double x) { return (x > eps) - (x < -eps); }
struct PT {
    double x, y;
    PT() { x = 0, y = 0; }
    PT(double x, double y) : x(x), y(y) {}
    PT(const PT &p) : x(p.x), y(p.y)    {}
    PT operator + (const PT &a) const { return PT(x + a.x, y + a.y); }
    PT operator - (const PT &a) const { return PT(x - a.x, y - a.y); }
    PT operator * (const double a) const { return PT(x * a, y * a); }
    friend PT operator * (const double &a, const PT &b) { return PT(a * b.x, a * b.y); }
    PT operator / (const double a) const { return PT(x / a, y / a); }
    bool operator == (PT a) const { return sign(a.x - x) == 0 && sign(a.y - y) == 0; }
    bool operator != (PT a) const { return !(*this == a); }
    bool operator < (PT a) const { return sign(a.x - x) == 0 ? y < a.y : x < a.x; }
    bool operator > (PT a) const { return sign(a.x - x) == 0 ? y > a.y : x > a.x; }
    double norm() { return sqrt(x * x + y * y); }
    double norm2() { return x * x + y * y; }
    PT perp() { return PT(-y, x); }
    double arg() { return atan2(y, x); }
    PT truncate(double r) { // returns a vector with norm r and having same direction
        double k = norm();
        if (!sign(k)) return *this;
        r /= k;
        return PT(x * r, y * r);
    }
};

istream &operator >> (istream &in, PT &p) { return in >> p.x >> p.y; }
ostream &operator << (ostream &out, PT &p) { return out << "(" << p.x << "," << p.y << ")"; }
inline double dot(PT a, PT b) { return a.x * b.x + a.y * b.y; }
inline double dist2(PT a, PT b) { return dot(a - b, a - b); }
inline double dist(PT a, PT b) { return sqrt(dot(a - b, a - b)); }
inline double cross(PT a, PT b) { return a.x * b.y - a.y * b.x; }
inline double cross2(PT a, PT b, PT c) { return cross(b - a, c - a); }
inline int orientation(PT a, PT b, PT c) { return sign(cross(b - a, c - a)); }


vector<PT> convex_hull(vector<PT> &points){
    if(points.size() <= 1)
        return points;
    std::sort(points.begin(), points.end());
    vector<PT> up, down, hull;
    for(int i = 0; i< points.size(); i++){
        PT p = points[i];
        while(up.size()>=2 && orientation(up[up.size()-2], up.back() ,p) > 0){
            up.pop_back();
        }
        while(down.size()>=2 && orientation(down[down.size()-2], down.back() ,p) < 0){
            down.pop_back();
        }
        up.push_back(p);
        down.push_back(p);
    }
    
    for(int i = 0; i< down.size(); i++){
        PT p = down[i];
        hull.push_back(p);
    }
    if(hull.size()>1)
        hull.pop_back();
    reverse(up.begin(), up.end());
    up.pop_back();
    for(int i = 0; i<up.size();i++){
        PT p = up[i];
        hull.push_back(p);
    }
    return hull;
}

double dist_from_point_to_line(PT a, PT b, PT c) {
    return fabs(cross(b - a, c - a) / (b - a).norm());
}

int main()
{
    int n, t = 0;
    while(1){
        cin>>n;
        if(n==0)
            break;
        vector<PT> points;
        double x, y;
        for(int i = 0; i < n; i++){
            cin>>x>>y;
            points.push_back({x, y});
        }
        vector<PT> hull = convex_hull(points);
        double ans = 1e9;
        for(int i = 0; i < hull.size(); i++){
            double cur = 0.0;
            for(int j = 0; j < hull.size(); j++){
                cur = max(cur, dist_from_point_to_line(hull[i], hull[(i+1)%hull.size()], hull[j]));
            }
            ans = min(ans, cur);
        }
        cout<<"Case "<<++t<<": ";
        cout<<fixed<<setprecision(2)<<ans<<endl;
    }
    return 0;
}

