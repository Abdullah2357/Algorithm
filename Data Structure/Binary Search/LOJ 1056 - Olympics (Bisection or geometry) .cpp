#include<bits/stdc++.h>
#define ll     long long
using namespace std;

#define PI 2*acos(0.0)
#define sz 200005


void Solve(int t)
{
    int a,b;
    scanf("%d : %d",&a,&b);
    double r = sqrt(a*a+b*b)/2.0;
    double theta = (r*r+r*r-b*b)/(2*r*r);
    theta = acos(theta);
    double  s = r*theta;
    double res = 400/(2*s+2*a);
    printf("Case %d: %.6f %.6f\n",t,a*res,b*res);
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
//#include<bits/stdc++.h>
//#define ll     long long
//using namespace std;
//#define Output          freopen("output.txt","w",stdout)
//
//#define PI 2*acos(0.0)
//#define sz 200005
//
//double perimeter(double a,double b)
//{
//    double r = sqrt(a*a+b*b)/2.0;
//    double theta = (r*r+r*r-b*b)/(2*r*r);
//    theta = acos(theta);
//    double  s = r*theta;
//    return s+s+a+a;
//}
//void Solve(int t)
//{
//    int a,b;
//    scanf("%d : %d",&a,&b);
//    double  lo = 0,hi = 100000,mid,res = -1;
//    while(hi-lo>.00000001)
//    {
//        mid = (lo+hi+lo)/3;
//        double mid2 = (lo+hi+hi)/3;
//        double p = perimeter((double)a*mid,(double)b*mid);
//        double p2 = perimeter((double)a*mid2,(double)b*mid2);
//        if(abs(400-p) <= abs(400-p2))
//        {
//            res = mid;
//            hi = mid2;
//        }
//        else
//        {
////            res = mid2;
//            lo = mid;
//        }
////
////        if(p<400)
////        {
////            res = mid;
////            lo = mid;
////        }
////        else
////            hi = mid;
//    }
//    printf("Case %d: %.6f %.6f\n",t,a*res,b*res);
//}
//int main()
//{
//    int t,T=1;
//    Output;
//    scanf("%d",&T);
//    for(t=1;t<=T;t++)
//    {
//        Solve(t);
//    }
//    return 0;
//}
