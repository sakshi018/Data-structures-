#include <iostream>
using namespace std;

struct node
{
	int data;
	struct node* next;
};

node *newnode(int key)
{
	node *newnode;
	newnode= new node;
	newnode->data=key;
	newnode->next=NULL;
	return newnode;
}

void intersection(node *head1, node *head2)
{
	int l1,l2,d;
	l1=l2=d=0;

	node *h1,*h2;
	h1=head1;
	h2=head2;
	while(h1!=NULL)
	{
		l1++;
		h1=h1->next;
	}
	while(h2!=NULL)
	{
		l2++;
		h2=h2->next;
	}

	if(l1<l2)
	{
		d=l2-l1;
		h1=head2;
		h2=head1;
	}
	else
	{
		d=l1-l2;
		h1=head1;
		h2=head2;
	}

	for(int i=0; i<d; i++)
	{
		h1=h1->next;
	}

	while(h1!=NULL && h2!=NULL)
	{
		if(h1==h2)
		{
			cout<<"Intersection of two nodes is:"<<h1->data<<endl;
			break;
		}
		h1=h1->next;
		h2=h2->next;
	}
}

int main()
{
	node *head1,*head2;
	head1=newnode(10);
	head2=newnode(3);
	head2->next=newnode(6);
	head2->next->next=newnode(9);
	head1->next=newnode(15);
	head2->next->next->next=newnode(15);
	head1->next=head2->next->next->next;
	head1->next->next=newnode(30);

	intersection(head1,head2);
}