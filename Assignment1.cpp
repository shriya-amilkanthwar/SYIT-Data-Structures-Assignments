#include <iostream>
using namespace std;
struct Contact{
	string Name;
	string Number;
};
int main()
{
	int n;
	cout<<"Enter total number of contacts : ";
	cin>>n;
	Contact contacts[n];
	cout<<"Enter Contact Details :\n";
	for(int i=0;i<n;i++)
	{
		cout<<"Enter Name of Contact "<<i+1<<" : ";
		cin>>contacts[i].Name;
		cout<<"Enter Number : ";
		cin>>contacts[i].Number;
	}
	string nm;
	bool flag = true;
	cout<<"\nEnter Name to search : ";
	cin>>nm;
	
	for(int i=0;i<n;i++)
	{
		if(contacts[i].Name==nm)
		{
			cout<<"Contact Found :\n";
			cout<<"Name : "<<contacts[i].Name;
			cout<<"\nNumber : "<<contacts[i].Number;
			flag = false;
		}
	}
	if(flag)
	{
		cout<<"Contact Not found";
	}
	return 0;
}

