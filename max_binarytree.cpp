#include <iostream>
#include <algorithm>
using namespace std;

struct node
{
	int data;
	struct node* left;
	struct node* right;
};
int findmax(node *root)
{	//int min=0;
	//int maxx=0;
	if(root!=NULL)
	{
		return max(root->data,max(findmax(root->left),findmax(root->right)));
	}
}

int main()
{
	node *root;
	root->data=20;
	root->left->data=30;
	root->right->data=10;
	root->left->right->data=56;
	root->left->left->data=12;
	root->right->right->data=45;
	root->right->left->data=100;
}