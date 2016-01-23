#include <iostream>
using namespace std;

struct node
{
	node *left;
	node *right;
	int data;
};

node *newNode(int data)
{
	node *nnode = new node;
	nnode->data=data;
	nnode->right=NULL;
	nnode->left=NULL;

	return nnode;
}

void leavestoLinkedlist(node *root, node **head, node **tail)
{
	// = NULL;

	if(root==NULL)
		return;

	if(root->right==NULL && root->left==NULL)
	{
		if(*head==NULL)
			*(head)=*(tail)=root;
		else
		{
			(*tail)->right=root;
			*tail=(*tail)->right;
		}
		return;
	}

	leavestoLinkedlist(root->left, head, tail);
	leavestoLinkedlist(root->right, head, tail);

	//return root;
}

int main()
{
	node *root = NULL;
	node *head = NULL;
	node *tail = NULL;

	root = newNode(1);
	root->left = newNode(2);
    root->right = newNode(3);
    root->left->left = newNode(4);
    root->left->right = newNode(5);
    root->right->right = newNode(6);
    root->left->left->left = newNode(7);
    root->left->left->right = newNode(8);
    root->right->right->left = newNode(9);
    root->right->right->right = newNode(10);

    //cout<<"odo";

    leavestoLinkedlist(root, &head, &tail);

    //cout<<head->data;
    while(head!=NULL)
    {
    	cout<<head->data<<endl;
    	head=head->right;
    }
}