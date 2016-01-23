//replace-every-array-element-by-multiplication-of-previous-and-next
/*Given an array of integers, update every element with multiplication of previous and next elements with following exceptions. 
a) First element is replaced by multiplication of first and second.
b) Last element is replaced by multiplication of last and second last.
*/
#include <iostream>
using namespace std;

void replace(int *arr, int n)
{
	int prev = arr[0];
	arr[0] = arr[0] * arr[1];
	int curr;
	for(int i=1; i<n-1; i++)
	{
		curr = arr[i];
		arr[i] = prev * arr[i+1];
		prev = curr;
	}

	arr[n-1] = prev * arr[n-1];
}

int main()
{
    int arr[] = {2, 3, 4, 5, 6};
    int n = sizeof(arr)/sizeof(arr[0]);
    replace(arr, n);
    for (int i=0; i<n; i++)
      cout << arr[i] << " ";
    return 0;
}