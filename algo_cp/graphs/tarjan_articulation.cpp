/*
ARTICULATION POINT-> vertex on removal of which disconnects the graph
***********FOR UNDIRECTED GRAPH******************
Tarjan's Algorithm:
Perform DFS
A vertex u is an articulation point if one of the 2 conditions are satisfied:
1. u is a root and has 2 independent children in the DFS tree
2. u is not a root, and there exists at least one child v of u
   such that there is no back edge from subtree(v) to any ancestor of u
We maintain 2 arrays low[] and disc[]
disc[u]= discovery time of u in DFS
low[u] = discovery time of the earliest discovered vertex
		 that is reachable from subtree(u)
So, u is an articulation point if one of the 2 conditions are satisfied:
1. parent[u]=NULL and children>=2
2. low[v]>=disc[u] for any child v of u 
low[u] = min(
				d[u],
				d[w], for all back edges (u,w),
				low[v], for all children of u in DFS tree
			)
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
void arti(vector<int> adj[],int u,int *visited,int *disc,int *low,int* parent,int art[])
{
	static int time = 0;
	visited[u]=1;
	disc[u]=low[u]=++time;
	int children = 0;
	for(auto i:adj[u])
	{
		if(!visited[i])
		{
			parent[i]=u;
			++children;
			arti(adj,i,visited,disc,low,parent,art);
			low[u]=min(low[u],low[i]);

			if(parent[u]==-1&&children>=2)
				art[u]=1;
			else if(parent[u]!=-1&&low[i]>=disc[u])
				art[u]=1;
		}
		else if(parent[u]!=i)
			low[u]=min(low[u],disc[i]);
	}
}
int main()
{
	int V,E,u,v,i;
	cin>>V>>E;
	vector<int> adj[V];
	for(i=0;i<E;i++)
	{
		cin>>u>>v;
		adj[u].pb(v);
		adj[v].pb(u);
	}
	int visited[V],disc[V],low[V],parent[V],art[V];
	for(i=0;i<V;i++)
	{
		visited[i]=disc[i]=low[i]=art[i]=0;
		parent[i]=-1;
	}
	arti(adj,0,visited,disc,low,parent,art);
	for(i=0;i<V;i++)
	{
		if(art[i])
			cout<<i<<' ';
	}
	cout<<'\n';
	return 0;
}