/*DP approach
nCk = (n-1)C(k-1)+(n-1)Ck

TIME= O(nk)
SPACE=O(k)*/
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

int nck(int n,int k)
{
	int dp[k+1];
	mem(dp,0,sizeof(dp));
	dp[0]=1;
	int i,j;
	for(i=1;i<=n;i++)
	{
		for(j=min(i,k);j>0;j--)
		{
			if(i==j)
				dp[j]=1;
			else
				dp[j]=(dp[j-1]+dp[j])%mod;
		}
	}
	return dp[k];
}

int main()
{
	int n,k;
	cin>>n>>k;
	cout<<nck(n,k)<<'\n';
	return 0;
}