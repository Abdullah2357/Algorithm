#include<bits/stdc++.h>
#define ll                  long long
#define endl                '\n'
#define F                   first
#define S                   second
#define all(a)              (a.begin()),(a.end())
#define UNIQUE(X)           (X).erase(unique(all(X)),(X).end())
#define SORT_UNIQUE(c)      (sort(c.begin(),c.end()), c.resize(distance(c.begin(),unique(c.begin(),c.end()))))
#define ms(a,b)             memset(a, b, sizeof(a))
#define Input               freopen("in.txt","r",stdin)
#define Output              freopen("out.txt","w",stdout)
#define MOD                 1000000007
#define sz                  200005
using namespace std;

int n, x, c[105];
int dp[1000005][105];


void Solve(int t)
{
    int i, j, ans = 0, fg = 0;
    cin>>n>>x;
    for(i = 1; i <= n; i++)
    {
        cin>>c[i];
    }   
    //dp[i][k] -> how many ways to construct k starting from i

    // base case
    for(i=1;i<=n;i++){
        dp[i][0] = 1;
    }

    for(i = n;i>=1;i--){
        for(j = 1;j<=x;j++){
            int skiping = dp[i+1][j]; // If we skip i-th coin
            int picking = 0;
            if(c[i]<=j){
                picking = dp[i][j-c[i]];// If we pick i-th coin
            }

            dp[i][j] = (skiping + picking)%MOD;
        }
    }
    ans = dp[1][x];
    cout<<ans<<endl;
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
