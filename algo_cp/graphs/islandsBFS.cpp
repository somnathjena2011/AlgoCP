/*
given a 2d grid of 1s and 0s
find no of islands of 1s
can move up,down,left,right or diagonally

BFS in GRID
TIME COMPLEXITY=>O(ROW*COL)
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
#define COL 1000
#define ROW 1000
#define ll long long int
#define ull unsigned long long int
#define mp make_pair
#define pb push_back
#define mem memset
#define inf 1e18
#define mod 1000000007
int diri[] = {-1,-1,-1,0,1,1,1,0};
int dirj[] = {-1,0,1,1,1,0,-1,-1};
int isSafe(int i,int j,int row,int col)
{
	if(i>=0&&i<row&&j>=0&&j<col)
		return 1;
	return 0;
}
void bfs(int G[][COL],int x,int y,int row,int col,int visited[][COL])
{
	queue<pair<int,int>> q;
	q.push(mp(x,y));
	int i,j,k;
	visited[x][y]=1;
	while(!q.empty())
	{
		pair<int,int> p=q.front();
		i=p.first;j=p.second;
		q.pop();
		for(k=0;k<8;k++)
		{
			int newx=i+diri[k];
			int newy=j+dirj[k];
			if(isSafe(newx,newy,row,col)&&!visited[newx][newy]&&G[newx][newy]==1)
			{
				q.push(mp(newx,newy));
				visited[newx][newy]=1;
			}
		}
	}
}
int main()
{
	int i,j,row,col;
	cin>>row>>col;
	int G[row][COL],visited[row][COL];
	for(i=0;i<row;i++)
	{
		for(j=0;j<col;j++)
		{
			cin>>G[i][j];
			visited[i][j]=0;
		}
	}
	int ans=0;
	for(i=0;i<row;i++)
	{
		for(j=0;j<row;j++)
		{
			if(!visited[i][j]&&G[i][j]==1)
			{
				bfs(G,i,j,row,col,visited);
				++ans;
			}
		}
	}
	cout<<ans<<'\n';
	return 0;
}