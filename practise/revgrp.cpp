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
node *reversegroup(node *head, int k)
{
	node *current,*nnode,*prev;
	current=head;
	nnode=prev=NULL;

	int count=0;

	while(current!=NULL && count<k)
	{
		nnode=current->next;
		current->next=prev;
		prev=current;
		current=nnode;
		count++;
	}
	if(nnode!=NULL)
	{
		head->next=reversegroup(current,k);
	}

	return prev;
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
	int k;
	cout<<"Enter the size of group to be reversed"<<endl;
	cin>>k;
	head=reversegroup(head,k);
	printlist(head);
}