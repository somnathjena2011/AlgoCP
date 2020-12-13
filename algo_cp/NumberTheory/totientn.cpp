/*compute euler totient for all numbers <=n
TIME COMPLEXITY != O(nlog(log(n))*/
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
int totient(int a[],int n)
{
	int i,j;
	for(i=0;i<=n;i++)
		a[i]=i;
	for(i=2;i<=n;i++)
	{
		if(a[i]==i)
		{
			a[i]=i-1;
			for(j=2*i;j<=n;j+=i)
				a[j]=(a[j]/i)*(i-1);
		}
	}
}
int main()
{
	int n;
	cin>>n;
	int a[n+1];
	totient(a,n);
	for(int i=1;i<=n;i++)
		cout<<a[i]<<' ';
	cout<<'\n';
	return 0;
}