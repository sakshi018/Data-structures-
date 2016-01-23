#include <iostream>
using namespace std;

struct node
{
	int data;
	struct node *left;
	struct node *right;
};

node *new_node(int data)
{
	node *newnode = new node;
	newnode->data = data;
	newnode->left = NULL;
	newnode->right = NULL;

	return newnode;
}

int identical(node *root1, node *root2)
{
	if(root1==NULL && root2==NULL)
	{
		return 1;
	}
	if(root1!=NULL && root2!=NULL)
	{
		if((root1->data==root2->data)&&(identical(root1->left,root2->left))&&(identical(root1->right,root2->right)))
			return 1;
	}

	return 0;
}

int main()
{
	node *root1,*root2;
	root1=new_node(1);
	root1->left=new_node(2);
	root1->right=new_node(3);
	root1->left->left=new_node(4);
	root1->left->right=new_node(5);

	root2=new_node(1);
	root2->left=new_node(2);
	root2->right=new_node(3);
	root2->left->left=new_node(4);
	root2->left->right=new_node(5);
	root2->left->right->left=new_node(6);

	if(identical(root1,root2))
	{
		cout<<"The trees are identical"<<endl;
	}
	else
	{
		cout<<"Not identical"<<endl;
	}
	return 0;
}