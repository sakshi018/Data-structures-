//Given a sorted array and a number x, find the pair in array whose sum is closest to x
#include <iostream>
#include <climits>
#include <cstdlib>
using namespace std;

void printclosest(int *arr, int n, int x)
{
	int diff = INT_MAX;
	int l=0;
	int r= n-1;
	int res_l,res_r;

	while(r > l)
	{
		if(abs(arr[l] + arr[r]-x)<diff)
		{
			res_l = l;
			res_r = r;
			diff = abs(arr[l] + arr[r] - x);
		}
		else if((arr[l] + arr[r]) > x)
			r--;
		else
			l++;
	}
	 cout <<" The closest pair is " << arr[res_l] << " and " << arr[res_r];
}

int main()
{
    int arr[] =  {10, 22, 28, 29, 30, 40}, x = 54;
    int n = sizeof(arr)/sizeof(arr[0]);
    printclosest(arr, n, x);
    return 0;
}