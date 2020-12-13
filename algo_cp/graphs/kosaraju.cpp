/*
FIND STRONGLY CONNECTED COMPONENTS IN A DIRECTED GRAPH
ALGORITHM:
Say there are 3 SCCS c1->c2->c3
Ideally to find SCCs we would like to perform the DFS travseral from 
a vertex in the sink component
Then what would happen is that we will visit all the vertices in c3
then we have to jump to any other vertex, so when we make a jump
we know we identified a SCC

Finish Time of a vertex that connects to another SCC
other than its own, is always greater than finish time
of all vertices in the other SCC

So we perform DFS starting from any node and push them in stack after 
DFS from that vertex is finsihed. So, higher vertex in the stack
means later finsih time.

Next we transpose the graph, so if a SCC(c1) was a source
it becomes sink. We wanted to traverse from sink, and a vertex of c1 has highest finsih time
and at top of stack, so we can traverse in that way now.
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
void dfs(vector<int> adj[],int u,stack<int>& s,int* visited)
{
	visited[u]=1;
	for(auto i:adj[u])
	{
		if(!visited[i])
			dfs(adj,i,s,visited);
	}
	s.push(u);
}
void dfs2(vector<int> adj[],int u,int *visited,vector<int>& SCC)
{
	visited[u]=1;
	SCC.pb(u);
	for(auto i:adj[u])
	{
		if(!visited[i])
			dfs2(adj,i,visited,SCC);
	}
}
vector<vector<int>> kosaraju(vector<int> adj[],int V)
{
	stack<int> s;
	int visited[V];
	mem(visited,0,sizeof(visited));
	dfs(adj,0,s,visited);
	mem(visited,0,sizeof(visited));
	vector<vector<int>> SCCs;
	vector<int> trans[V];
	for(int i=0;i<V;i++)
	{
		for(auto j:adj[i])
			trans[j].pb(i);
	}
	while(!s.empty())
	{
		int u=s.top();
		s.pop();
		if(!visited[u])
		{
			vector<int> SCC;
			dfs2(trans,u,visited,SCC);
			SCCs.pb(SCC);
		}
	}
	return SCCs;
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
	}
	vector<vector<int>> SCCs = kosaraju(adj,V);
	for(auto it=SCCs.begin();it!=SCCs.end();it++)
	{
		vector<int> SCC = *it;
		for(auto x:SCC)
			cout<<x<<' ';
		cout<<'\n';
	}
	return 0;
}