/*Compute Cn
RECURSIVE FORMULATION
Cn+1 = summation from i=0 to n Ci*Cn-i
C0=C1=1
TIME COMPLEXITY = O(n2)
SPACE COMPLEXITY=O(n)
USE OF CATALAN NUMBERS:
1. No of balanced paranthesization using n pairs of ()
2. No of ways to go from (0,0) to (n,n) in a grid without crossing diagonal
3. No of BSTs with n keys
4. No of fully binary trees with n+1 leaves
5. No of ways to draw n non-intersecting chords given 2n points on a circle
6. No of ways a convex polygon of n+2 sides can split into triangles by connecting vertices*/

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
	int n,i,j;
	cin>>n;
	int C[n+1];
	C[0]=C[1]=1;
	for(i=2;i<=n;i++)
	{
		int sum=0;
		for(j=0;j<i;j++)
			sum+=(C[j]*C[i-1-j]);
		C[i]=sum;
	}
	cout<<C[n]<<'\n';
	return 0;
}