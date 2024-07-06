#include<bits/stdc++.h>
using namespace std;

int a[105], D[105];

void Update(int l,int r,int x)
{
    D[l] += x;
    D[r+1] -= x;
}
void Difference_Array()
{
    int n, i, q, l, r, x;

    cin>>n;
    for(i=1;i<=n;i++)
    {
        cin>>a[i];
        D[i] = D[i]-D[i-1];
    }
    cin>>q;

    while(q--)
    {
        cin>>l>>r>>x;
        Update(l,r,x);
    }

    for(i=1;i<=n;i++)
    {
        a[i] = a[i-1]+D[i];
    }

    for(i=1;i<=n;i++)
    {
        cout<<a[i]<< ' ';
    }
    cout<<endl;
}

int main()
{
    Difference_Array();
}

