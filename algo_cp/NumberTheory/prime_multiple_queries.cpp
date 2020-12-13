/*given n numbers find prime factorization of every number
If we try to find prime factorization of every number it will take O(nsqrt(n)) time
So we initially store the smallest prime factor of each number(SPF)
Algo for SPF:
	1. initiliaze SPF[i]=i for each number
	2. perform sieve of erastothenis
	3. while running inner loop for a prime number, mark SPF of all those numbers as i
This takes O(nlog(logn)) time
then for any number x, output SPF[x] and recursively call factorize(x/SPF[x]
In worst case consider every time SPF is 2, so this takes O(logx) time
if MAXN = n
then worst case time complexity = O(nlog(logn)) + n*O(logn)
							    = O(nlogn)
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
#define mod 1000000007
#define MAX 100000
int SPF[MAX+1];
void sieve()
{
	int i,j;
	for(i=1;i<=MAX;i++)
		SPF[i]=i;
	for(i=2;i*i<=MAX;i++)
	{
		if(SPF[i]==i)
		{
			for(j=i*i;j<=MAX;j+=i)
			{
				if(SPF[j]==j)
					SPF[j]=i;
			}
		}
	}
}

void factorize(int x)
{
	if(x==1)
	{
		cout<<'\n';
		return;
	}
	cout<<SPF[x]<<' ';
	factorize(x/SPF[x]);
}

int main()
{
	int q,n,i,j;
	sieve();
	cin>>q;
	while(q--)
	{
		cin>>i;
		factorize(i);
	}
	return 0;
}

