#include<bits/stdc++.h>
#define ll     long long
using namespace std;

#define sz 200005


double AreaOfTriangle(double a,double b,double c)
{
    double s,area;
    s = (a+b+c)/2.0;
    area = sqrt(s*(s-a)*(s-b)*(s-c));
    return area;
}
void Solve(int t)
{
    int a,b,c;
    cin>>a>>b>>c;
    double area = AreaOfTriangle(a * 1.0, b * 1.0, c * 1.0);
    double s = (a+b+c)/2.0;
    double ans = area/s;
    printf("%.8f\n",ans);
}
int main()
{
    int t,T=1;
    scanf("%d",&T);
    for(t=1;t<=T;t++)
    {
        Solve(t);
    }
    return 0;
}

