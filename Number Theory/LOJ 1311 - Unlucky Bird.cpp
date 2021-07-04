#include<bits/stdc++.h>
using namespace std;

void Solve(int t)
{
    double v1, v2, v3, a1, a2, TimeNeedToStop1, TimeNeedToStop2, d, DisCovByBird;
    scanf("%lf %lf %lf %lf %lf",&v1, &v2, &v3, &a1, &a2);
    TimeNeedToStop1 = v1/a1;
    TimeNeedToStop2 = v2/a2;
    d = v1*TimeNeedToStop1 - (0.5*a1*TimeNeedToStop1*TimeNeedToStop1);
    d += v2*TimeNeedToStop2 - (0.5*a2*TimeNeedToStop2*TimeNeedToStop2);
    DisCovByBird = v3*max(TimeNeedToStop1, TimeNeedToStop2);
    printf("Case %d: %.10f %.10f\n", t, d, DisCovByBird);
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
