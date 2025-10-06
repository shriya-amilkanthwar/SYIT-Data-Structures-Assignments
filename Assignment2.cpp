#include <iostream>
#include <fstream>
#include <vector>
using namespace std;

void bubbleSort(vector<int>& arr)
{
	for(int i=0;i<arr.size()-1;i++)
	{
		for(int j=0;j<arr.size()-i-1;j++)
		{
			if(arr[j]>arr[j+1])
			{
				int temp = arr[j];
				arr[j] = arr[j+1];
				arr[j+1] = temp;
			}
		}
	}
}

int main()
{
	vector<int> temp;
	ifstream in("temperatures.txt");
	
	if(!in)
	{
		cout<<"Unable to open input file\n";
	}
	
	int data;
	while(in >> data)
	{
		temp.push_back(data);
	}
	in.close();
	
	if(temp.empty())
	{
		cout<<"No data found in the File\n";
		
	}
	
	bubbleSort(temp);
	
	cout<<"Sorted temprature : ";
	for(int t : temp)
	{
		cout<<t<<" ";
	}
	cout<<"\n";
	
	ofstream out("sorted_temperatures.txt");
	if(!out)
	{
		cout<<"Unable to open output File";
		return 1;
	}
	
	for(int t : temp)
	{
		out<< t << endl;
	}
	out.close();
	cout<<"Sorted Temperatures Stored in sorted_temperatures.txt file";
	return 0;
}

