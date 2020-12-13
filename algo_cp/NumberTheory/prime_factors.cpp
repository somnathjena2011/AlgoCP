/*all prime factors of a number
like for 12 = 2,2,3
loop run till sqrt(n)
Time complexity = O(sqrt(n))*/
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
#define MAX 500

int primeFactors(int n,vector<int>& factors)
{
	int times = 1;
	while(n%2==0)
	{
		factors.pb(2);
		n/=2;
		++times;
	}
	for(int i=3;i*i<=n;i+=2)
	{
		++times;
		while(n%i==0)
		{
			factors.pb(i);
			n/=i;
			++times;
		}
	}
	if(n>2)
		factors.pb(n);
	return times+1;
}

int main()
{
	vector<int> factors[100001];
	int running_times[100001];
	running_times[1]=running_times[0]=1;
	for(int i=2;i<=100000;i++)
	{
		running_times[i]=primeFactors(i,factors[i]);
	}
	freopen("primeFactors.txt","w",stdout);
	for(int i=2;i<=100000;i++)
	{
		cout<<running_times[i]<<", ";
	}
	cout<<'\n';
	return 0;
}