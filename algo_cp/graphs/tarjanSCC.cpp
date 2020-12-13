/*
***********FOR DIRECTED GRAPH******************
Tarjan's Algorithm:
Perform DFS
DFS produces DFS tree/forest, SCCs form subtress of DFS tree
If we can find head of such subtrees, then all nodes in that subtree
including the head will be one SCC
There is no back edge from a SCC to another
(There can be cross edges)
A node is HEAD if low[u]==disc[u]
low[u]=disc of earliest visited vertex that can be
	   reaached from subtree rooted at that vertex
	   i.e. disc of vertex to which there is a backedge from 
	   a descendant of u
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
void SCC(vector<int> adj[],int u,int disc[],int low[],int onStack[],stack<int>& s)
{
	static int time = 0;
	s.push(u);
	onStack[u]=1;
	disc[u]=low[u]=++time;
	for(auto i:adj[u])
	{
		if(disc[i]==-1)//not visited
		{
			SCC(adj,i,disc,low,onStack,s);
			low[u]=min(low[u],low[i]);
		}
		else if(onStack[i]==1)//back edge, not cross edge
			low[u]=min(low[u],disc[i]);
	}
	int v;
	if(low[u]==disc[u])//head node
	{
		while(s.top()!=u)
		{
			v=s.top();
			s.pop();
			cout<<v<<' ';
			onStack[v]=0;
		}
		s.pop();
		cout<<u<<'\n';
		onStack[u]=0;
	}
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
	int disc[V],low[V],onStack[V];
	mem(disc,-1,sizeof(disc));
	mem(low,-1,sizeof(low));
	mem(onStack,0,sizeof(onStack));
	stack<int> s;
	for(i=0;i<V;i++)
	{
		if(disc[i]==-1)
			SCC(adj,i,disc,low,onStack,s);
	}
	return 0;
}