#include <iostream>
using namespace std;
struct node
{
	int data;
	struct node* next;
};

node *new_node(int key)
{
	node *newnode;
	newnode= new node;
	newnode->data=key;
	newnode->next=NULL;
	return newnode;
}

node *reverse(node *head)
{
	node *temp,*nnode;
	while(head!=NULL)
	{
		nnode = head->next;
		head->next = temp;
		temp=head;
		head=nnode;
	}
	return temp;
}
void printlist(node *head)
{
	while(head!=NULL)
	{
		cout<<head->data<<endl;
		head = head->next;
	}
}
int main()
{
	cout<<"Enter the first element\n";
	int key;
	cin>>key;

	node *head=new_node(key);
	node *tail;
	tail=head;

	char ch;
	while(ch!='n')
	{
		cout<<"Enter data\n";
		cin>>key;
		tail->next=new_node(key);
		tail=tail->next;
		cout<<"Do u want to continue(y/n)\n";
		cin>>ch;
	}

	head = reverse(head);
	printlist(head);
}