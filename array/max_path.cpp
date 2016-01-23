//Given two sorted arrays such the arrays may have some common elements. Find the sum of the maximum sum path to reach from beginning of any array to end of any of the two arrays. We can switch from one array to another array only at common elements.

#include <iostream>
#include <algorithm>
using namespace std;

int getSum(int *a, int *b, int m, int n)
{
	int i=0, j=0;
	int result =0;
	int sum1,sum2;

	sum1=sum2=0;

	while(i<m && j<n)
	{
		if(a[i]<b[j])
			sum1 = sum1 + a[i++];
		else if(a[i]>b[j])
			sum2 = sum2 + b[j++];
		else
		{
			result = result + max(sum1,sum2);
			sum1 = sum2 =0;

			while(i<m && j<n && a[i] == b[j])
			{
				result = result + a[i++];
				j++;
				//cout<<result<<endl;
			}
		}
	}

	while(i<m)
	{
		sum1 = sum1 + a[i++];
	}
	while(j<n)
		sum2 = sum2 + b[j++];

	result = result + max(sum1, sum2);
	cout<<result<<endl;

	return result;
}

int main()
{
    int ar1[]  = {2, 3, 7, 10, 12, 15, 30, 34};
    int ar2[] =  {1, 5, 7, 8, 10, 15, 16, 19};
    int m = sizeof(ar1)/sizeof(ar1[0]);
    int n = sizeof(ar2)/sizeof(ar2[0]);
    cout << "Maximum sum path is "
         << getSum(ar1, ar2, m, n);
    return 0;
}


