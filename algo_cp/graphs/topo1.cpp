/*
ONLY FOR DIRECTED ACYCLIC GRAPH
No topological sort for CYCLIC graphs
if there is an edge u->v, then v comes after u in the order
ALgo:
when node topo is called for u,
then it is called for all its neighbours recursively
then u is pushed onto the stack
it means nodes in tree rooted at u are pushed into the stack
and after then only u is pushed 
so when we pop the stack u comes first
TIME COMPLEXITY=O(V+E)

1st vertex of topo sort always has indegree 0
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

void topo(vector<int> adj[],int u,int *visited,stack<int> &s)
{
	visited[u]=1;
	for(auto i:adj[u])
	{
		if(!visited[i])
			topo(adj,i,visited,s);
	}
	s.push(u);
}

int main()
{
	int V,E,i,j,u,v;
	cin>>V>>E;
	vector<int> adj[V];
	for(i=0;i<E;i++)
	{
		cin>>u>>v;
		adj[u].pb(v);
	}
	int visited[V];
	mem(visited,0,sizeof(visited));
	stack<int> sort;
	for(i=0;i<V;i++)
	{
		if(!visited[i])
			topo(adj,i,visited,sort);
	}
	while(!sort.empty())
	{
		cout<<sort.top()<<' ';
		sort.pop();
	}
	cout<<'\n';
	return 0;
}