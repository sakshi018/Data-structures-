//find-the-largest-pair-sum-in-an-unsorted-array
#include <iostream>
using namespace std;

int findsum(int *arr, int n)
{
	int first,second;
	if(arr[0]>arr[1])
	{
		first = arr[0];
		second = arr[1];
	}
	else
	{
		first = arr[1];
		second = arr[2];
	}

	int i;
	for(i=2;i<n;i++)
	{
		if(arr[i]>first)
		{
			second = first;
			first = arr[i];
		}
		else if(arr[i]>second && arr[i]!=first)
			second = arr[i];
	}
	return (first + second);
}

int main()
{
	int arr[] = {12, 34, 10, 6, 40};
    int n = sizeof(arr)/sizeof(arr[0]);
    cout << "Max Pair Sum is " << findsum(arr, n);
    return 0;
}