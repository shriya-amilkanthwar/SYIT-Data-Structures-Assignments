#include <iostream>
#include <vector>
using namespace std;
void bubbleSort(vector<int>& nums,int n) {
    if(n==1)
    {
          return;
    }
            
    for(int i=0;i<n-1;i++)
    {
        if(nums[i]>nums[i+1])
        {
               swap(nums[i],nums[i+1]);
        }
    }
    bubbleSort(nums,n-1);
      
    }
int main()
{
	vector<int> nums = {24,6,87,54,12};
	int n = nums.size();
	cout<<"Before Sorting : \n";
	for(int i=0;i<n;i++)
	{
		cout<<nums[i]<<" ";
	}
	bubbleSort(nums,n);
	cout<<"\nAfter Sorting : \n";
	for(int i=0;i<n;i++)
	{
		cout<<nums[i]<<" ";
	}
}


