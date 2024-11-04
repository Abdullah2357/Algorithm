#include<bits/stdc++.h>
#define ll                  long long
#define endl                '\n'
using namespace std;

ll Find_XOR_from_1_to_n(ll n){
    if(n%4==1)
        return 1;
    else if(n%4==2)
        return n+1;
    else if(n%4==3)
        return 0;
    else
        return n;
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    ll n;
    cin>>n;
    ll XOR = Find_XOR_from_1_to_n(n);
    return 0;
}
