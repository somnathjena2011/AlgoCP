/*factorial of large numbers*/
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
int res[MAX];
int multiply(int n,int res[],int res_size)
{
	int carry = 0;
	for(int i=0;i<res_size;i++)
	{
		int prod = res[i]*n + carry;
		res[i] = prod%10;
		carry = prod/10;
	}
	while(carry)
	{
		res[res_size]=carry%10;
		carry/=10;
		res_size++;
	}
	return res_size;
}

void fact(int n)
{
	res[0]=1;
	int res_size = 1;

	for(int i=2;i<=n;i++)
		res_size = multiply(i,res,res_size);
	for(int i=res_size-1;i>=0;i--)
		cout<<res[i];
	cout<<'\n';
}

int main()
{
	int n;
	cin>>n;
	fact(n);
	return 0;
}