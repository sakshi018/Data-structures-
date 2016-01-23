//check-if-any-two-intervals-overlap-among-a-given-set-of-intervals
#include <iostream>
#include <algorithm>
using namespace std;

struct interval
{
	int start;
	int end;
};

bool compareinterval(interval i1, interval i2)
{
	if(i1.start < i2.start)
		return true;
	else
		return false;
}

bool isOverlap(interval *arr1, int n)
{
	sort(arr1, arr1+n-1, compareinterval);
	int i;
	for(i=1;i<n;i++)
	{
		if(arr1[i-1].end > arr1[i].start)
			return true;
	}
	return false;
}

int main()
{
	interval arr1[] =  {{1,3}, {7,9}, {4,6}, {10,13}};
    int n1 = sizeof(arr1)/sizeof(arr1[0]);
    isOverlap(arr1, n1)? cout << "Yes\n" : cout << "No\n";
 
    interval arr2[] =  { {6,8},{1,3},{2,4},{4,7} };
    int n2 = sizeof(arr2)/sizeof(arr2[0]);
    isOverlap(arr2, n2)? cout << "Yes\n" : cout << "No\n";
 
    return 0;
}
