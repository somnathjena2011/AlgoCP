/*
Disjoint set using union by Rank
and find by Path compression
TIME COMPLEXITIES of Union and find
=O(logn)
Find(sets[],int i)
{
	//When finding parent of a node, for all nodes
	//in the path from that node to the root
	//make parent as the root node
	//Rank doesn't change here as rank doesn't represent height only
	if(sets[i].parent!=i)
	sets[i].parent=find(sets,sets[i].parent);
	return sets[i].parent;
}
Union(sets[],int x,int y)
{
	int px=find(sets,x);
	int py=find(sets,y);
	if(sets[px].rank<sets[py].rank)
	sets[px].parent=py;
	else if(sets[py].rank<sets[px].rank)
	sets[py].parent=px;
	else
	{
		sets[px].parent=py;
		sets[py].rank++;
	}
}
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
typedef struct subset{
	int parent;
	int rank;
}subset;
int find(subset sets[],int i)
{
	if(sets[i].parent!=i)
		sets[i].parent=find(sets,sets[i].parent);
	return sets[i].parent;
}
void Union(subset sets[],int x,int y)
{
	int px=find(sets,x);
	int py=find(sets,y);
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
void make(subset sets[],int n)
{
	for(int i=0;i<n;i++)
	{
		sets[i].parent=i;
		sets[i].rank=0;
	}
}
//Algorithm to detect cycle in undirected graph
//For each edge find sets of the 2 nodes
//if different sets union them
//else cycle detected

//Path compression leads to a constant
//amortized time complexity of union and find
int isCycle(vector<ipair> edges,int n)
{
	subset* sets=(subset*)malloc(n*sizeof(subset));
	make(sets,n);
	for(auto edge:edges)
	{
		int x=find(sets,edge.ff);
		int y=find(sets,edge.ss);
		if(x==y)
			return 1;
		Union(sets,x,y);
	}
	return 0;
}
int main()
{
	int V,E,u,v;
	cin>>V>>E;
	vector<ipair> edges;
	for(int i=0;i<E;i++)
	{
		cin>>u>>v;
		edges.pb(mp(u,v));
	}
	cout<<isCycle(edges,V)<<'\n';
	return 0;
}