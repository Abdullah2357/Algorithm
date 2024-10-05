#include<bits/stdc++.h>
#define ll                  long long
#define endl                '\n'
#define F                   first
#define S                   second
#define all(a)              (a.begin()),(a.end())
#define UNIQUE(X)           (X).erase(unique(all(X)),(X).end())
#define SORT_UNIQUE(c)      (sort(c.begin(),c.end()), c.resize(distance(c.begin(),unique(c.begin(),c.end()))))
#define ms(a,b)             memset(a, b, sizeof(a))
#define eps                 1e-9
#define MOD                 1000000007
#define sz                  200005
using namespace std;
 
typedef double T;
 
struct pt {
    T x,y;
    pt operator+(pt p) {return {x+p.x, y+p.y};}
    pt operator-(pt p) {return {x-p.x, y-p.y};}
    pt operator*(T d) {return {x*d, y*d};}
    pt operator/(T d) {return {x/d, y/d};} // only for floatingpoint
};
template <typename T> int sgn(T x) {
    return (T(0) < x) - (x < T(0));
}
 
inline double dot(pt a, pt b) { return a.x * b.x + a.y * b.y; }
inline double dist2(pt a, pt b) { return dot(a - b, a - b); }
inline double dist(pt a, pt b) { return sqrt(dot(a - b, a - b)); }
inline double cross(pt a, pt b) { return a.x * b.y - a.y * b.x; }
inline double cross2(pt a, pt b, pt c) { return cross(b - a, c - a); }
inline int orientation(pt a, pt b, pt c) { return sgn(cross(b - a, c - a)); }
 
int is_point_in_convex(vector<pt> &p, const pt& x) { // O(log n)
    int n = p.size(); assert(n >= 3);
    int a = orientation(p[0], p[1], x), b = orientation(p[0], p[n - 1], x);
    if (a < 0 || b > 0) return 1;
    int l = 1, r = n - 1;
    while (l + 1 < r) {
        int mid = l + r >> 1;
        if (orientation(p[0], p[mid], x) >= 0) l = mid;
        else r = mid;
    }
    int k = orientation(p[l], p[r], x);
    if (k <= 0) return -k;
    if (l == 1 && a == 0) return 0;
    if (r == n - 1 && b == 0) return 0;
    return -1;
}
bool is_point_on_seg(pt a, pt b, pt p) {
    if (fabs(cross(p - b, a - b)) < eps) {
        if (p.x < min(a.x, b.x) - eps || p.x > max(a.x, b.x) + eps) return false;
        if (p.y < min(a.y, b.y) - eps || p.y > max(a.y, b.y) + eps) return false;
        return true;
    }
    return false;
}
bool is_point_on_polygon(vector<pt> &p, const pt& z) {
    int n = p.size();
    for (int i = 0; i < n; i++) {
        if (is_point_on_seg(p[i], p[(i + 1) % n], z)) return 1;
    }
    return 0;
}
int winding_number(vector<pt> &p, const pt& z) { // O(n)
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
int is_point_in_polygon(vector<pt> &p, const pt& z) { // O(n)
    int k = winding_number(p, z);
    return k == 1e9 ? 0 : k == 0 ? 1 : -1;
}
 
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n, m, i, inside = 0, boundary = 0;
    double x, y;
    cin>>n>>m;
    vector<pt> p;
    for(i=1;i<=n;i++)
    {
        cin>>x>>y;
        p.push_back({(T)x, (T)y});
    }
 
    for(i = 1; i <= m; i++)
    {
        cin>>x>>y;
        if(is_point_in_polygon(p, {x, y})==-1)
            cout<<"INSIDE\n";
        else if(is_point_in_polygon(p, {x, y}) == 0)
            cout<<"BOUNDARY\n";
        else
            cout<<"OUTSIDE\n";
    }
    // cout<< inside<< ' '<< boundary<<endl;
    return 0;
}
#include<bits/stdc++.h>
#define ll                  long long
#define endl                '\n'
#define F                   first
#define S                   second
#define all(a)              (a.begin()),(a.end())
#define UNIQUE(X)           (X).erase(unique(all(X)),(X).end())
#define SORT_UNIQUE(c)      (sort(c.begin(),c.end()), c.resize(distance(c.begin(),unique(c.begin(),c.end()))))
#define ms(a,b)             memset(a, b, sizeof(a))
#define eps                 1e-9
#define MOD                 1000000007
#define sz                  200005
using namespace std;
 
typedef double T;
 
struct pt {
    T x,y;
    pt operator+(pt p) {return {x+p.x, y+p.y};}
    pt operator-(pt p) {return {x-p.x, y-p.y};}
    pt operator*(T d) {return {x*d, y*d};}
    pt operator/(T d) {return {x/d, y/d};} // only for floatingpoint
};
template <typename T> int sgn(T x) {
    return (T(0) < x) - (x < T(0));
}
 
inline double dot(pt a, pt b) { return a.x * b.x + a.y * b.y; }
inline double dist2(pt a, pt b) { return dot(a - b, a - b); }
inline double dist(pt a, pt b) { return sqrt(dot(a - b, a - b)); }
inline double cross(pt a, pt b) { return a.x * b.y - a.y * b.x; }
inline double cross2(pt a, pt b, pt c) { return cross(b - a, c - a); }
inline int orientation(pt a, pt b, pt c) { return sgn(cross(b - a, c - a)); }
 
int is_point_in_convex(vector<pt> &p, const pt& x) { // O(log n)
    int n = p.size(); assert(n >= 3);
    int a = orientation(p[0], p[1], x), b = orientation(p[0], p[n - 1], x);
    if (a < 0 || b > 0) return 1;
    int l = 1, r = n - 1;
    while (l + 1 < r) {
        int mid = l + r >> 1;
        if (orientation(p[0], p[mid], x) >= 0) l = mid;
        else r = mid;
    }
    int k = orientation(p[l], p[r], x);
    if (k <= 0) return -k;
    if (l == 1 && a == 0) return 0;
    if (r == n - 1 && b == 0) return 0;
    return -1;
}
bool is_point_on_seg(pt a, pt b, pt p) {
    if (fabs(cross(p - b, a - b)) < eps) {
        if (p.x < min(a.x, b.x) - eps || p.x > max(a.x, b.x) + eps) return false;
        if (p.y < min(a.y, b.y) - eps || p.y > max(a.y, b.y) + eps) return false;
        return true;
    }
    return false;
}
bool is_point_on_polygon(vector<pt> &p, const pt& z) {
    int n = p.size();
    for (int i = 0; i < n; i++) {
        if (is_point_on_seg(p[i], p[(i + 1) % n], z)) return 1;
    }
    return 0;
}
int winding_number(vector<pt> &p, const pt& z) { // O(n)
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
int is_point_in_polygon(vector<pt> &p, const pt& z) { // O(n)
    int k = winding_number(p, z);
    return k == 1e9 ? 0 : k == 0 ? 1 : -1;
}
 
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n, m, i, inside = 0, boundary = 0;
    double x, y;
    cin>>n>>m;
    vector<pt> p;
    for(i=1;i<=n;i++)
    {
        cin>>x>>y;
        p.push_back({(T)x, (T)y});
    }
 
    for(i = 1; i <= m; i++)
    {
        cin>>x>>y;
        if(is_point_in_polygon(p, {x, y})==-1)
            cout<<"INSIDE\n";
        else if(is_point_in_polygon(p, {x, y}) == 0)
            cout<<"BOUNDARY\n";
        else
            cout<<"OUTSIDE\n";
    }
    // cout<< inside<< ' '<< boundary<<endl;
    return 0;
}
