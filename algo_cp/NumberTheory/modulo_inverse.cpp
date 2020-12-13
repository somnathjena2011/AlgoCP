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

ALGORITHM
ax+my=1 for some x and y [FROM EUCLIDEAN GCD, as gcd =1]
(ax+my)%m=ax%m=1=> ax=1modm

TIME COMPLEXITY=O(log(min(a,m))*/

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

int gcd(int a,int b,int *x,int *y)
{
	if(b==0)
	{
		*x=1;*y=0;
		return a;
	}
	int x1,y1;
	int g = gcd(b,a%b,&x1,&y1);
	*x = y1;
	*y = x1-(a/b)*y1;
	return g;
}

int moduloInverse(int a,int m)
{
	int x,y,g;
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
	int a,m;
	cin>>a>>m;
	cout<<moduloInverse(a,m)<<'\n';
	return 0;
}