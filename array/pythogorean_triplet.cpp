#include <iostream>
#include <algorithm>
using namespace std;

bool pythogorean(int *arr, int n)
{
	int i;
	for(i=0; i<n ;i++)
	{
		arr[i] = arr[i] * arr[i];
	}

	sort(arr, arr+n);

	for(i=n-1; i>=2; i--)
	{
		int l=0;
		int r = i-1;
		while(l<r)
		{
			if(arr[l] + arr[r] == arr[i])
				return true;
			else if(arr[l] + arr[r] < arr[i])
				l++;
			else
				r--;
		}
	}
	return false;
}
int main()
{
    int arr[] = {3, 1, 4, 6, 5};
    int arr_size = sizeof(arr)/sizeof(arr[0]);
    pythogorean(arr, arr_size)? cout << "Yes": cout << "No";
    return 0;
}