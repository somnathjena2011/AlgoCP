/*
Find all topological sorting of a DAG
ALGO:
for all vertices:
	if the vertex is not visited and has indegree 0
	then push it into topo sort, decrease indegree of its neighbours
	call toposort again

	then restore back the indegree and pop the topo sort
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
void topo(vector<int> adj[],int v,vector<int> sort,int* visited,int* indegree)
{
	int flag = 0;
	for(int i=0;i<v;i++)
	{
		if(indegree[i]==0&&!visited[i])
		{
			for(auto j:adj[i])
				--indegree[j];
			visited[i]=1;
			sort.pb(i);
			topo(adj,v,sort,visited,indegree);

			visited[i]=0;
			sort.erase(sort.end()-1);
			for(auto j:adj[i])
				++indegree[j];
			flag=1;
		}
	}
	if(!flag)
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
	int indegree[V],visited[V];
	mem(visited,0,sizeof(visited));
	mem(indegree,0,sizeof(indegree));
	for(i=0;i<E;i++)
	{
		cin>>u>>v;
		adj[u].pb(v);
		++indegree[v];
	}	
	vector<int> sort;
	topo(adj,V,sort,visited,indegree);
	return 0;
}