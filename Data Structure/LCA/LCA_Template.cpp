#include<bits/stdc++.h>
#define sz 100005
using namespace std;

int parent[18][sz], level[sz];
std::vector<int> graph[sz];

void DFS(int u, int par)
{
	parent[0][u] = par;
	for(int i = 1; i<= 17; i++){
		parent[i][u] = parent[i-1][parent[i-1][u]];
	}
	for(auto v:graph[u])
	{
		if(v != par){
			level[v] = level[u] + 1;
			DFS(v, u);
		}
	}
}
int find_LCA(int x, int y)
{
	if(level[x] < level[y])
		swap(x, y);
	for(int i = 17; i >= 0; i--){
		if(level[parent[i][x]] < level[y])
			continue;
		x = parent[i][x];
	}

	if(x == y)
		return x;

	for(int i = 17;i >= 0; i--){
		if(parent[i][x] != parent[i][y])
		{
			x = parent[i][x];
			y = parent[i][y];
		}
	}
	return parent[0][x];
}


int main(){
	int n, i, u, v;
	cin>>n;
	for(i=1;i<n;i++)
	{
		cin>>u>>v;
		graph[u].push_back(v);
		graph[v].push_back(u);
	}

	DFS(1, 1);
	int q;
	cin>>q;
	while(q--)
	{
		cin>>u>>v;
		cout<< find_LCA(u , v)<< endl;
	}
	return 0;
}

/*
15
1 2 
1 3
2 4
2 5
3 6 
3 7
4 8
4 9
5 10 
5 11
6 12 
6 13
7 14 
7 15

3
8 4
8  5
12 7
*/