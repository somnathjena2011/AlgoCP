/*
ADJACENCY LIST REPRESENTATION OF GRAPHS
ADD EDGE=> O(1)
REMOVE EDGE=>O(1)
INITIALIZING=>O(N)
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

void addEdge(vector<int> g[],int u,int v)
{
	g[u].pb(v);
	g[v].pb(u);
}

int main()
{
	int ve,e,i,u,v;
	cin>>ve>>e;
	vector<int> g[ve];
	for(i=0;i<e;i++)
	{
		cin>>u>>v;
		addEdge(g,u,v);
	}
	for(i=0;i<ve;i++)
	{
		cout<<i;
		for(auto j:g[i])
			cout<<"->"<<j;
		cout<<'\n';
	}
	return 0;
}