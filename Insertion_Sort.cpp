#include <iostream>
using namespace std;
int main()
{
	int n,temp;
	cout<<"Enter size of array : ";
	cin>>n;
	int arr[n];
	cout<<"Enter array Elements : ";
	for(int i=0;i<n;i++)
	{
		cin>>arr[i];
	}
	for(int i=0;i<=n-1;i++)
	{
		int j=i;
		while(j>0 && arr[j-1]>arr[j])
		{
			swap(arr[j-1],arr[j]);
			j--;
		}
	}
	cout<<endl<<"Sorted Array : ";
	for(int i=0;i<n;i++)
	{
		cout<<arr[i]<<" ";
	}
	return 0;
}

