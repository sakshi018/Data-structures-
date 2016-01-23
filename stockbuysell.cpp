#include <iostream>
using namespace std;

struct interval
{
	int buy;
	int sell;
};

void stockbuysell(int *a, int n)
{
	int count=0;
	interval sol[n/2 + 1];

	if(n==1)
		return;
	int i=0;
	while(i<n-1)
	{
		while((i<n-1)&&(a[i+1]<a[i]))
			i++;
		if(i==n-1)
			break;
		sol[count].buy=i++;

		while((i<n)&&(a[i+1]>a[i]))
			i++;
		sol[count].sell=i-1;

		count++;
	}
	if(count==0)
		cout<<"No day to make profit"<<endl;
	else
	{
		for(int i=0;i<count;i++)
		{
			cout<<"Buy on: "<<sol[i].buy<<" Sell on: "<<sol[i].sell<<endl;
		}
	}
}

int main()
{
	int price[] = {100, 180, 260, 310, 40, 535, 695};
    int n = sizeof(price)/sizeof(price[0]);
    stockbuysell(price,n);
}