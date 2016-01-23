//Given a binary array sorted in non-increasing order, count the number of 1’s in it.
#include <iostream>
using namespace std;

int count1(int *arr, int low, int high)
{
	if(high>=low)
	{
		int mid = (high + low)/2;

		if((mid==high||arr[mid+1]==0) && arr[mid]==1)
			return mid+1;
		if(arr[mid]==1)
			count1(arr,mid+1,low);
		else
			count1(arr,low,mid-1);

	}
}

int main()
{
   int arr[] = {1, 1, 1, 1, 0, 0, 0};
   int n = sizeof(arr)/sizeof(arr[0]);
   cout << "Count of 1's in given array is " << count1(arr, 0, n-1);
   return 0;
}