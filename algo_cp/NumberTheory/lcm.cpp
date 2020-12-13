/*LCM USING EUCLIDEAN GCD
RUNNING TIME = O(log(min(a,b)))
lcm=(a*b)/gcd*/
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

int gcd(int a,int b)
{
	if(b==0)
		return a;
	return gcd(b,a%b);
}

int lcm(int a,int b)
{
	return (a*b)/gcd(a,b);
}

int main()
{
	int a,b;
	cin>>a>>b;
	cout<<lcm(a,b)<<'\n';
	return 0;
}