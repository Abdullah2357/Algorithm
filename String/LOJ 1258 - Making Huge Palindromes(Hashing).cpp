#include<bits/stdc++.h>
#define ll      long long
#define MOD     1000000007
#define sz      1000005
using namespace std;

ll p[sz], hashsum[sz], rev_hashsum[sz];

bool isEqual(int x,int n)
{
    ll H2 = (p[sz-5] * rev_hashsum[x-1])%MOD;
    ll H1 = (hashsum[n-1] - hashsum[n-x-1]+MOD)%MOD;
    H1 = (H1*p[sz-5-n+x])%MOD;
    if(H1==H2)
        return true;
    else
        return false;
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    p[0] = 1;
    for(int i=1;i<sz;i++)
    {
        p[i] = (p[i-1]*31)%MOD;
    }
    int t,T;
    cin>>T;
    for(t=1; t<=T; t++){
        string text, pattern;
        cin>>text;
        pattern = text;
        reverse(pattern.begin(), pattern.end());
        int n = text.size();
        for(int i=0;i<n;i++)
        {
            hashsum[i] = ((text[i]-'a'+1)*p[i])%MOD;
            rev_hashsum[i] = ((pattern[i]-'a'+1)*p[i])%MOD;
            if(i){
                hashsum[i] = (hashsum[i-1] + hashsum[i])%MOD;
                rev_hashsum[i] = (rev_hashsum[i-1] + rev_hashsum[i])%MOD;
            }
        }
        int ans = 2*n-1;
        for(int i = n;i>=1;i--)
        {
            if(isEqual(i,n))
            {
                ans = 2*n - i;
                break;
            }
        }
        cout<<"Case "<<t<<": "<<ans<<'\n';
    }
    return 0;
}
