/*EUCLIDEAN GCD
RUNNING TIME = O(log(min(a,b)))
also returns x,y such that ax+by = gcd*/
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
	*y = x1 - (a/b)*y1;
	return g;
}

int main()
{
	int a,b;
	cin>>a>>b;
	int x,y;
	cout<<gcd(a,b,&x,&y)<<'\n';
	cout<<x<<' '<<y<<'\n';
	return 0;
}