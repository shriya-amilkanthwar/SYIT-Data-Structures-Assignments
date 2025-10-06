#include <iostream>
#include <vector>
using namespace std;
int linearSearch(vector<int>& nums, int target) {
        int i;
        for(i=0;i<nums.size();i++)
        {
            if(nums[i]==target && i!=nums.size())
            {
                break;
            }
        }
        if(i==nums.size())
        {
            return -1;
        }
        else{
            return i;
        }
    }
int main()
{
	vector<int> arr = {0,54,0,51,10,5};
	int n = arr.size();
	cout<<linearSearch(arr,5);
	return 0;
}

