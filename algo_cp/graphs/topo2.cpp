/*
KAHN'S ALGORITHM
TIME COMPLEXITY= O(V+E)

Algo:
enqueue all nodes with indegree 0
while queue is not empty
	deque a node
	push it into answer and increase visited by 1
	decrease indegree of all its neighbours
	enqueue a neighbour if its indegree becomes 0
if visited!=no of vertices
then linear order not possible(cycle)
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
void topo(vector<int> adj[],int V)
{
	int cnt = 0;
	queue<int> q;
	int indegree[V];
	mem(indegree,0,sizeof(indegree));
	for(int i=0;i<V;i++)
	{
		for(auto j:adj[i])
			++indegree[j];
	}
	for(int i=0;i<V;i++)
	{
		if(indegree[i]==0)
			q.push(i);
	}
	vector<int> sort;
	while(!q.empty())
	{
		int u=q.front();
		q.pop();
		sort.pb(u);++cnt;
		for(auto i:adj[u])
		{
			--indegree[i];
			if(indegree[i]==0)
				q.push(i);
		}
	}
	if(cnt!=V)
		cout<<-1<<'\n';
	else
	{
		for(auto i:sort)
			cout<<i<<' ';
		cout<<'\n';
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
	topo(adj,V);
	return 0;
}