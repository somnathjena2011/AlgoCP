/*compute nck%mod using formula nck = n!/(k!*(n-k)!)

n! and k! can be large

so compute n!%m, k!%m, (n-k)!%m, then modulo inverse of k!%m, (n-k)!%m mod m
ans = (((n!%m)*(modInv(k!%m))%m)*modInv((n-k)!%m)))%m

TIME COMPLEXITY = O(n)*/

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

ll gcd(ll a,ll b,ll *x,ll *y)
{
	if(b==0)
	{
		*x=1;*y=0;
		return a;
	}
	ll x1,y1;
	ll g = gcd(b,a%b,&x1,&y1);
	*x = y1;
	*y = x1-(a/b)*y1;
	return g;
}

ll moduloInverse(ll a,ll m)
{
	ll x,y,g;
	g = gcd(a,m,&x,&y);
	if(g!=1)
		return 0;
	else
	{
		x=(x+m)%m;
		return x;
	}
}

int main()
{
	ll n,k,i,j;
	cin>>n>>k;
	ll fact[n+1];
	fact[0]=fact[1]=1;
	for(i=2;i<=n;i++)
		fact[i]=(fact[i-1]*(i%mod))%mod;
	ll nck = (((fact[n]*moduloInverse(fact[k],mod))%mod)*moduloInverse(fact[n-k],mod))%mod;
	cout<<nck<<'\n';
	return 0;
}