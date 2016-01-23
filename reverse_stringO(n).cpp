#include <iostream>
using namespace std;

void reverse(char *begin, char *end);
void reverse_word(char *s)
{
	char *temp=s;
	char *word_begin=s;
	while(*temp)
	{
		temp++;
		if(*temp=='\0')
		{
			reverse(word_begin,temp-1);
		}
		else if(*temp==' ')
		{
			reverse(word_begin,temp-1);
			word_begin=temp+1;
		}
	}
	reverse(s,temp-1);
}
void reverse(char *begin, char *end)
{
	char temp;
	while(begin<end)
	{
		temp = *begin;
		*begin++ = *end;
		*end-- = temp;
	}
}

int main()
{
	char s[] = "i like it";
	cout<<s<<endl;
	reverse_word(s);
	cout<<s<<endl;; 
}