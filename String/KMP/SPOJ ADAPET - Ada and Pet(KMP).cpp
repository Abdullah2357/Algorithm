#include<bits/stdc++.h>
#define ll      long long
#define MOD     1000000007
#define sz      500005
#define endl    '\n'
using namespace std;

ll failure[sz];

void build_failure_function(string pattern,ll m)
{
    failure[0] = failure[1] = 0; // base case

    for(ll i = 2; i <= m; i++) // i is the length of the prefix we are dealing with
    {
        // j is the index of the largest next partial match 
        // (the largest suffix/prefix) of the string under index i - 1
        ll j = failure[i-1];
        while(true)
        {
            // check if the last character of prefix of length i "expands" the current "candidate"
            if(pattern[j] == pattern[i-1])
            {
                failure[i] = j+1;
                break;
            }
            if(j==0)// if we cannot "expand" even the empty string
            {
                failure[i] = 0;
                break;
            }
            j = failure[j]; // else go to the next best "candidate" partial match
        }
    }
}


int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int t,T;
    cin>>T;
    for(t=1;t<=T;t++)
    {
        ll n, k;
        string pattern;
        cin>>pattern>>k;
        n = pattern.size();
        ll ans = n;
        build_failure_function(pattern, n);
        ans += (k-1)*(n-failure[n]);
        cout<<ans<<endl;
    }
    return 0;
}
