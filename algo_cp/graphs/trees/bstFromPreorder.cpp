/*
Given Preorder traversal of tree
construct BST
TIME COMPLEXITY=>O(n)
ALGORITHM=>
maintain
min,max,preIndex,key
Initialize min=INT_MIN,max=INT_MAX,preIndex=0
key=pre[0]
if(min<=key<=max)
create subtree rooted at node with value key
increment preIndex
recursively call the function for left-subtree
with min=min and max=key
and right-subtree with min=key and max=max
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
typedef struct node{
	int key;
	struct node* left;
	struct node* right;
}node;
node* create(int key)
{
	node* nd = (node*)malloc(sizeof(node));
	nd->key=key;
	nd->left=nd->right=NULL;
	return nd;
}
node* search(node *root,int key)
{
	if(root==NULL)
		return root;
	if(root->key==key)
		return root;
	if(key<root->key)
		return search(root->left,key);
	else
		return search(root->right,key);
}
node *insert(node *root,int key)
{
	if(root==NULL)
		return create(key);
	if(key<root->key)
		root->left=insert(root->left,key);
	else
		root->right=insert(root->right,key);
	return root;
}
node* minNode(node* root)
{
	node* curr=root;
	while(curr&&curr->left)
		curr=curr->left;
	return curr;
}
node* del(node* root,int val)
{
	if(root==NULL)
		return root;
	if(val<root->key)
		root->left=del(root->left,val);
	else if(val>root->key)
		root->right=del(root->right,val);
	else
	{
		if(root->left==NULL)
		{
			node* temp=root->right;
			free(root);
			return temp;
		}
		else if(root->right==NULL)
		{
			node* temp=root->left;
			free(root);
			return temp;
		}
		node* min=minNode(root->right);
		root->key=min->key;
		root->right=del(root->right,min->key);
	}
	return root;
}
void inorder(node* root)
{
	if(root==NULL)
		return;
	inorder(root->left);
	cout<<root->key<<' ';
	inorder(root->right);
}
//O(n) solution
node* construct(int pre[],int *preIndex,int min,int max,int key,int n)
{
	if(*preIndex>=n)
		return NULL;
	node* root=NULL;
	if(key>min&&key<max)
	{
		root=create(key);
		*preIndex=*preIndex+1;
		if(*preIndex<n)
			root->left=construct(pre,preIndex,min,key,pre[*preIndex],n);
		if(*preIndex<n)
			root->right=construct(pre,preIndex,key,max,pre[*preIndex],n);
	}
	return root;
}
//O(n^2) solution
//first element will be root
//find the first element greater than it,say at index i
//all elements from 1 to i-1 are in the left subtree
//all elements from i to n-1 are in right subtree
//recursively call the function with the corresponding indices
node* construct2(int pre[],int min,int max,int n)
{
	if(min>=n||max<0||min>max)
		return NULL;
	node* root=NULL;
	if(min==max)
		root=create(pre[min]);
	else
	{
		root=create(pre[min]);
		int i;
		for(i=min+1;i<=max;i++)
		{
			if(pre[i]>pre[min])
				break;
		}
		root->left=construct2(pre,min+1,i-1,n);
		root->right=construct2(pre,i,max,n);
	}
	return root;
}
int main()
{
	int n,i;
	cin>>n;
	int pre[n];
	for(i=0;i<n;i++)
		cin>>pre[i];
	int preIndex=0;
	node* root=construct(pre,&preIndex,INT_MIN,INT_MAX,pre[0],n);
	inorder(root);
	cout<<'\n';
	node* root2=construct2(pre,0,n-1,n);
	inorder(root2);
	cout<<'\n';
	return 0;
}