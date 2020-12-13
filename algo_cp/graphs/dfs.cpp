/*
TIME COMPLEXITY = O(V+E)*/
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

void dfs(vector<int> adj[],int u,int* visited)
{
	cout<<u<<' ';
	visited[u]=1;
	for(auto i:adj[u])
	{
		if(!visited[i])
			dfs(adj,i,visited);
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
	int visited[V];
	mem(visited,0,sizeof(visited));
	for(i=0;i<V;i++)
	{
		if(!visited[i])
			dfs(adj,i,visited);
	}
	return 0;
}