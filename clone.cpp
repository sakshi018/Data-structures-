/*You are given a Double Link List with one pointer of each node pointing to the next node just like in a single link list. The second pointer however CAN point to any node in the list and not just the previous node. Now write a program in O(n) time to duplicate this list. That is, write a program which will create a copy of this list.*/
#include <iostream>
using namespace std;

struct node
{
	int data;
	node *next;
	node *arbit;
};

node *new_node(int data)
{
	node *newnode = new node;
	newnode->data=data;
	newnode->next=NULL;
	newnode->arbit=NULL;
	return newnode;
}

void printlist(node *head)
{
	node *temp=head;
	cout<<"linked list next pointer"<<endl;
	while(temp!=NULL)
	{
		cout<<temp->data<<endl;
		temp=temp->next;
	}
	cout<<"Arbitary pointer"<<endl;
	while(head!=NULL)
	{
		cout<<head->arbit->data<<endl;
		head=head->next;
	}
}

node *clone(node *head1)
{
	node *head2;
	node *temp1,*temp2;
	head2=head1;
	temp1=head1;
	temp2=head2;
	while(temp1!=NULL)
	{
		temp2=temp1;
		temp1=temp1->next;
		temp2=temp2->next;
	}
	temp1=head1;
	temp2=head2;
	printlist(temp2);
	node *curr;
	curr=temp1;
	/*while(curr!=NULL)
	{	//cout<<"hello";
		temp1=curr;
		temp1->next=temp2;
		temp2->arbit=temp1;
		temp2=temp2->next;
		curr=curr->next;
	}
	temp1=head1;
	temp2=head2;
	while(temp2!=NULL)
	{
		temp2->arbit=temp2->arbit->arbit->next;
		temp2=temp2->next;
	}
	//temp2->next=NULL;*/
	return head2;
}


int main()
{
	node *head,*tail;
	head=new_node(1);
	head->next=new_node(2);
	head->next->next=new_node(3);
	head->next->next->next=new_node(4);
	head->next->next->next->next=new_node(5);
	node *arr[5];
	int i;
	tail=head;
	for(i=0;i<5;i++)
	{
		arr[i]=tail;
		tail=tail->next;
	}

	head->arbit=arr[2];
	head->next->arbit=arr[0];
	head->next->next->arbit=arr[4];
	head->next->next->next->arbit=arr[2];
	head->next->next->next->next->arbit=arr[1];

	printlist(head);
	node *head2;
	head2=clone(head);
	//printlist(head2);
}