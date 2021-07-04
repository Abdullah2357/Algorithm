#include<bits/stdc++.h>
using namespace std;

#define N 100005
int ST[20][N];
int a[N];

void Compute_ST(int n)
{
    for(int i=0;i<n;i++) ST[0][i] = a[i];
    for(int k=1 ; (1<<k) < n; k++)
    {
        for(int i=0; i+(1<<k)<=n ; i++)
        {
            int x = ST[k-1][i];
            int y = ST[k-1][i+(1<<k-1)];
            ST[k][i] = min(x, y);
        }
    }
}
int RMQ(int i, int j)
{
    int k = log2(j-i);
    int x = ST[k][i];
    int y = ST[k][j - (1<<k)+1];
    return min(x, y);
}
int main()
{
    int n;
    cin>>n;
    for(int i = 0; i < n ;i++)
    {
        cin>>a[i];
    }
    Compute_ST(n);
    int q;
    cin>>q;
    while(q--)
    {
        int l, r;
        cin>>l>>r;
        cout<<RMQ(l, r)<<endl;
    }
    return 0;
}
