#include<bits/stdc++.h>
#define ll     long long
using namespace std;

ll n,coin[20];
vector<int> A,B;

void SubSet(int pos,int value)
{
    if(pos>n/2)
    {
        A.push_back(value);
        return ;
    }
    SubSet(pos+1,value);
    SubSet(pos+1,value+coin[pos]);
    SubSet(pos+1,value+coin[pos]+coin[pos]);
}
void SubSet2(int pos,int value)
{
    if(pos>n)
    {
        B.push_back(value);
        return ;
    }
    SubSet2(pos+1,value);
    SubSet2(pos+1,value+coin[pos]);
    SubSet2(pos+1,value+coin[pos]+coin[pos]);
}
bool Find(int value)
{
    int lo=0,hi = B.size()-1,mid;
    while(lo<=hi)
    {
        mid = (lo+hi)/2;
        if(B[mid]==value)
        {
            return 1;
        }
        else if(B[mid]>value)
        {
            hi = mid-1;
        }
        else
            lo = mid+1;
    }
    return 0;
}
void Solve(int t)
{
    ll i, j, fg = 0, x, y, ans = 0,k;
    scanf("%d %d",&n,&k);
    A.clear();
    B.clear();
    for(i=1;i<=n;i++)
    {
        scanf("%d",&coin[i]);
    }
    SubSet(1,0);
    SubSet2(n/2+1,0);
    sort(A.begin(),A.end());
    sort(B.begin(),B.end());
    for(i=0;i<A.size();i++)
    {
        int baki = k-A[i];
        if(Find(baki)){
            fg=1;
            break;
        }
    }
    if(fg)
        printf("Case %d: Yes\n",t);
    else
        printf("Case %d: No\n",t);
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

