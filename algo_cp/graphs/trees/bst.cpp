/*
BINARY TREE=>
0,1,or 2 children every node
0 or 2 children=>Full binary tree
full except for last level which is filled from left=>complete binary tree
HANDSHAKING LEMMA=>L=I+1 in binary tree where 
each node has 0 or 2 children, L are leaf nodes
I are internal nodes(root is also internal)

BINARU SEARCH TREE=>
Keys in left subtree<root
Keys in right subtree>roor
Left & right subtrees are also BSTs
Inorder=>gives sorted order
INSERTION=>
Search(like binary search) and insert as a leaf
DELETION=>
3 case
1. Leaf node=> simple remove it
2. has one child=>
replace node to be deleted with child node
3. has 2 children=>
Find successor in right subtree
Copy its value to current node
Delete the successor node

INSERT=>WORST CASE TIME COMPLEXITY=O(h)=O(n)
DELETE=>WORST CASE TIME COMPLEXITY same as INSERT
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
int main()
{
	node* root=NULL;
	root=insert(root,50);
	root=insert(root,30);
	root=insert(root,20);
	root=insert(root,40);
	root=insert(root,70);
	root=insert(root,60);
	root=insert(root,80);
	inorder(root);
	cout<<'\n';
	root=del(root,20);
	inorder(root);
	cout<<'\n';
	root=del(root,30);
	inorder(root);
	cout<<'\n';
	root=del(root,50);
	inorder(root);
	cout<<'\n';
	return 0;
}