/***************ONLY IF M IS PRIME*********************/
/*given a compute inverse of a modulo m
i.e. find x such that
ax=1modm, 0<x<m
This is possible only if gcd(a,m)=1
otherwise ax = gk where g=gcd(a,m) and k is some constant
similarly m = gk' where k' another constant
if ax=1 mod m => gk=1 mod m => gk%m=1
=> gk=mf+1 for some f
=> gk-mf=1
=> gk-gk'f=1
=> g(k-k'f)=1
=> gk"=1, wehre g and k" are integers
This is contradiction
So, for modulo inverse to exist gcd(a,m)=1

ALGORITHM IF m is PRIME
FROM FERMAT'S LITTLE THEOREM:
a^(m-1)=1modm if m is prime
multiply both sides by a^-1
a^(m-2)=a^-1modm 
Hence we use modular exponentiation to find pow(a,m-2)%m

TIME COMPLEXITY = O(logm)
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

ll pow(ll x,ull y,ull m)
{
	ll res=1;
	if(x>m)
		x=x%m;
	while(y>0)
	{
		if(y&1)
			res=(res*x)%m;
		y=y>>1;
		x=(x*x)%m;
	}
	return res;
}

ll moduloInverse(ll a,ll m)
{
	return pow(a,m-2,m);
}

int main()
{
	ll a,m;
	cin>>a>>m;
	cout<<moduloInverse(a,m)<<'\n';
	return 0;
}
