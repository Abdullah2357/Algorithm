#include<bits/stdc++.h>
#define ll      long long
#define MOD     1000000007
#define sz      200005
using namespace std;

int failure[sz];

void build_failure_function(vector<int> pattern,int m)
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

int kmp(vector<int> text, vector<int> pattern)
{
    int n = text.size();
    int m = pattern.size();
    build_failure_function(pattern, m);
    int i = 0;
    int j = 0; // the first character of the text
    int ans = 0;

    while(j<n)
    {
        if(j==n)
            return false;// reached the end of the text

        if(text[j] == pattern[i])
        {
            i++;
            j++;
            if(i==m){
                ans++;
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
    return ans;
}


int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n, w, i, a[200005], b[200005];
    cin>>n>>w;
    std::vector<int> text, pattern;
    for(i=1;i<=n;i++)
    {
    	cin>>a[i];
    	if(i>1)
    		text.push_back(a[i]-a[i-1]);
    }
    for(i=1;i<=w;i++)
    {
    	cin>>b[i];
    	if(i>1)
    		pattern.push_back(b[i]-b[i-1]);
    }
    if(w==1)
    	cout<<n<<endl;
    else
    	cout<<kmp(text, pattern)<<endl;
    return 0;
}
