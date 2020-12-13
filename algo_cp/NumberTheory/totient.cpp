/*
phi(n) = n*product (1-1/p) of all p where p|n and p is prime
TIME COMPLEXITY = O(sqrt(n))

EULER"S TOTIENT FUNCTIONS PROPERTIES:
1) For a prime number p, Φ(p) is p-1. For example Φ(5) is 4, Φ(7) is 6 and Φ(13) is 12. This is obvious, gcd of all numbers from 1 to p-1 will be 1 because p is a prime.
2) For two numbers a and b, if gcd(a, b) is 1, then Φ(ab) = Φ(a) * Φ(b). For example Φ(5) is 4 and Φ(6) is 2, so Φ(30) must be 8 as 5 and 6 are relatively prime. 
3) For any two prime numbers p and q, Φ(pq) = (p-1)*(q-1). This property is used in RSA algorithm. 
4) If p is a prime number, then Φ(p^k) = p^k – p^(k-1). This can be proved using Euler’s product formula.
5) Sum of values of totient functions of all divisors of n is equal to n. 
For example, n = 6, the divisors of n are 1, 2, 3 and 6. According to Gauss, sum of Φ(1) + Φ(2) + Φ(3) + Φ(6) should be 6. We can verify the same by putting values, we get (1 + 1 + 2 + 2) = 6.
6) The most famous and important feature is expressed in Euler’s theorem : 

The theorem states that if n and a are coprime
(or relatively prime) positive integers, then

aΦ(n) = 1 (mod n) 

The RSA cryptosystem is based on this theorem:
In the particular case when m is prime say p, Euler’s theorem turns into the so-called Fermat’s little theorem : 

ap-1 = 1 (mod p) 

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

int euler_totient(int n)
{
	int res=n;
	for(int i=2;i*i<=n;i++)
	{
		if(n%i==0)
		{
			while(n%i==0)
			{
				n/=i;
			}
			res = res*(i-1)/i;
			//cout<<"i= "<<i<<"res= "<<res<<'\n';
		}
	}
	if(n>1)
		res = res*(n-1)/n;
	return res;
}

int main()
{
	int n;
	cin>>n;
	cout<<euler_totient(n)<<'\n';
	return 0;
}