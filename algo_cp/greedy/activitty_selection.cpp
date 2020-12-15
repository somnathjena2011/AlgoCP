/*
Given n activities their start times and finish times
Pick maximum no of activities which do not
intersect with each other
GREEDY=>
Sort activities as per their finish times
for each activity:
	if the start time>=last finish time
	include it and update finish time
Proof of optimality=>
G=>greedy soln
O=>Optimal sol
|G|=m, |O|=n ,n>=m
G=g1,g2,g3,...gk,....gm
O=o1,o2,......ok,........on
say they differ first time at kth interval
finish time of gk<=finish time of ok (by structure of greedy algo)
so we can exchange gk and ok and optimal solution does not worsen
we do this for every differing intervals in o
finally O=g1,g2,.....gm,....on
But after gm if there are more intervals our greedy algo would have choosen them
so |O|=|G|=m

TIME COMPLEXITY=>O(nlogn) if sorting required
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
bool compare(pair<int,int> p1,pair<int,int> p2)
{
	return p1.ss<p2.ss;
}
int main()
{
	int n,i,u,v,last;
	cin>>n;
	pair<int,int> j[n];
	for(i=0;i<n;i++)
	{
		cin>>u>>v;
		j[i].ff=u;j[i].ss=v;
		//cin>>j[i].ff>>j[i].ss;
	}
	sort(j,j+n,compare);
	last=-1;int ans=0;
	for(i=0;i<n;i++)
	{
		if(j[i].ff>=last)
		{
			++ans;
			last=j[i].ss;
		}
	}
	cout<<ans<<'\n';
	return 0;
}