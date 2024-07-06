#include<bits/stdc++.h>
#define ll      long long
#define MOD     1000000007
#define sz      200005
using namespace std;

int failure[sz];

void build_failure_function(string pattern,int m)
{
    failure[0] = failure[1] = 0; // base case

    for(int i = 2; i <= m; i++) // i is the length of the prefix we are dealing with
    {
        // j is the index of the largest next partial match 
        // (the largest suffix/prefix) of the string under index i - 1
        int j = failure[i-1];
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
std::vector<int> res;
void kmp(string text, string pattern)
{
    int n = text.size();
    int m = pattern.size();
    build_failure_function(pattern, m);
    int i = 0;
    int j = 0; // the first character of the text

    while(j<n)
    {
        if(j==n)
            break;
        if(text[j] == pattern[i])
        {
            i++;
            j++;
            if(i==m)
            {
                res.push_back(j-m+1);
                i = failure[i];
            }
        }
        else
        {
            if(i==0)
                j++;
            else
                i = failure[i];
        }

    }
    return ;
}


int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int t,T;
    cin>>T;
    for(t=1;t<=T;t++)
    {
        int n, i;
        string text,pattern;
        cin>>text>>pattern;
        res.clear();
        kmp(text, pattern);
        if(res.size()==0)
        {
            cout<<"Not Found\n";
        }
        else
        {
            cout<<res.size()<<'\n';
            for(auto it:res)
                cout<<it<< ' ';
            cout<<"\n";
        }
        cout<<"\n";
    }
    return 0;
}
