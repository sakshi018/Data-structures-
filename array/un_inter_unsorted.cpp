//union intersection of two unsorted arrays
#include <iostream>
#include <algorithm>
using namespace std;

void printUnion(int *arr1, int *arr2, int m, int n)
{
	int i;
	if(m > n)
	{
		int *tempp = arr1;
		arr1 = arr2;
		arr2 = tempp;

		int temp = m;
		m = n;
		n = temp;
	}

	sort(arr1, arr1 + m);
	for(i=0; i<m; i++)
	{
		cout<<arr1[i]<<endl;
	}
	for(i=0; i<n; i++)
	{
		if(binary_search(arr1,arr1+m,arr2[i])==false)
			cout<<arr2[i]<<endl;
	}
}

void printIntersection(int *arr1, int *arr2, int m, int n)
{
	int i;
	if(m > n)
	{
		int *tempp = arr1;
		arr1 = arr2;
		arr2 = tempp;

		int temp = m;
		m = n;
		n = temp;
	}

	sort(arr1, arr1 + m);
	
	for(i=0; i<n; i++)
	{
		if(binary_search(arr1,arr1+m,arr2[i])==true)
			cout<<arr2[i]<<endl;
	}
}

int main()
{
    int arr1[] = {7, 1, 5, 2, 3, 6};
    int arr2[] = {3, 8, 6, 20, 7};
    int m = sizeof(arr1)/sizeof(arr1[0]);
    int n = sizeof(arr2)/sizeof(arr2[0]);
    cout << "Union of two arrays is \n";
    printUnion(arr1, arr2, m, n);
    cout << "\nIntersection of two arrays is \n";
    printIntersection(arr1, arr2, m, n);
    return 0;
}

//time complexity : O min(mlogm+nlogm,nlogn+mlogn)