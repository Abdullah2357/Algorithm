#include<bits/stdc++.h>
using namespace std;

string s,t;
int dp[3002][3002];

int FuN(int i,int j)
{
    if(i==s.size() || j==t.size())
    {
        return 0;
    }
    if(dp[i][j]!=-1)
        return dp[i][j];
    int ret1=0,ret2=0,ret3=0;
    if(s[i]==t[j])
        ret1 = 1+FuN(i+1,j+1);
    else
    {
        ret2 = FuN(i+1,j);
        ret3 = FuN(i,j+1);
    }
    return dp[i][j]= max(ret1,max(ret2,ret3));
}

void print(int i,int j)
{
    if(i==s.size() || j==t.size())
    {
        printf("\n");
        return ;
    }
    int ret1=0,ret2=0;
    if(s[i]==t[j]){
        cout<<s[i];
        print(i+1,j+1);
    }
    else
    {
        if(dp[i+1][j]>dp[i][j+1])
            print(i+1,j);
        else
            print(i,j+1);
    }
}
int main()
{
    cin>>s>>t;
    memset(dp,-1,sizeof(dp));
    int ans = FuN(0,0);
    print(0,0);
    return 0;
}

