//check-given-array-contains-duplicate-elements-within-k-distance
#include <iostream>
#include <algorithm>
#include <map>
using namespace std;

bool kdistance(int *a, int n, int k)
{
	map<int,int> hmap;

	for(int i=0; i<n; i++)
	{
		if(hmap.find(a[i])==hmap.end())
			//hmap.insert(a[i],1);
			hmap.insert(map<int,int>::value_type(a[i],1));
		else
			return true;
		if(i>=k)
			hmap.erase(a[i-k]);
	}
	return false;
}

int main()
{
	 int arr[] = {10, 5, 3, 4, 3, 5, ny76};
	 int n = sizeof(arr)/sizeof(arr[0]);
        if (kdistance(arr,n,3))
           cout<<"Yes";
        else
           cout<<"No";
}