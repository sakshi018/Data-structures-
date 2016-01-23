#include <iostream>
#include <string>
using namespace std;

struct node
{
	string data;
	node* next;
};

node *new_node(string s)
{
	node *newnode;
	newnode = new node;
	newnode->data = s;
	newnode->next = NULL;
	return newnode;
}
node *findmid(node *head)
{
	node *slow,*fast;
	slow=head;
	fast=head;
	if(head!=NULL)
	{
		while(fast!=NULL && fast->next!=NULL)
		{
			fast=fast->next->next;
			if(fast!=NULL)
				return slow;
			slow=slow->next;
		}
		return slow;
	}
}

node *reverse(node *head2)
{
	node *nnode,*prev;
	prev=NULL;
	while(head2!=NULL)
	{
		nnode=head2->next;
		head2->next=prev;
		prev=head2;
		head2=nnode;
	}
	return prev;
}

void palindrome(int l, node *head)
{
	node *mid=findmid(head);
	node *prev=NULL;
	node *temp=head;
	node *head2,*head1;
	head1=head;

	head2=mid->next;
	mid->next=NULL;
	head2=reverse(head2);

	int flag=0;
	if(l%2!=0)
	{
		/*while(temp->next!=mid)
		{
			temp=temp->next;
		}
		prev=temp;*/
		
		while(head1->next!=mid && head2!=NULL)
		{
			if(head1->data.compare(head2->data)!=0)
			{
				cout<<"Linked list is not palinrome"<<endl;
				flag=1;
				break;
			}
			head1=head1->next;
			head2=head2->next;
		}
		if(flag!=1)
			cout<<"Linked list is palindrome"<<endl;
	}
	else
	{
		while(head1!=mid && head2!=NULL)
		{
			if(head1->data.compare(head2->data)!=0)
			{
				cout<<"LInked list is not palindrome"<<endl;
				flag=1;
				break;
			}
			head1=head1->next;
			head2=head2->next;
		}
		if(flag!=1)	
			cout<<"linked list is palindrome"<<endl;
	}

}

int main()
{
	node *head,*tail;
	int i,l;
	string s;
	cout<<"Enter the length of linked list "<<endl;
	cin>>l;
	cout<<"Enter your character"<<endl;
	cin>>s;
	head=new_node(s);
	tail=head;
	for(i=0;i<l-1;i++)
	{
		cout<<"Enter your character"<<endl;
		cin>>s;
		tail->next=new_node(s);
		tail=tail->next;
	}
	palindrome(l,head);
}