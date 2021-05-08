#include<bits/stdc++.h>
using namespace std;


int SF[10000005];
void FuN()
{
    for( int i = 2 ; i * i <= 10000000 ; i ++ ){
        if( !SF[i] ){
            for( int j = i ; j <= 10000000 ; j += i ){
                if( !SF[j] ) SF[j] = i ;
            }
        }
    }
    for( int i = 2 ; i <= 1e7 ; i ++ ) if( !SF[i] ) SF[i] = i ;
}
vector<int> Factor;
//map<int,int> Factor;
void GetFactor(int n)
{
    Factor.clear();
    while(n!=1)
    {
        //Factor[SF[n]]++;
        Factor.push_back(SF[n]);
        n/=SF[n];

    }
}

int main()
{
    FuN();
    GetFactor(45);
    for(auto it: Factor)
        cout<<it<< ' ';
    cout<<endl;
}
