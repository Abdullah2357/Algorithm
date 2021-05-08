#include<bits/stdc++.h>
using namespace std;
int main()
{
    int t,g,l,a,b,i;
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d %d",&g,&l);
        if(l%g==0)
        {
            printf("%d %d\n",g,l);
        }
        else
            printf("-1\n");
        /*a = __gcd(g,l);
        b = (g*l) / a;
        cout<<a<<' '<<b<<endl;*/
    }
    return 0;
}
