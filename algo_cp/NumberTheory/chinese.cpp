/*
Find x such that
x=r1modm1
x=r2modm2
...
x=rnmodmn
given r1,r2,...rn and m1,m2,...mn, all ms are mutually coprime
ALGORITHM:
Find M=m1*m2*...mn
For all i find Mi=M/mi
FOr all i find modInv(Mi) wrt mi
x = (sum over all i ri*Mi*modInv(Mi))%M

Reason to take %M:
ith term in x is say ti
ti%mj=0 for j!=i as ti contains Mi and Mi has all mj except mi
ti%mi=(bi*(Mi*modInv(Mi)))%mi
     =(bi*1)%mi=bi
Now on adding or subtracting M does not matter as (x+M)%mi=x%mi
So we take smallest x which is the sum term modulo M*/
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
int gcd(int a,int b,int *x,int *y)
{
	if(b==0)
	{
		*x=1;
		*y=0;
		return a;
	}
	int x1,y1;
	int g = gcd(b,a%b,&x1,&y1);
	*x = y1;
	*y = x1-(a/b)*y1;
	return g;
}
int modInv(int a,int m)
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
int chinese(int r[],int m[],int n)
{
	int x=0,i;
	int M[n];
	int prod=1;
	for(i=0;i<n;i++)
		prod*=m[i];
	for(i=0;i<n;i++)
		M[i]=prod/m[i];
	for(i=0;i<n;i++)
		x=(x+((r[i]%prod)*((M[i]%prod)*(modInv(M[i],m[i])%prod))%prod)%prod)%prod;
	return x;
}
int main()
{
	int n,i,j;
	cin>>n;
	int m[n],r[n];
	for(i=0;i<n;i++)
		cin>>r[i]>>m[i];
	j=chinese(r,m,n);
	cout<<j<<'\n';
	return 0;
}