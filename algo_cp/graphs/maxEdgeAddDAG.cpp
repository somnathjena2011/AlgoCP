/*
Add maximum no of edges to a DAG such that it remains DAG
Addition of even a single edge will create a cycle 

Algo:
Find topological sorting of the DAG
say v1,v2.......,vn
Add edges from vi to vj for all i,j such that j>i 
and there is not an edge already from i to j
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
vector<int> topo(vector<int> adj[],int V)
{
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
		sort.pb(u);
		for(auto i:adj[u])
		{
			--indegree[i];
			if(indegree[i]==0)
				q.push(i);
		}
	}
	return sort;
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
	vector<int> sort=topo(adj,V);
	int visited[V];
	mem(visited,0,sizeof(visited));
	for(i=0;i<sort.size();i++)
	{
		u=sort[i];
		for(auto x:adj[u])
			visited[x]=1;
		for(j=i+1;j<sort.size();j++)
		{
			if(!visited[sort[j]])
				cout<<sort[i]<<"-"<<sort[j]<<' ';
			visited[sort[j]]=0;
		}
	}
	cout<<'\n';
	return 0;
}