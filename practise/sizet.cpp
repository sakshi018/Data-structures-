#include <iostream>
using namespace std;

struct node
{
	int data;
	struct node *left;
	struct node *right;
};

node *newnode(int data)
{
	node *newnode = new node;
	newnode->data = data;
	newnode->left = NULL;
	newnode->right = NULL;

	return newnode;
}

int size(node *root)
{
	if(root==NULL)
		return 0;
	else
		return(size(root->left)+1+size(root->right));
}

int main()
{
	node *root=newnode(1);
	root->left=newnode(2);
	root->right=newnode(3);
	root->left->left=newnode(4);
	root->right->right=newnode(5);

	cout<<"Size of tree is: "<<size(root)<<endl;
	
}