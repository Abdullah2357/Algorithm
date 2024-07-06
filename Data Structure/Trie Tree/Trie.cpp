#include<bits/stdc++.h>
using namespace std;

const int N = 1e6+100;
int to[N][26];///N = # of nodes in the tree
int tot_nodes = 1;
int cnt[N];/// # of string that ends int the subtree of u

int add_string(string &s)
{
    int cur = 1;///root node
    cnt[cur]++;
    for(int i=0;i<s.size();i++)
    {
        int ch = s[i]-'a';
        if(!to[cur][ch]) to[cur][ch] = ++tot_nodes;
        cur = to[cur][ch];
        cnt[cur]++;
    }
    return cur;
}

int query(string &t)
{
    int cur = 1;
    for(int i=0;i<t.size();i++)
    {
        int ch = t[i]-'a';
        if(!to[cur][ch]) return 0;
        cur = to[cur][ch];
    }
    return cnt[cur];
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin>>n;
    int q;
    cin>>q;
    for(int i=1;i<=n;i++)
    {
        string s;
        cin>>s;
        add_string(s);
    }

    while(q--)
    {
        string t;
        cin>>t;
        cout<<query(t)<<endl;
    }
}
