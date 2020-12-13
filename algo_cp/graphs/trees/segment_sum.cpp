/*
Given an initial array of n nos
We have to answer q queries
queries of 2 types:
1. update an array element
2. output sum of a given range of array

Segment tree is a full binary tree
Leaf nodes are array elements
n leaf nodes, so n-1 internal nodes so 2n-1 total nodes
(leaving dummy nodes)
each internal node represents sum of certain array range
size of segment tree array=2*2^(ceil(lo2(n)))-1=O(n)

TIME COMPLEXITIES=>
1. construct=> O(n)
2. update=>O(logn)
3. sum of range=>O(logn)
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
#define ff first
#define ss second
#define ipair pair<int,int>
int constructUtil(int arr[],int l,int r,int *st,int i)
{
	if(l==r)
		st[i]=arr[l];
	else
	{
		int mid=(l+r)/2;
		st[i]=constructUtil(arr,l,mid,st,2*i+1)+constructUtil(arr,mid+1,r,st,2*i+2);
	}
	return st[i];
}
int* construct(int arr[],int n)
{
	int x=(int)ceil(log2(n));
	int size=2*(int)pow(2,x)-1;
	int *st=new int[size];
	constructUtil(arr,0,n-1,st,0);
	return st;
}
int getSumUtil(int *st,int tl,int tr,int l,int r,int i)
{
	if(l>tr||r<tl)
		return 0;
	if(tl>=l&&tr<=r)
		return st[i];
	int mid=(tl+tr)/2;
	return getSumUtil(st,tl,mid,l,r,2*i+1)+getSumUtil(st,mid+1,tr,l,r,2*i+2);
}
int getSum(int* st,int n,int l,int r)
{
	if(l<0||r>=n||l>r)
		return -1;
	return getSumUtil(st,0,n-1,l,r,0);
}
void updateUtil(int* st,int l,int r,int i,int si,int diff)
{
	if(i<l||i>r)
		return;
	st[si]+=diff;
	if(l==r)
		return;
	int mid=(l+r)/2;
	updateUtil(st,l,mid,i,2*si+1,diff);
	updateUtil(st,mid+1,r,i,2*si+2,diff);
}
void update(int arr[],int *st,int n,int i,int val)
{
	if(i<0||i>=n)
		return;
	int diff=val-arr[i];
	arr[i]=val;
	updateUtil(st,0,n-1,i,0,diff);
}
int main()
{
	int n,q,i,j,k,l;
	cin>>n>>q;
	int arr[n];
	for(i=0;i<n;i++)
		cin>>arr[i];
	int* st=construct(arr,n);
	for(i=0;i<q;i++)
	{
		cin>>j>>k>>l;
		if(j==1)
			cout<<getSum(st,n,k,l)<<'\n';
		else
			update(arr,st,n,k,l);
	}
	return 0;
}