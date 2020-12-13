/*
Detect cycle in an undirected graph
Perform DFS
if there is an edge from current node to a visted node
which is not parent of that node then cycle
******ONLY FOR UNDIRECTED GRAPH*******
*/
#include<iostream>
#include<vector>
#include<map>
#include<set>
#include<cstring>
#include<algorithm>
#include<cmath>
#include<climits>
#include<stdio.h>
#include<queue>
#include<list>
#include<stack>
#include<random>
#include<chrono>
//mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
using namespace std;
#define COL 31
#define ROW 31
#define ll long long int
#define ull unsigned long long int
#define mp make_pair
#define pb push_back
#define mem memset
#define inf 1e18
#define mod 1000000007

int dfs(vector<int> adj[],int u,int *visited,stack<int> &s,int parent)
{
	visited[u] = 1;
	s.push(u);
	for(auto i:adj[u])
	{
		if(visited[i]&&parent!=i)
		{
			cout<<i<<' ';
			while(s.top()!=i)
			{
				cout<<s.top()<<' ';
				s.pop();
			}
			cout<<i<<'\n';
			return 1;
		}
		else if(!visited[i])
			return dfs(adj,i,visited,s,u);
	}
	s.pop();
}

int main()
{
	int V,E,u,v,i,j;
	cin>>V>>E;
	vector<int> adj[V];
	for(i=0;i<E;i++)
	{
		cin>>u>>v;
		adj[u].pb(v);
		adj[v].pb(u);
		//This algo only works for UNDIRECTED GRAPH
	}
	int visited[V];
	mem(visited,0,sizeof(visited));
	stack<int> s;
	dfs(adj,0,visited,s,-1);
	return 0;
}