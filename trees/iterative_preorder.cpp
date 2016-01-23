#include <iostream>
#include <stack>
#include <algorithm>
using namespace std;
struct node
{
	int data;
	node *left;
	node *right;
};

node* newNode(int data)
{
   node* nodee = new node;
    nodee->data = data;
    nodee->left = NULL;
    nodee->right = NULL;
 
    return(nodee);
}

void preorder(node *root)
{
	stack<node*> s;

	while(1)
	{
		while(root)
		{
			cout<<root->data;

			s.push(root);

			root=root->left;
		}

		if(s.empty())
			break;
		root=s.top();
		s.pop();

		root=root->right;
	}
}

int main()
{
    node *root = newNode(1);
    root->left        = newNode(2);
    root->right       = newNode(3);
    root->left->left  = newNode(7);
    root->left->right = newNode(6);
    root->right->left  = newNode(5);
    root->right->right = newNode(4);
    //cout << "Spiral Order traversal of binary tree is \n";
    preorder(root);
 
    return 0;
}