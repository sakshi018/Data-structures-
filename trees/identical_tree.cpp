#include <iostream>
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

int identical(node *a, node *b)
{
	if(a==NULL && b==NULL)
		return 1;
	if(a!=NULL && b!=NULL)
		return ((a->data == b->data) && identical(a->left,b->left) && identical(a->right,b->right));

	return 0;
}

int main()
{
    node *root1 = newNode(1);
    node *root2 = newNode(1);
    root1->left = newNode(2);
    root1->right = newNode(3);
    root1->left->left  = newNode(4);
    root1->left->right = newNode(5); 
 
    root2->left = newNode(2);
    root2->right = newNode(3);
    root2->left->left = newNode(4);
    root2->left->right = newNode(5); 
 
    if(identical(root1, root2))
        cout<<"Both tree are identical.";
    else
        cout<<"Trees are not identical.";
 
  return 0;
}