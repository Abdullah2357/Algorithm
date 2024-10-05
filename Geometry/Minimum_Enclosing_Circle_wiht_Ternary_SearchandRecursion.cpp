#include<bits/stdc++.h>
using namespace std;
#define pb      push_back
#define sz      200005
const double eps = 1e-9;
const double PI = acos((double)-1.0);
int sign(double x) { return (x > eps) - (x < -eps); }
typedef double T;

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

struct circle{
    PT c;
    double r;
};


circle circle_from(T x1, T y1, T x2, T y2, T x3, T y3){
    T nom = ((x1*x1) - (x3*x3)) * (x1 - x2) + 
            ((y1*y1) - (y3*y3)) * (x1 - x2) +
            ((x2*x2) - (x1*x1)) * (x1 - x3) +
            ((y2*y2) - (y1*y1)) * (x1 - x3);

    T denom = 2.0 * ((y3-y1)*(x1-x2) - (y2-y1)*(x1-x3));
    double f = nom/denom;

    nom = ((x1*x1) - (x3*x3)) * (y1 - y2) + 
          ((y1*y1) - (y3*y3)) * (y1 - y2) +
          ((x2*x2) - (x1*x1)) * (y1 - y3) +
          ((y2*y2) - (y1*y1)) * (y1 - y3);
    denom = 2.0 * ((x3-x1)*(y1-y2) - (x2-x1)*(y1-y3));

    double g = nom / denom;

    double c =  -(x1*x1) -(y1*y1) - (2.0*g*x1) - (2.0*f*y1);

    double r = sqrt(g*g + f*f - c);
    double h = -g;
    double k = -f;

    return {{h, k}, r};
}

bool is_inside(const circle& c, const PT& p)
{
    return dist(c.c, p) <= c.r;
}

circle circle_from(vector<PT> q){
    if(q.size()==0)
        return {{0,0},0};
    else if(q.size()==1)
        return {q[0], 0};
    else if(q.size()==2)
        return {(q[0]+q[1])/2.0, (q[0]-q[1]).norm()/2.0};
    else{
        return circle_from(q[0].x, q[0].y, q[1].x, q[1].y, q[2].x, q[2].y);
    }
}
vector<PT> s;
circle SEC(int i, vector<PT> q)
{
    if(i == s.size() || q.size() == 3){
        return circle_from(q);
    }
    circle D = SEC(i+1, q);
    if(!is_inside(D, s[i])){
        q.push_back(s[i]);
        D = SEC(i+1, q);
    }
    return D;
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
vector<PT> hull;
double ternarysearch(double x){
    double lo = 0.0, hi = 1000.0, m1, m2, res =-1;
    while(hi-lo>eps){
        m1 = lo + (hi - lo)/3;
        m2 = hi - (hi - lo)/3;
        double d1 = 0.0, d2 = 0.0;
        for(int i = 0; i < hull.size(); i++){
            d1 = max(d1, dist(hull[i], {x, m1}));
            d2 = max(d2, dist(hull[i], {x, m2}));
        }

        if(d1 < d2){
            res = d1;
            hi = m2;
        }
        else
            lo = m1;
    }
    return res;
}



int main()
{
    int n, i, j, k;
    cin>>n;
    vector<PT> p;
    for(i=0;i<n;i++)
    {
        double x, y;
        cin>>x>>y;
        p.push_back({x, y});
    }
    hull = convex_hull(p);

    double lo = 0.0, hi = 1000.0, m1, m2, res = -1, resx = -1, resy = -1;
    while(hi-lo>eps)
    {
        m1 = lo + (hi - lo)/3;
        m2 = hi - (hi - lo)/3;
        double d1 = 0.0, d2 = 0.0;
        d1 = ternarysearch(m1);
        d2 = ternarysearch(m2);
        if(d1 < d2){
            res = d1;
            hi = m2;
        }
        else
            lo = m1;
    }
    cout<<fixed<<setprecision(2)<<2.0*res<<endl;
}