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
/* to find the nth node from the end*/
void endnode(node *head, int n)
{
	node *fast,*slow;
	fast=head;
	slow=head;
	int count=0;
	while(count!=n)
	{
		//if(n-count>0)
		//{
			fast=fast->next;
			count++;
		//}
	}
	while(fast!=NULL)
	{
		slow=slow->next;
		fast=fast->next;
	}

	cout<<"The nth node from end is: "<<slow->data<<endl;
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

	int n;
	cout<<"Enter the nth node from end"<<endl;
	cin>>n;
	endnode(head,n);
}