/*
find minimum spanninng tree using Kruskal's algorithm
Algo:
Sort edges in increasing order of weight
Pick each edge
check if its 2 vertices are in same set
if in same set discard
else include this edge and union the 2 vertices
TIME COMPLEXITY=>O(Elog(V))
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
#define ipair pair<int,int>
typedef struct edge{
	int f,t;
}edge;
typedef struct subset{
	int parent;
	int rank;
}subset;
int Find(subset sets[],int i)
{
	if(sets[i].parent!=i)
		sets[i].parent=Find(sets,sets[i].parent);
	return sets[i].parent;
}
void Union(subset sets[],int x,int y)
{
	int px=Find(sets,x);
	int py=Find(sets,y);
	if(sets[px].rank<sets[py].rank)
		sets[px].parent=py;
	else if(sets[py].rank<sets[px].rank)
		sets[py].parent=px;
	else
	{
		sets[py].parent=px;
		sets[px].rank++;
	}
}
void Make(subset sets[],int n)
{
	for(int i=0;i<n;i++)
	{
		sets[i].parent=i;
		sets[i].rank=0;
	}
}
bool compare(pair<edge,int> e1,pair<edge,int> e2)
{
	return e1.ss<=e2.ss;
}
int main()
{
	int V,E,i,j,u,v,w;
	cin>>V>>E;
	vector<pair<edge,int>> edges;
	for(i=0;i<E;i++)
	{
		cin>>u>>v>>w;
		edge e;
		e.f=u;e.t=v;
		edges.pb(mp(e,w));
	}
	subset* sets=(subset*)malloc(V*sizeof(subset));
	Make(sets,V);
	sort(edges.begin(),edges.end(),compare);
	vector<pair<edge,int>> MST;
	for(auto it=edges.begin();it!=edges.end();it++)
	{
		edge ed=it->ff;
		int x=Find(sets,ed.f);
		int y=Find(sets,ed.t);
		if(x!=y)
		{
			MST.pb(mp(ed,it->ss));
			Union(sets,x,y);
		}
	}
	int wt=0;
	for(auto it=MST.begin();it!=MST.end();it++)
	{
		edge ed=it->ff;
		w=it->ss;
		cout<<ed.f<<"--"<<w<<"--"<<ed.t<<'\n';
		wt+=w;
	}
	cout<<wt<<'\n';
}