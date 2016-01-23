#include <iostream>
using namespace std;

struct node
{
	node *left;
	node *right;
	int data;
};
void increment(node *root, int diff);
void converttree(node *root)
{
	int left_data = 0;
	int right_data = 0;
	int diff;
	if(root == NULL || (root->left==NULL && root->right == NULL))
		return;
	else
	{
		converttree(root->left);
		converttree(root->right);

		if(root->left!=NULL)
			left_data = root->left->data;
		if(root->right != NULL)
			right_data = root->right->data;

		diff = left_data + right_data - root->data;

		if(diff>0)
			root->data = root->data + diff;
		if(diff<0)
			increment(root, -diff);
	}
}

void increment(node *root, int diff)
{
	if(root->left!=NULL)
	{
		root->left->data = root->left->data + diff;
		increment(root->left, diff);
	}
	else if(root->right!=NULL)
	{
		root->right->data =  root->right->data + diff;
		increment(root->right, diff);
	}
}

void printInorder(node* node)
{
  if (node == NULL)
    return;
 
  /* first recur on left child */
  printInorder(node->left);
 
  /* then print the data of node */
  cout<<node->data<<endl;
 
  /* now recur on right child */
  printInorder(node->right);
}

node* newNode(int data)
{
  node *nnode = new node;
  nnode->data = data;
  nnode->left = NULL;
  nnode->right = NULL;
  return nnode;
}

int main()
{
  node *root = newNode(50);
  root->left        = newNode(7);
  root->right       = newNode(2);
  root->left->left  = newNode(3);
  root->left->right = newNode(5);
  root->right->left  = newNode(1);
  root->right->right = newNode(30);
 
  cout<<"\n Inorder traversal before conversion "<<endl;
  printInorder(root);
 
  converttree(root);
 
  cout<<"\n Inorder traversal after conversion "<<endl;
  printInorder(root);
 
  //getchar();
  return 0;
}