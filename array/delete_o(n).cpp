//delete-an-element-from-array-using-one-traversal/
//will not work if element not present
#include <iostream>
using namespace std;

void deletelement(int *arr, int n, int x)
{
	if(arr[n-1]==x)
		return;
	int prev = arr[n-1];
	int i;
	int curr;
	for(i=n-2; i>=0 && arr[i]!=x; i--)
	{
		curr = arr[i];
		arr[i] = prev;
		prev = curr;
	}

	if(i<0)
		return; //element not found
	arr[i] = prev;

	for(i=0;i<n-1;i++)
	{
		cout<<arr[i]<<endl;
	}
}

int main()
{
	int arr[] = {11, 15, 6, 8, 9, 10};
    int n = sizeof(arr)/sizeof(arr[0]);
    int x = 6;
    deletelement(arr,n,x);
}