#include<bits/stdc++.h>
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


vector<PT> convex_hull(vector<PT> points){
    if(points.size() <= 1)
        return points;
    std::sort(points.begin(), points.end());
    vector<PT> up, down, hull;
    for(int i = 0; i< points.size(); i++){
        PT p = points[i];
        while(up.size()>=2 && orientation(up[up.size()-2], up.back() ,p) >= 0){
            up.pop_back();
        }
        while(down.size()>=2 && orientation(down[down.size()-2], down.back() ,p) <= 0){
            down.pop_back();
        }
        up.push_back(p);
        down.push_back(p);
    }
    
    for(auto p:down)
        hull.push_back(p);
    if(hull.size()>1)
        hull.pop_back();
    reverse(up.begin(), up.end());
    up.pop_back();
    for(auto p:up){
        hull.push_back(p);
    }
    return hull;
}


double rad_to_deg(double r) { return (r * 180.0 / PI); }

double get_angle(PT A,PT B,PT C)
{
    double a = (B-C).norm();
    double b = (A-C).norm();
    double c = (A-B).norm();
    return acos((b*b+c*c-a*a)/(2*b*c));
}


void Solve(int t){
    int n, i;
    cin>>n;
    double x, y;
    vector<PT> points;
    for(i = 0; i < n; i++){
        cin>>x>>y;
        points.push_back({x, y});
    }
    if(n<3){
        cout<<"Case "<<t<<": 0\n";
        return ;
    }
    vector<PT> hull = convex_hull(points);

    double res = 180.0;
    n = hull.size();
    for(i = 0; i < hull.size(); i++){
        double angle = get_angle(hull[i], hull[(i+1)%n], hull[(i-1+n)%n]);
        // cout<<angle<<endl;
        res = min(res, rad_to_deg(angle));
    }
    if(res==180.0)
        res = 0.0;
    cout<<"Case "<<t<<": "<<fixed<<setprecision(8)<<res<<endl;

}
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int t, T;
    cin>>T;
    for(t=1;t<=T;t++)
        Solve(t);
    return 0;
}
