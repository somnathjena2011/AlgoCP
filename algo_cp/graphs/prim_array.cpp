/*
PRIM'S ALGORITHM TO FIND MINIMUM SPANNING TREE
At each step maintain 2 sets T and V-T
T contains vertices already in MST
Pick the vertex v from V-T with min edge weight from T to V-T
include v in T
TIME COMPLEXITY=>O(V^2)


PROOF OF CORRECTNESS=>
Lemma1: For any set S and V-S, the min-cut edge connecting S & V-S
must be included in MST
Using the Lemma1 and contradiction it can be shown Prim's algo is correct
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
#define ff first
#define ss second
int main()
{
	int V,E,i,j,u,v,k,w,vnear,min;
	cin>>V>>E;
	int adj[V][V];
	for(i=0;i<V;i++)
		for(j=0;j<V;j++)
			adj[i][j]=INT_MAX;
	for(i=0;i<E;i++)
	{
		cin>>u>>v>>w;
		adj[u][v]=w;
		adj[v][u]=w;
	}
	int parent[V],inMST[V],dist[V];
	mem(parent,-1,sizeof(parent));
	mem(inMST,0,sizeof(inMST));
	for(i=0;i<V;i++)
		dist[i]=INT_MAX;
	inMST[0]=0;
	dist[0]=0;
	for(i=1;i<=V-1;i++)
	{
		min=INT_MAX;
		for(j=0;j<V;j++)
		{
			if(inMST[j]==0&&dist[j]<min)
			{
				vnear=j;
				min=dist[j];
			}
		}
		inMST[vnear]=1;
		for(j=0;j<V;j++)
		{
			if(!inMST[j]&&dist[j]>adj[vnear][j])
			{
				parent[j]=vnear;
				dist[j]=adj[vnear][j];
			}
		}
	}
	int minWeight=0;
	for(i=1;i<V;i++)
	{
		cout<<parent[i]<<"--"<<dist[i]<<"--"<<i<<'\n';
		minWeight+=dist[i];
	}
	cout<<minWeight<<'\n';
	return 0;
}