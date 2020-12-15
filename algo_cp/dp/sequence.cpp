/*
Given 2 strings A and B,gap penalty and mismatch penalty
find minimum penalty
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
	string A,B;
	int i,j,k,m,n,pg,pm;//gp=gap penalty,mp=mismatch
	cin>>m>>n>>pg>>pm;
	cin>>A;
	cin>>B;
	int dp[m+1][n+1];
	dp[0][0]=0;
	for(i=1;i<=n;i++)
		dp[0][i]=pg*i;
	for(i=1;i<=m;i++)
		dp[i][0]=pg*i;
	for(i=1;i<=m;i++)
	{
		for(j=1;j<=n;j++)
		{
			if(A[i-1]==B[j-1])//dp[i-1][j] means ith matches a gap, so A[1...i-1] must align with B[1....j]
				dp[i][j]=min(dp[i-1][j-1],min(dp[i-1][j]+pg,dp[i][j-1]+pg));
			else
				dp[i][j]=min(dp[i-1][j-1]+pm,min(dp[i-1][j]+pg,dp[i][j-1]+pg));
		}
	}
	cout<<dp[m][n]<<'\n';
	int l=max(m,n);
	stack<char> X,Y;
	i=m;j=n;
	while(l--)
	{
		if(dp[i][j]==dp[i-1][j-1]||dp[i][j]==dp[i-1][j-1]+pm)
		{
			X.push(A[i-1]);
			Y.push(B[j-1]);
			i=i-1;j=j-1;
		}
		else if(dp[i][j]==dp[i-1][j]+pg)
		{
			X.push(A[i-1]);
			Y.push(' ');
			i=i-1;
		}
		else
		{
			X.push(' ');
			Y.push(B[j-1]);
			j=j-1;
		}
	}
	while(!X.empty())
	{
		cout<<X.top();
		X.pop();
	}
	cout<<'\n';
	while(!Y.empty())
	{
		cout<<Y.top();
		Y.pop();
	}
	cout<<'\n';
	return 0;
}