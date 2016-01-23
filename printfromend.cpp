#include <iostream>
using namespace std;

struct node
{
	int data;
	node* next;
};

node *new_node(int key)
{
	node *newnode;
	newnode = new node;
	newnode->data = key;
	newnode->next = NULL;
	return newnode;
}

void printend(node *head)
{
	if(head==NULL)
		return;
	printend(head->next);
	cout<<head->data<<endl;
}
int main()
{
	node *head,*tail;
	int i,l,data;
	cout<<"length of ll?"<<endl;
	cin>>l;
	cout<<"enter data"<<endl;
	cin>>data;
	head=new_node(data);
	tail=head;
	for(i=0;i<l-1;i++)
	{
		cout<<"enter data"<<endl;
		cin>>data;
		tail->next=new_node(data);
		tail=tail->next;
	}
	printend(head);
}