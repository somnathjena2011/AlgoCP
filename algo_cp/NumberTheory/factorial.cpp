/*factorial using loop
Time complexity= O(n)*/
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
	ull n,i;
	cin>>n;
	ull fact=1;
	for(i=1;i<=n;i++)
	{
		fact=((fact%mod)*i)%mod;
	}
	cout<<fact<<'\n';
	return 0;
}