/*
Given infinite supply of coins C1,C2,...Cn
find minimum no of coins to make a change of Rs V
Greedy fails=>
Ex. V=50, C=[40,30,20,5]
By greedy we pick 40,5,5
But one ans is 30,20
Soln=>DP
dp[i][j]=min coins needed to make a change of j
using coins from 1 to i
dp[i][j]=min(dp[i][j-C[i]],dp[i-1][j])//if j>=C[i]
        =dp[i-1][j] otherwise
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
			dp[i][j]=INT_MAX;
	for(i=1;i<=v;i++)
		dp[0][i]=INT_MAX;
	for(i=0;i<=n;i++)
		dp[i][0]=0;
	for(i=1;i*c[1]<=v;i++)
		dp[1][i*c[1]]=i;
	for(i=2;i<=n;i++)
	{
		for(j=1;j<=v;j++)
		{
			if(c[i]<=j)
			{
				if(dp[i][j-c[i]]!=INT_MAX)
					dp[i][j]=min(1+dp[i][j-c[i]],dp[i-1][j]);
				else
					dp[i][j]=dp[i-1][j];
			}
			else
				dp[i][j]=dp[i-1][j];
		}
	}
	cout<<dp[n][v]<<'\n';
	return 0;
}