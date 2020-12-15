/*
Given e eggs and f floors, find the min no of trials
in worst case to determine the lowest safe floor

DP=>
dp[i][j]=min trials in worst case with i floors and j eggs
dp[i][j]=min(k=1toi)(max(dp[k-1][j-1],dp[i-k][j])+1)

TIME COMPLEXITY=>O(e*f^2)
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
	int e,f,i,j,k,m;
	cin>>e>>f;
	int dp[f+1][e+1];
	for(i=0;i<=f;i++)
		for(j=0;j<=e;j++)
			dp[i][j]=0;
	for(i=1;i<=f;i++)
	{
		dp[i][1]=i;
		dp[i][0]=INT_MAX-1;
	}
	for(j=1;j<=e;j++)
		dp[1][j]=1;
	for(i=2;i<=f;i++)
	{
		for(j=1;j<=e;j++)
		{
			m=INT_MAX;
			for(k=1;k<=i;k++)
			{
				m=min(m,max(dp[k-1][j-1],dp[i-k][j])+1);
			}
			dp[i][j]=m;
		}
	}
	cout<<dp[f][e]<<'\n';
	return 0;
}