/*calculate x^y mod p
time complexity = O(logy)*/
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

ll pow(ll x,ull y)
{
	ll res = 1;
	if(x>mod)
		x=x&mod;
	while(y>0)
	{
		if(y&1)
			res=(res*x)%mod;
		y=y>>1;
		x=(x*x)%mod;
	}
	return res;
}

int main()
{
	ll x;ull y;
	cin>>x>>y;
	cout<<pow(x,y)<<'\n';
	return 0;
}