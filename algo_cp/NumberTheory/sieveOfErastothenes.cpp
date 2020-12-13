/*all primes less than n
time complexity = O(nlog(log(n))*/
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

void sieve(int n)
{
	int prime[n+1];
	mem(prime,1,sizeof(prime));
	prime[0]=prime[1]=0;
	for(int i=2;i*i<=n;i++)
	{
		if(prime[i])
		{
			for(int j=i*i;j<=n;j+=i)
				prime[j]=0;
		}
	}
	for(int i=1;i<=n;i++)
	{
		if(prime[i])
			cout<<i<<' ';
	}
	cout<<'\n';
}

int main()
{
	int n;
	cin>>n;
	sieve(n);
}