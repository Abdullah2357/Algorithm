#include<bits/stdc++.h>
using namespace std;
int SOD[1005];
void SODF()
{
    memset(SOD,0,sizeof(SOD));
    int i,j;
    for(i=1;i<=1000;i++)
    {
        for(j=i;j<=1000;j+=i)
        {
            SOD[j] += i;
        }
    }
}
int main()
{
    int s,i,n,ans;
    SODF();
    for(int j=1 ; ; j++)
    {
        scanf("%d",&s);
        if(s==0)
            break;
        ans = -1;
        for(i=1000;i>=1;i--)
        {
            if(SOD[i] == s)
            {
                ans = i;
                break;
            }
        }
        printf("Case %d: %d\n",j,ans);    }
    return 0;
}
