#include<bits/stdc++.h>
#define ll                  long long
#define endl                '\n'
#define sz                  1000005
using namespace std;


int Set(int N, int pos) {return  N = N | (1<<pos);}
int Reset(int N, int pos) {return  N = N & ~(1<<pos);}
bool Cheek(int N, int pos) {return  (bool)(N & (1<<pos));}

int n, a[sz];
int b[sz][32];

void Solve(int t)
{
    ll i, j, ans = 0, fg = 0;
    cin>>n;
    for(i = 1; i <= n; i++)
    {
        cin>>a[i];
        for(j=0;j<32;j++){
            b[i][j] = Cheek(a[i], j);
        }
    }

    for(j=0;j<32;j++){
        int one = 0, zero = 0;
        for(i=1;i<=n;i++){
            if(b[i][j]==1)
                one++;
            else
                zero++;
        }
        ans += (1<<j)*(one*(one-1))/2;
        // ans = (# of 1)C2
    }
    cout<<ans<<endl;

    
    ///pseudo code (n<=1e6, a[i]<=1e9, or high)
    /*ans = 0;
    for(i=1;i<=n;i++){
        for(j=i+1;j<=n;j++){
            ans += a[i]&a[j];
        }
    }
    cout<<ans<<endl;*/
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int t, T = 1;
    // cin>>T;
    for(t = 1; t <= T; t++)
        Solve(t);
    return 0;
}
