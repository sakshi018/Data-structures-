//sum of distinct elements of an array in window k
//count of distinct elements of an array in window k
//sum of count of distinct elements of an array in window k

#include <iostream>
#include <map>
using namespace std;

void countWindow(int *a, int k, int n)
{
	map<int, int> hmap;
	map<int, int>::iterator it;
	int dist_count=0;
	int sum=0;
	int i;
	for(i=0; i<k; i++)
	{	
		//it = hmap.find(a[i]);
		if(hmap.find(a[i])==hmap.end())
		{
			hmap.insert(map<int,int>::value_type(a[i],1));
			sum = sum +a[i];
		}
		else
			hmap[a[i]]++;
	}
	cout<<sum<<endl;
	//sum =0;
	//sum = sum+dist_count;
	for(i=k; i<n; i++)
	{
		if(hmap[a[i-k]]==1)
		{
			hmap.erase(a[i-k]);
			dist_count--;
			sum=sum-a[i-k];
		}
		else
		{
			hmap[a[i-k]]--;
			//sum=sum-a[i];
		}

		//insert more elements
		//it = hmap.find(a[i]);
		
		if(hmap.find(a[i])==hmap.end())
		{
			hmap.insert(map<int,int>::value_type(a[i],1));
			sum = sum +a[i];
		}
		else
		{
			hmap[a[i]]++;
			//sum = sum +a[i];
		}

		cout<<sum<<endl;
		//sum=sum+dist_count;
	}
	//cout<<sum<<endl;

}

int main()
{
	int arr[] = {1, 2, 1, 3, 4, 2, 3};
	int k=4;
	int n = sizeof(arr)/sizeof(arr[0]);
	countWindow(arr,k,n);
}