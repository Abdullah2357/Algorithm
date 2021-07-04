#include<bits/stdc++.h>
#define ll     long long
using namespace std;

#define sz 55

string s;
int n,dp[sz][sz][sz];

int FuN(int pos,int vowel,int consonant)/// FuN for check is it possible to make the string good
{
    if(vowel>=3 || consonant>=5)
        return 0;
    if(pos==n)
    {
        return (vowel<3 && consonant<5);
    }

    if(dp[pos][vowel][consonant] != -1)
        return dp[pos][vowel][consonant];

    int ret1 = 0,ret2 = 0;

    if(s[pos]=='?')
    {
        ret1 = FuN(pos+1,vowel+1,0);
        ret2 = FuN(pos+1,0,consonant+1);
    }
    else if(s[pos]=='A' || s[pos]=='E' || s[pos]=='I' || s[pos]=='O' || s[pos]=='U')
    {
        ret1 = FuN(pos+1,vowel+1,0);
    }
    else
    {
        ret2 = FuN(pos+1,0,consonant+1);
    }

    return dp[pos][vowel][consonant] = ret1|ret2;
}

int FuN2(int pos,int vowel,int consonant)/// FuN for check is it possible to make the string bad
{
    if(vowel>=3 || consonant>=5)
        return 0;
    if(pos==n)
    {
        return (vowel<3 && consonant<5);
    }

    if(dp[pos][vowel][consonant] != -1)
        return dp[pos][vowel][consonant];

    int ret1 = 1,ret2 = 1;

    if(s[pos]=='?')
    {
        ret1 = FuN2(pos+1,vowel+1,0);
        ret2 = FuN2(pos+1,0,consonant+1);
    }
    else if(s[pos]=='A' || s[pos]=='E' || s[pos]=='I' || s[pos]=='O' || s[pos]=='U')
    {
        ret1 = FuN2(pos+1,vowel+1,0);
    }
    else
    {
        ret2 = FuN2(pos+1,0,consonant+1);
    }

    return dp[pos][vowel][consonant] = ret1&ret2;
}

void Solve(int t)
{
    cin>>s;
    n = s.size();

    memset(dp,-1,sizeof(dp));
    int good = FuN(0,0,0);

    memset(dp,-1,sizeof(dp));
    int bad = FuN2(0,0,0);
    bad^=1;

    printf("Case %d: ",t);

    if(good==1 && bad==0)
        printf("GOOD\n");
    else if(good==1 && bad==1)
        printf("MIXED\n");
    else
        printf("BAD\n");
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
