/*Given n and prime p of form 4i+3 find x such that x*x%p=n

From EULER"S CRITERION:
if p is prime then it must be odd, so (p-1)/2 must be integer
Now x^2 mod p = n mod p
=> x^(p-1)modp= n^(p-1)/2 mod p [Rasing both sides to the power (p-1)/2]
=> n^(p-1)/2 = 1 mod p [Fermat's Little theorem: x^(p-1)=1modp when p is prime

SO n^(p-1)/2 = 1 mod p [Now multiple y both sides]
=> n^(p+1)/2 = n mod p
=> x^2=n^(p+1)/2modp [if such x exists]
=> x^2=n^(2i+2)modp
=> x=+-n/(p+1)/4 mod p
TIME COMPLEXITY= O(logp)*/
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
int pow(int x,int y,int p)
{
	int res=1;
	x=x%p;
	while(y>0)
	{
		if(y&1)
			res=(res*x)%p;
		y=y>>1;
		x=(x*x)%p;
	}
	return res;
}
//ASSUMING p=4i+3 and prime
int sqrtmod(int n,int p)
{
	int x= pow(n,(p+1)/4,p);
	if((x*x)%p==n%p)
		return x;
	x=(p-x)%p;
	if((x*x)%p==n%p)
		return x;
	return 0;
}
int main()
{
	int n,p;
	cin>>n>>p;
	cout<<sqrtmod(n,p)<<'\n';
	return 0;
}