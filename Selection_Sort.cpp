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
	for(int i=0;i<n-1;i++)
	{
		int mini = i;
		for(int j=i+1;j<n;j++)
		{
			if(arr[j]<arr[mini])
			{
				mini = j;
			}
		}
		swap(arr[i],arr[mini]);
	}
	cout<<endl<<"Sorted Array : ";
	for(int i=0;i<n;i++)
	{
		cout<<arr[i]<<" ";
	}
	return 0;
}

