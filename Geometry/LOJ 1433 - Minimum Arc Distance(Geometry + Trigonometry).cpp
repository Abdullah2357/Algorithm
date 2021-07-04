#include<bits/stdc++.h>
using namespace std;

double SQR(double x)
{
    return (x*x);
}
void Solve(int t)
{
    double ox, oy, ax, ay, bx, by;
    double AB, OA, OB, theta, ArcDistance;
    scanf("%lf %lf %lf %lf %lf %lf",&ox, &oy, &ax, &ay, &bx, &by);
    AB = sqrt(SQR(ax-bx) + SQR(ay-by));
    OA = sqrt(SQR(ax-ox) + SQR(ay-oy));
    OB = sqrt(SQR(ox-bx) + SQR(oy-by));
    theta = acos((SQR(OA)+SQR(OB)-SQR(AB))/(2.0*OA*OB));
    ArcDistance = OA*theta;
    printf("Case %d: %.10f\n",t, ArcDistance);
}
int main()
{
    int t,T;
    scanf("%d",&T);
    for(t=1;t<=T;t++)
    {
        Solve(t);
    }
    return 0;
}
