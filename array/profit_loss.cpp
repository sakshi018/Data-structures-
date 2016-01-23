#include <iostream>
#include <algorithm>
using namespace std;

int maxdiff(int *price, int n)
{
	int profit[n];
	int i;
	for(i=0 ;i<n; i++)
		profit[i]=0;

	int maxprice = price[n-1];
	for(i=n-2; i>=0; i--)
	{
		if(price[i] > maxprice)
			maxprice = price[i];

		profit[i] = max(profit[i+1], maxprice - price[i]);
	}

	int minprice = price[0];

	for(i=1; i<n; i++)
	{
		if(price[i]<minprice)
			minprice = price[i];
		profit[i] = max(profit[i-1], profit[i] + (price[i]-minprice));
	}

	return profit[n-1];
}

int main()
{
    int price[] = {2, 30, 15, 10, 8, 25, 80};
    int n = sizeof(price)/sizeof(price[0]);
    cout << "Maximum Profit = " << maxdiff(price, n);
    return 0;
}