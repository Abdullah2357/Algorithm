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

int main()
{
    int n, i, j, k;
    int N,L;
    cin>>N>>L;
    cin>>n;
    vector<PT> p;
    for(i=0;i<n;i++)
    {
        double x, y;
        cin>>x>>y;
        p.push_back({x, y});
    }
    random_shuffle(p.begin(), p.end());
    s = p;
    vector<PT> q;
    circle C =  SEC(0, q);
    // cout<<C.c<< ' '<<C.r<<endl;
    cout<<fixed<<setprecision(10)<<2.0*C.r/L * tan(PI/N)<<endl;
}