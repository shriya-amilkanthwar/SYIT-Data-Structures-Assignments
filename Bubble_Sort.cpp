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
//	for(int i=0;i<n;i++)
//	{
//		for(int j=0;j<n-1-i;j++)
//		{
//			if(arr[j]>arr[j+1])
//			{
//				swap(arr[j],arr[j+1]);
//			}
//		}
//		
//	}
	for(int i=n-1;i>=0;i--)
	{
		int didSwap =0;
		for(int j=0;j<=i-1;j++)
		{
			if(arr[j]>arr[j+1])
			{
				swap(arr[j],arr[j+1]);
				didSwap = 1;
			}
		}
		
		if(didSwap==0)
		{
			break;
		}
		cout<<"runs\n";
	}
	cout<<endl<<"Sorted Array : ";
	for(int i=0;i<n;i++)
	{
		cout<<arr[i]<<" ";
	}
	return 0;
}

