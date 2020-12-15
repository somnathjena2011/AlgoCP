/*
Given infinite supply of coins C1,C2,...Cn
find total no of ways to make a change of Rs V
Soln=>DP
dp[i][j]=no of ways to make a change of j
using coins from 1 to i
dp[i][j]=dp[i][j-c[i]]+dp[i-1][j]
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
int main()
{
	int n,v,i,j;
	cin>>n>>v;
	int c[n+1];
	for(i=1;i<=n;i++)
		cin>>c[i];
	int dp[n+1][v+1];
	for(i=0;i<=n;i++)
		for(j=0;j<=v;j++)
			dp[i][j]=0;
	dp[0][0]=1;
	for(i=1;i<=n;i++)
		dp[i][0]=1;
	for(i=1;i*c[1]<=v;i++)
		dp[1][i*c[1]]=1;
	for(i=2;i<=n;i++)
	{
		for(j=1;j<=v;j++)
		{
			if(c[i]<=j)
				dp[i][j]=dp[i-1][j]+dp[i][j-c[i]];
			else
				dp[i][j]=dp[i-1][j];
		}
	}
	cout<<dp[n][v]<<'\n';
	return 0;
}