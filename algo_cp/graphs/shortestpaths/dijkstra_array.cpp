/*
->SINGLE SOURCE SHORTEST PATH
->BOTH FOR UNDIRECTED AND DIRECTED GRAPHS
->GREEDY ALGORITHM
->ONLY NON_NEGATIVE WEIGHTS
->CAN BE IMPLEMENTED USING BINARY HEAP, HERE DONE USING ARRAY
Algo:
Maintain 2 sets S and V-S, S contains vertices whose
shortest distance from s has been found
Update shortest distance of vertices from V-S

TIME COMPLEXITY=>O(V^2)
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
#define MAX 100000
int main()
{
	int V,E,u,v,w,i,j,s;
	cin>>V>>E;
	int adj[V][V];
	for(i=0;i<V;i++)
		for(j=0;j<V;j++)
			adj[i][j]=MAX;
	for(i=0;i<E;i++)
	{
		//here done for undirected graphs
		cin>>u>>v>>w;
		adj[u][v]=w;
		adj[v][u]=w;
	}
	int parent[V],dist[V],found[V];
	mem(parent,-1,sizeof(parent));
	mem(found,0,sizeof(found));
	for(i=0;i<V;i++)
		dist[i]=MAX;
	cin>>s;//source vertex
	dist[s]=0;int vnear=s,min;
	for(i=1;i<=V;i++)
	{
		min=INT_MAX;
		for(j=0;j<V;j++)
		{
			if(found[j]==0&&dist[j]<min)
			{
				min=dist[j];
				vnear=j;
			}
		}
		//vnear is the new vertex whose shortest distance froms s is found
		//dist[j]=curr shortest dist from s
		found[vnear]=1;
		for(j=0;j<V;j++)
		{
			if(dist[vnear]+adj[vnear][j]<dist[j])
			{
				dist[j]=dist[vnear]+adj[vnear][j];
				parent[j]=vnear;
			}
		}
	}	
	//print all shortest paths and distance
	stack<int> path;
	for(i=0;i<V;i++)
	{
		j=i;
		while(parent[j]!=-1)
		{
			path.push(j);
			j=parent[j];
		}
		cout<<i<<"="<<dist[i]<<'\n';
		cout<<j;
		while(!path.empty())
		{
			j=path.top();
			path.pop();
			cout<<"->"<<j;
		}
		cout<<'\n';
	}
	return 0;
}