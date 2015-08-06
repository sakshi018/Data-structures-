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

void evenodd(node *head)
{
	if(head!=NULL)
	{
		while(head!=NULL && head->next!=NULL)
		{
			head=head->next->next;
		}
		if(head==NULL)
			cout<<"List is even length";
		else
			cout<<"List is odd length";
	}
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
	evenodd(head);
}