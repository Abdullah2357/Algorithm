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

PT project_from_point_to_seg(PT a, PT b, PT c) {
    double r = dist2(a, b);
    if (sign(r) == 0) return a;
    r = dot(c - a, b - a) / r;
    if (r < 0) return a;
    if (r > 1) return b;
    return a + (b - a) * r;
}
// minimum distance from point c to segment ab
double dist_from_point_to_seg(PT a, PT b, PT c) {
    return dist(c, project_from_point_to_seg(a, b, c));
}
bool seg_seg_intersection(PT a, PT b, PT c, PT d, PT &ans) {
    double oa = cross2(c, d, a), ob = cross2(c, d, b);
    double oc = cross2(a, b, c), od = cross2(a, b, d);
    if (oa * ob < 0 && oc * od < 0){
        ans = (a * ob - b * oa) / (ob - oa);
        return 1;
    }
    else return 0;
}

bool inDisk(PT a, PT b, PT p) {
    return dot(a-p, b-p) <= 0;
}

bool onSegment(PT a, PT b, PT p) {
    return orientation(a,b,p) == 0 && inDisk(a,b,p);
}

bool above(PT a, PT p) {
    return p.y >= a.y;
}
bool crossesRay(PT a, PT p, PT q) {
    return (above(a,q) - above(a,p)) * orientation(a,p,q) > 0;
}

bool inPolygon(vector<PT> p, PT a, bool strict = true) {
    int numCrossings = 0;
    for (int i = 0, n = p.size(); i < n; i++) {
        if (onSegment(p[i], p[(i+1)%n], a))
            return !strict;
        numCrossings += crossesRay(a, p[i], p[(i+1)%n]);
    }
    return numCrossings & 1; // inside if odd number of crossings
}
bool is_point_on_seg(PT a, PT b, PT p) {
    if (fabs(cross(p - b, a - b)) < eps) {
        if (p.x < min(a.x, b.x) - eps || p.x > max(a.x, b.x) + eps) return false;
        if (p.y < min(a.y, b.y) - eps || p.y > max(a.y, b.y) + eps) return false;
        return true;
    }
    return false;
}

bool is_point_on_polygon(vector<PT> &p, const PT& z) {
    int n = p.size();
    for (int i = 0; i < n; i++) {
        if (is_point_on_seg(p[i], p[(i + 1) % n], z)) return 1;
    }
    return 0;
}
// returns 1e9 if the point is on the polygon 
int winding_number(vector<PT> &p, const PT& z) { // O(n)
    if (is_point_on_polygon(p, z)) return 1e9;
    int n = p.size(), ans = 0;
    for (int i = 0; i < n; ++i) {
        int j = (i + 1) % n;
        bool below = p[i].y < z.y;
        if (below != (p[j].y < z.y)) {
            auto orient = orientation(z, p[j], p[i]);
            if (orient == 0) return 0;
            if (below == (orient > 0)) ans += below ? 1 : -1;
        }
    }
    return ans;
}
// -1 if strictly inside, 0 if on the polygon, 1 if strictly outside
int is_point_in_polygon(vector<PT> &p, const PT& z) { // O(n)
    int k = winding_number(p, z);
    return k == 1e9 ? 0 : k == 0 ? 1 : -1;
}
vector<PT> FuN(vector<PT> v1, vector<PT> v2){
    vector<PT> res;
    for(auto p:v1){
        if(is_point_in_polygon(v2, p)<1){
            res.push_back(p);
        }
    }
    for(auto p:v2){
        if(is_point_in_polygon(v1, p)<1){
            res.push_back(p);
        }
    }

    int n = v1.size();
    int m = v2.size();
    for(int i = 0; i< v1.size(); i++){
        for(int j = 0;j < v2.size(); j++){
            PT out;
            if(seg_seg_intersection(v1[i], v1[(i+1)%n], v2[j], v2[(j+1)%m], out)){
                res.push_back(out);
            }
        }
    }
    return res;
}
vector<PT> convex_hull(vector<PT> points){
    if(points.size() <= 1)
        return points;
    sort(points.begin(), points.end());
    vector<PT> up, down, hull;
    for(auto &p:points){
        while(up.size()>=2 && orientation(up[up.size()-2], up.back() ,p) > 0){
            up.pop_back();
        }
        while(down.size()>=2 && orientation(down[down.size()-2], down.back() ,p) < 0){
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
double area(vector<PT> &p) {
    double ans = 0; int n = p.size();
    for (int i = 0; i < n; i++) ans += cross(p[i], p[(i + 1) % n]);
    return fabs(ans) * 0.5;
}

int main() {
    int n, i, c;
    cin>>n;
    vector<PT> v1, v2;
    double x, y;
    for(i = 1; i <= n; i++){
        cin>>c;
        for(int j = 0; j < c; j++){
            cin>>x>>y;
            v2.push_back({x, y});
        }
        if(i==1)
            v1 = v2;
        else
        {
            v1 = FuN(v1, v2);
            v1 = convex_hull(v1);
        }
        v2.clear();
    }

    double ans = area(v1);

    cout<<fixed<<setprecision(4)<<ans<<endl;

    return 0;
}
