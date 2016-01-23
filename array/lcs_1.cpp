//Given an array of 0s and 1s, find the position of 0 to be replaced with 1 to get longest continuous sequence of 1s.
#include <iostream>
using namespace std;

int repl(int *arr, int n)
{
	int max_count = 0;
	int prev_zero = -1;
	int prev_prev_zero = -1;
	int max_index;
	int curr;
	for(curr=0; curr<n; curr++)
	{
		if(arr[curr]==0)
		{
			if(curr-prev_prev_zero > max_count)
			{
				max_count = curr - prev_prev_zero;
				max_index = prev_zero;
			}

			prev_prev_zero = prev_zero;
			prev_zero = curr;
		}
	}

	if(n-prev_prev_zero > max_count)
		max_index = prev_zero;

	return max_index;
}

int main()
{
    int arr[] = {1, 1, 0, 0, 1, 0, 1, 1, 1, 0, 1, 1, 1};
    int n = sizeof(arr)/sizeof(arr[0]);
    cout << "Index of 0 to be replaced is "
         << repl(arr, n);
    return 0;
}