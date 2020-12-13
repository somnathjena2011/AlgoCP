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
void BFS(vector<int> g[],int v,int s)
{
	int visited[v];
	queue<int> q;
	mem(visited,0,sizeof(visited));
	visited[s]=1;
	q.push(s);
	while(!q.empty())
	{
		int u=q.front();
		cout<<u<<' ';
		q.pop();
		for(auto i:g[u])
		{
			if(!visited[i])
			{
				visited[i]=1;
				q.push(i);
			}
		}
	}
}

int main()
{
	int v,e,i,j,k;
	cin>>v>>e;
	vector<int> g[v];
	for(i=0;i<e;i++)
	{
		cin>>j>>k;
		g[j].pb(k);
	}
	BFS(g,v,2);
	return 0;
}