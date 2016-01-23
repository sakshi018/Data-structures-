//top view of tree
//wrong soln
#include <iostream>
#include <algorithm>
#include <map>
#include <queue>
using namespace std;

struct node
{
	int key;
	node *left;
	node *right;
};

struct qitem
{
	int hd;	//horizontal distance
	node *nnode;
};

node* newNode(int key)
{
    node* nnode = new node;
    nnode->key = key;
    nnode->left = nnode->right = NULL;
    return nnode;
}

void printtopview(node *root)
{
	if(root == NULL)
		return;
	map<int> set;
	//std::vector<int> set;
	queue<qitem> q;
	q.push(root,0);

	while(!q.empty())
	{
		qitem qi = q.top();
		q.pop();
		int hd = qi.hd;
		node *nnode = qi->nnode;
		if(set.find(hd)==set.end())
		{
			set.add(hd);
			cout<<node->key;
		}
		if(node->left != NULL)
			q.push(n->left,hd-1);
		if(node->right != NULL)
			q.push(n->right, hd+1);
	}
}

int main()
{
	node *root = newNode(1);
    root->left = newNode(2);
    root->right = newNode(3);
    root->left->left = newNode(4);
    root->left->right = newNode(5);
    root->right->left = newNode(6);
    root->right->right = newNode(7);
    root->right->left->right = newNode(8);
    root->right->right->right = newNode(9);
    cout << "Vertical order traversal is \n";
    printtopview(root);
    return 0;
}

