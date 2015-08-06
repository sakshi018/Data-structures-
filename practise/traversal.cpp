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

void postorder(node* root)
{
	if(root==NULL)
		return;
	postorder(root->left);
	postorder(root->right);

	cout<<root->data<<endl;
}

void preorder(node* root)
{
	if(root==NULL)
		return;
	cout<<root->data<<endl;

	preorder(root->left);
	preorder(root->right);
}

void inorder(node* root)
{
	if(root==NULL)
		return;

inorder(root->left);
cout<<root->data<<endl;
inorder(root->right);
}

int main()
{
	node *root=newnode(1);
	root->left=newnode(2);
	root->right=newnode(3);
	root->left->left=newnode(4);
	root->right->right=newnode(5);

	cout<<"Pre order traversal is :"<<endl;
	preorder(root);

	cout<<"postorder traversal is :"<<endl;
	postorder(root);

	cout<<"Inorder traversal is :"<<endl;
	inorder(root);
}