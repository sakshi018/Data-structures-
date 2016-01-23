//find-the-element-that-appears-once in O(n)
#include <iostream>
using namespace std;

int findsingle(int *arr, int n)
{
	int res = arr[0];
	for(int i=1; i<n; i++)
	{
		res = res ^ arr[i];
	}

	return res;

}

int main()
{
     int ar[] = {2, 3, 5, 4, 5, 3, 4};
     int n = sizeof(ar)/sizeof(ar[0]);
     cout << "Element occurring once is " << findsingle(ar, n);
     return 0;
}