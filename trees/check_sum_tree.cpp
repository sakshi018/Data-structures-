#include <iostream>
using namespace std;

struct node
{
	node *left;
	node *right;
	int data;
};

int checksumtree(node *root)
{	
	int node_left=0;
	int node_right = 0;

	if(root == NULL || (root->left==NULL && root->right==NULL))
		return 1;
	else
	{
		if(root->left!=NULL)
			node_left=root->left->data;
		if(root->right!=NULL)
			node_right=root->right->data;

		if((root->data= node_left + node_right) && checksumtree(root->left) && checksumtree(root->right))
			return 1;
		else
			return 0;

	}
}

node* newNode(int data)
{
  node *nnode = new node;
  nnode->data = data;
  nnode->left = NULL;
  nnode->right = NULL;
  return nnode;
}
 
/* Driver program to test above function */
int main()
{
   node *root  = newNode(10);
  root->left         = newNode(8);
  root->right        = newNode(2);
  root->left->left   = newNode(3);
  root->left->right  = newNode(5);
  root->right->right = newNode(2);
  if(checksumtree(root))
    cout<<"The given tree satisfies the children sum property ";
  else
    cout<<"The given tree does not satisfy the children sum property ";
  return 0;
}