/*
->SINGLE SOURCE SHORTEST PATH
->BOTH FOR UNDIRECTED AND DIRECTED GRAPHS
->GREEDY ALGORITHM
->ONLY NON_NEGATIVE WEIGHTS
->CAN BE IMPLEMENTED USING BINARY MIN HEAP(priority queue)
Algo:
Maintain 2 sets S and V-S, S contains vertices whose
shortest distance from s has been found
Update shortest distance of vertices from V-S

TIME COMPLEXITY=>O(Elog(V))
How?=>
//Maximum size of priority queue is E,
as for each vertex we keep it in the queue along with its dist
for each vertex
	extractMin for vertex with min distance=>O(logV)
	update vnear
	for all edges of vnear
	decreaseKey if necessary
	(This step is performed total of no of edges times
	in total running of the outer for loop)
	Hence time complexity=>O(Elog(E))=O(Elog(V))
decreaseKey step=>
if we define our own minHeap, then also to search for each vertex takes O(size of heap)
hence not optimized
So, we insert in the heap same vertex with decreased distance

Max size of heap can grow to V^2
But O(log(V^2))=O(log(V))
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
typedef pair<ll,ll> ipair;

int main()
{
	ll V,E,i,u,v,j,vnear,w,s,k;
	cin>>V>>E;
	vector<ipair> adj[V];
	for(i=0;i<E;i++)
	{
		cin>>u>>v>>w;
		adj[u].pb(mp(v,w));
		adj[v].pb(mp(u,w));
		//HERE DONE FOR UNDIRECTED GRAPHS
	}
	//here our priority queue element will be pair<weight,vertex>
	ll found[V],dist[V],parent[V];
	mem(found,0,sizeof(found));
	mem(parent,-1,sizeof(parent));
	for(i=0;i<V;i++)
		dist[i]=INT_MAX;
	cin>>s;
	dist[s]=0;
	//syntax for minHeap
	priority_queue<ipair,vector<ipair>,greater<ipair>> pq;
	for(i=0;i<V;i++)
	{
		if(i==s)
			pq.push(mp(0,s));
		else
			pq.push(mp(INT_MAX,i));
	}
	//run for V times
	for(i=0;i<V;i++)
	{
		//extractMin
		ipair ip=pq.top();
		pq.pop();
		vnear=ip.ss;
		w=ip.ff;
		found[vnear]=1;
		for(auto it=adj[vnear].begin();it!=adj[vnear].end();it++)
		{
			j=it->ff;
			k=it->ss;
			if(!found[j]&&dist[j]>k+dist[vnear])
			{
				dist[j]=k+dist[vnear];
				pq.push(mp(dist[j],j));
				parent[j]=vnear;
			}
		}
	}
	for(i=0;i<V;i++)
		cout<<dist[i]<<' ';
	cout<<'\n';
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