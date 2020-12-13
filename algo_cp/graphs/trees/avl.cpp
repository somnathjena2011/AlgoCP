/*
AVL=>Height Balanced Tree
Height=O(logn)
INsertion,Deletion,Search=>O9h)=O(logn)
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
	int height;
	int key;
	struct node* left;
	struct node* right;
}node;
int height(node* x)
{
	if(x==NULL)
		return 0;
	return x->height;
}
node* create(int key)
{
	node* nd=(node*)malloc(sizeof(node));
	nd->height=1;
	nd->key=key;
	nd->left=NULL;
	nd->right=NULL;
	return nd;
}
node* leftRotate(node* root)
{
	node* r=root->right;
	root->right=r->left;
	r->left=root;
	root->height=max(height(root->left),height(root->right))+1;
	r->height=max(height(r->left),height(r->right))+1;
	return r;
}
node* rightRotate(node* root)
{
	node* l=root->left;
	root->left=l->right;
	l->right=root;
	root->height=max(height(root->left),height(root->right))+1;
	l->height=max(height(l->left),height(l->right))+1;
	return l;
}
int getBalance(node* x)
{
	if(x==NULL)
		return 0;
	return height(x->left)-height(x->right);
}
node* insert(node* root,int key)
{
	if(root==NULL)
		return create(key);
	if(key<root->key)
		root->left=insert(root->left,key);
	else if(key>root->key)
		root->right=insert(root->right,key);
	else
		return root;
	root->height=max(height(root->left),height(root->right))+1;
	int bal=getBalance(root);
	if(bal>1)
	{
		if(key<root->left->key)
			return rightRotate(root);
		else if(key>root->left->key)
		{
			root->left=leftRotate(root->left);
			return rightRotate(root);
		}
	}
	else if(bal<-1)
	{
		if(key>root->right->key)
			return leftRotate(root);
		else if(key<root->right->key)
		{
			root->right=rightRotate(root->right);
			return leftRotate(root);
		}
	}
	return root;
}
node* minNode(node* root)
{
	node* curr=root;
	while(curr&&curr->left)
		curr=curr->left;
	return curr;
}
node* del(node* root,int key)
{
	if(root==NULL)
		return root;
	if(key<root->key)
		root->left=del(root->left,key);
	else if(key>root->key)
		root->right=del(root->right,key);
	else
	{
		if(root->left==NULL&&root->right==NULL)
		{
			free(root);
			root=NULL;
		}
		else if(root->left==NULL)
		{
			node* temp=root->right;
			*root=*temp;
			free(temp);
		}
		else if(root->right==NULL)
		{
			node* temp=root->left;
			*root=*temp;
			free(temp);
		}
		else
		{
			node* temp=minNode(root->right);
			root->key=temp->key;
			root->right=del(root->right,temp->key);
		}
	}
	if(root==NULL)
		return root;
	root->height=max(height(root->left),height(root->right))+1;
	int bal=getBalance(root);
	if(bal>1)
	{
		if(getBalance(root->left)>=0)
			return rightRotate(root);
		else
		{
			root->left=leftRotate(root->left);
			return rightRotate(root);
		}
	}
	else if(bal<-1)
	{
		if(getBalance(root->right)<=0)
			return leftRotate(root);
		else
		{
			root->right=rightRotate(root->right);
			return leftRotate(root);
		}
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
void preorder(node* root)
{
	if(root==NULL)
		return;
	cout<<root->key<<' ';
	preorder(root->left);
	preorder(root->right);
}
int main()
{
	node* root=NULL;
	root = insert(root, 9);  
    root = insert(root, 5);  
    root = insert(root, 10);  
    root = insert(root, 0);  
    root = insert(root, 6);  
    root = insert(root, 11);  
    root = insert(root, -1);  
    root = insert(root, 1);  
    root = insert(root, 2);  
    preorder(root);
    cout<<'\n';
    root=del(root,10);
    preorder(root);
    cout<<'\n';
    return 0;
}