/*
->ALL PAIRS SHORTEST PATH
->FOR NON_NEGATIVE WEIGHTS
->BOTH DIRECTED AND UNDIRECTED
->TIME COMPLEXITY=>O(V^3)
->DYNAMIC PROGRAMMING
Algorithm:
Initialize D to adj
run loop V times
at each stage k compute shortest path from i to j using
intermediate vertices from 1 to k only
i--(1tok-1)---->k---(1tok-1)------>j
D[i][j]=min(D[i][j](i.e. using only 1 to k-1 vertices as intermediate)
			, D[i][k]+D[k][j])
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
#define COL 500
#define ROW 500
#define ll long long int
#define ull unsigned long long int
#define mp make_pair
#define pb push_back
#define mem memset
#define inf 1e18
#define mod 1000000007
#define MAX 100000
void printPath(int p[][COL],int u,int v)
{
	vector<int> path;
	if(p[u][v]==-1)
		return;
	path.pb(u);
	while(u!=v)
	{
		u=p[u][v];
		path.pb(u);
	}
	for(auto i:path)
		cout<<i<<' ';
	cout<<'\n';
}
int main()
{
	int V,E,i,j,u,v,w,k;
	cin>>V>>E;
	ll adj[V][V];
	int p[V][COL];
	for(i=0;i<V;i++)
	{
		for(j=0;j<V;j++)
		{
			adj[i][j]=INT_MAX;
			p[i][j]=-1;
		}
		adj[i][i]=0;
		p[i][i]=i;
	}
	for(i=0;i<E;i++)
	{
		cin>>u>>v>>w;
		adj[u][v]=w;
		p[u][v]=v;
	}
	ll D[V][V];
	for(i=0;i<V;i++)
		for(j=0;j<V;j++)
			D[i][j]=adj[i][j];
	for(k=0;k<V;k++)
	{
		for(i=0;i<V;i++)
		{
			for(j=0;j<V;j++)
			{
				if(D[i][k]!=INT_MAX&&D[k][j]!=INT_MAX&&D[i][k]+D[k][j]<D[i][j])
				{
					D[i][j]=D[i][k]+D[k][j];
					p[i][j]=p[i][k];
				}
			}
		}
	}
	for(i=0;i<V;i++)
	{
		for(j=0;j<V;j++)
			cout<<D[i][j]<<' ';
		cout<<'\n';
	}
	int from,to;
	cin>>from>>to;
	printPath(p,from,to);
}