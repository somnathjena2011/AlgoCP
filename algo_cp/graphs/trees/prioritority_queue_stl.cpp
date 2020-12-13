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
	priority_queue<int,vector<int>,greater<int>> pq;
	//syntax for minheap above
	pq.push(10);
	pq.push(30);
	pq.push(20);
	pq.push(5);
	pq.push(1);
	pq.push(10);
	while(!pq.empty())
	{
		cout<<pq.top()<<' ';
		pq.pop();
	}
	cout<<'\n';
	return 0;
}