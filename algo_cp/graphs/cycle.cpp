/*
Detect cycle in a directed graph using colors
WHITE=> vertex not visited yet
GRAY=> vertex is being processed
BLACK=> all neighbours of the vertex visited,
		DFS for this node is finished
While doing DFS if we encounter a backedge from
current vertex to an ancestor, i.e. an edge from 
current node to a gray node
TIME COMPLEXITY=> O(V+E)
******ONLY FOR DIRECTED GRAPH*******
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


int dfs(vector<int> adj[],int u,int *color,stack<int> &s)
{
	color[u] = 1;
	s.push(u);
	for(auto i:adj[u])
	{
		if(color[i]==1)
		{
			stack<int> cycle;
			cycle.push(i);
			while(s.top()!=i)
			{
				cycle.push(s.top());
				s.pop();
			}
			cycle.push(i);
			while(!cycle.empty())
			{
				cout<<cycle.top()<<' ';
				cycle.pop();
			}
			cout<<'\n';
			return 1;
		}
		if(color[i]==0&&dfs(adj,i,color,s))
			return 1;
	}
	color[u] = 2;
	s.pop();
	return 0;
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
		//This algo only works for DIRECTED GRAPH
	}
	int color[V];
	mem(color,0,sizeof(color));
	stack<int> s;
	dfs(adj,0,color,s);
	return 0;
}