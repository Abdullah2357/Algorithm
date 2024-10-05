#include<bits/stdc++.h>
#define ll                  long long
#define endl                '\n'
#define F                   first
#define S                   second
#define all(a)              (a.begin()),(a.end())
#define UNIQUE(X)           (X).erase(unique(all(X)),(X).end())
#define SORT_UNIQUE(c)      (sort(c.begin(),c.end()), c.resize(distance(c.begin(),unique(c.begin(),c.end()))))
#define ms(a,b)             memset(a, b, sizeof(a))
#define MOD                 1000000007
#define sz                  200005
using namespace std;

typedef double T;

void circle(T x1, T y1, T x2, T y2, T x3, T y3){
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

    if(h>0)
        cout<<fixed<<setprecision(3)<<"(x "<<"- "<<h<<")^2 + ";
    else if(h<0)
        cout<<fixed<<setprecision(3)<<"(x "<<"+ "<<-h<<")^2 + ";
    else
        cout<<"x^2 + ";

    if(k>0)
        cout<<fixed<<setprecision(3)<<"(y - "<<k<<")^2 = ";
    else if(k<0)
        cout<<fixed<<setprecision(3)<<"(y + "<<-k<<")^2 = ";
    else
        cout<<"y^2 = ";
    cout<<fixed<<setprecision(3)<<r<<"^2\n";

    cout<<"x^2 + y^2";
    if(g<0)
        cout<<fixed<<setprecision(3)<<" - "<<-2.0*g<<"x";
    else if(g>0)
        cout<<fixed<<setprecision(3)<<" + "<<2.0*g<<"x";
    else
        cout<<"";
    
    if(f<0)
        cout<<fixed<<setprecision(3)<<" - "<<-2.0*f<<"y";
    else if(f>0)
        cout<<setprecision(3)<<" + "<<2.0*f<<"y";
    else
        cout<< "";
    if(c<0)
        cout<<" - "<<fixed<<setprecision(3)<<abs(c);
    else if(c>0)
        cout<<" + "<<fixed<<setprecision(3)<<abs(c);
    else
        ;
    cout<<" = 0\n\n";
}

int main()
{
    double x1, x2, x3, y1, y2, y3;
    while(scanf("%lf %lf", &x1, &y1) == 2){
        cin>>x2>>y2>>x3>>y3;
        circle(x1, y1, x2, y2, x3, y3);
    }

}
