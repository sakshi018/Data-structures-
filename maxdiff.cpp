#include <iostream>
using namespace std;

int maxdifference(int *a, int n)
{
	int maxdiff=a[1]-a[0];
	int min = a[0];

	for(int i=0;i<n;i++)
	{
		if(a[i]-min>maxdiff)
			maxdiff=a[i]-min;
		if(a[i]<min)
			min = a[i];
	}
	return maxdiff;
}

int main()
{
  int arr[] = {1, 2, 6, 80, 100};
  int size = sizeof(arr)/sizeof(arr[0]);

  int md = maxdifference(arr,size);
  cout<<md;
}