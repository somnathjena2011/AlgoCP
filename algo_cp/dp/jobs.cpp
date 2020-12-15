/*
Given n jobs with profit array p,
durations t, and deadlines d
Schedule jobs with maximum profit
such that each job gets completed before its deadline
and no job overlaps with other

TIME COMPLEXITY=>O(nd)+O(nlogn)
d=max deadline
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
typedef struct job{
	int id;
	int profit;
	int duration;
	int deadline;
}job;
bool compare(job j1,job j2)
{
	return j1.deadline<=j2.deadline;
}
void print(int dp[][COL+1],job jobs[],int i,int t)
{
	if(i==0)
		return;
	if(dp[i][t]==dp[i-1][t])
		print(dp,jobs,i-1,t);
	else
	{
		int k=min(t,jobs[i].deadline)-jobs[i].duration;
		print(dp,jobs,i-1,k);
		cout<<jobs[i].id<<"->"<<k<<' ';
	}

}
int main()
{
	int n,i,j,k,d;
	cin>>n;
	int p[n+1],de[n+1],t[n+1];
	d=-1;
	for(i=1;i<=n;i++)
		cin>>p[i];
	for(i=1;i<=n;i++)
	{
		cin>>de[i];
		if(de[i]>d)
			d=de[i];
	}
	for(i=1;i<=n;i++)
		cin>>t[i];
	job jobs[n];
	for(i=1;i<=n;i++)
	{
		jobs[i].id=i;
		jobs[i].profit=p[i];
		jobs[i].deadline=de[i];
		jobs[i].duration=t[i];
	}
	sort(jobs+1,jobs+n+1,compare);
	int dp[n+1][COL+1];
	for(i=0;i<=n;i++)
		for(j=0;j<=d;j++)
			dp[i][j]=0;
	for(i=0;i<=d;i++)
		dp[0][i]=0;
	for(i=0;i<=n;i++)
		dp[i][0]=0;
	/*for(i=0;i<=d;i++)
	{
		if(i<=jobs[1].deadline&&i-jobs[1].duration>=0)
			dp[1][i]=jobs[1].profit;
	}*/
	for(i=1;i<=n;i++)
	{
		for(j=1;j<=d;j++)
		{
			k=min(jobs[i].deadline,j)-jobs[i].duration;
			if(k<0)
				dp[i][j]=dp[i-1][j];
			else
				dp[i][j]=max(dp[i-1][j],jobs[i].profit+dp[i-1][k]);
		}
	}
	cout<<dp[n][d]<<'\n';
	print(dp,jobs,n,d);
	cout<<'\n';
	return 0;
}