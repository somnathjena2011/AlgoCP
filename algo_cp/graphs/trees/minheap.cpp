/*
1. Complete binary tree
2. root key<children's keys and true for its subtree
TIME COMPLEXITIES=>
1. ExtractMin=>O(logn)
2. DecreaseKey=>O(logn)
3. Insertion=>O(logn)
4. Deletion=>O(logn)
5. findMin=>O(1)
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
#define COL 500
#define ROW 500
#define ll long long int
#define ull unsigned long long int
#define mp make_pair
#define pb push_back
#define mem memset
#define inf 1e18
#define mod 1000000007
class MinHeap
{
public:
	int cap;
	int size=0;
	int *heap;
	MinHeap(int cap)
	{
		this->cap=cap;
		this->heap=(int*)malloc(cap*sizeof(int));
		this->size=0;
	}
	void insert(int key);
	void del(int i);
	void decrease(int i,int val);
	int extractMin();
	int findMin();
	void heapify(int i);
	int left(int i){ return 2*i+1; }
	int right(int i){ return 2*i+2; }
	int parent(int i){ return (i-1)/2; }
	void print()
	{
		for(int i=0;i<size;i++)
			cout<<heap[i]<<' ';
		cout<<'\n';
	}
};

void swap(int *x,int *y)
{
	int t=*x;
	*x=*y;
	*y=t;
}

int MinHeap::findMin()
{
	if(size>0)
		return heap[0];
	return INT_MAX;
}

void MinHeap::insert(int key)
{
	if(size==cap)
		return;
	size++;
	heap[size-1]=key;
	int i=size-1;
	while(i!=0&&heap[i]<heap[parent(i)])
	{
		swap(&heap[i],&heap[parent(i)]);
		i=parent(i);
	}
}

void MinHeap::heapify(int i)
{
	if(i>=size||i<0)
		return;
	int l=left(i);
	int r=right(i);
	int smallest = i;
	if(l<size&&heap[l]<heap[i])
		smallest=l;
	if(r<size&&heap[r]<heap[smallest])
		smallest=r;
	if(smallest!=i)
	{
		swap(&heap[i],&heap[smallest]);
		heapify(smallest);
	}
}

int MinHeap::extractMin()
{
	if(size==0)
		return INT_MAX;
	if(size==1)
	{
		int ans=heap[0];
		size--;
		return ans;
	}
	int ans=heap[0];
	heap[0]=heap[size-1];
	size--;
	heapify(0);
	return ans;
}

void MinHeap::decrease(int i,int val)
{
	if(i==0)
	{
		heap[i]=val;
		return;
	}
	if(i<0||i>=size)
		return;
	heap[i]=val;
	while(i!=0&&heap[i]<heap[parent(i)])
	{
		swap(&heap[i],&heap[parent(i)]);
		i=parent(i);
	}
}

void MinHeap::del(int i)
{
	decrease(i,INT_MIN);
	extractMin();
}



int main()
{
	MinHeap* h=new MinHeap(11);
	h->insert(3);
	h->insert(2);
	h->insert(1);
	h->insert(15);
	h->insert(5);
	h->insert(4);
	h->insert(45);
	h->print();
	cout<<h->extractMin()<<'\n';
	cout<<h->findMin()<<'\n';
	h->decrease(2,1);
	h->print();
	return 0;
}