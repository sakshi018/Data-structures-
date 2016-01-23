#include <iostream>
using namespace std;

int maxdiff(int *arr, int n)
{
	int max_diff = arr[1] - arr[0];
	int min = arr[0];

	for(int i = 1; i<n; i++)
	{
		if(arr[i] - min > max_diff)
			max_diff = arr[i] - min;
		if(arr[i] < min)
			min = arr[i];
	}
	return max_diff;
}

int main()
{
	int arr[] = {80, 2, 6, 3, 100};
    int size = sizeof(arr)/sizeof(arr[0]);
    cout<<"Maximum difference is ";
    cout<<maxdiff(arr, size);
    return 0;
}