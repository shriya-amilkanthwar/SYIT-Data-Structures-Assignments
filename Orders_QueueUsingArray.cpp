#include<iostream>
using namespace std;
#define size 3
struct Order{
	int id;
	string name;
	string item;
};
class Queue
{
	Order arr[size];
	int front,rear;
	public :
		Queue()
		{
			front = -1;
			rear = -1;
		}
		bool isFull()
		{
			return ((rear+1)%size==front);
			
		}
		bool isEmpty()
		{
			return (front==-1);
		}
		void enqueue(Order order)
		{
			if(isFull())
			{
				cout<<"Queue is Full"<<endl;
				return;
			}
			if(isEmpty())
			{
				front = rear = 0;
			
			}
			else
			{
				rear=(rear+1)%size;
			}
				arr[rear] = order;
				cout<<"Order Added successfully\n";
		}
		void dequeue()
		{
			if(isEmpty())
			{
				cout<<"Queue is Empty"<<endl;
				return;
			}
			if(front==rear)
			{
				front=rear=-1;
			}
			else
			{
				Order p = arr[front];
				cout<<"Order with id : "<<p.id<<" deleted\n";
				front=(front+1)%size;
			}
			
		}
		void display()
		{
			if(isEmpty())
			{
				cout<<"Queue is Empty"<<endl;
				return;
			}
			int i=front;
			cout<<"\nOrder details :\n";
			while(true)
			{
				cout<<"Order Id : "<<arr[i].id<<endl;
				cout<<"Name : "<<arr[i].name<<endl;
				cout<<"Items : "<<arr[i].item<<endl<<endl;
				if(i==rear)
				{
					break;
				}
				i = (i+1)%size;
			}
		}
};
int main()
{
	Queue q;
	int choice;
	Order o;

	do {
		cout << "\n==============================\n";
		cout << "        Order Menu\n";
		cout << "==============================\n";
		cout << "1. Add Order \n";
		cout << "2. Delete Order\n";
		cout << "3. Display Orders\n";
		cout << "4. Exit\n";
		cout << "------------------------------\n";
		cout << "Enter your choice: ";
		cin >> choice;

		switch (choice) {
			case 1:
				cout << "Enter Order ID: ";
				cin >> o.id;
				cout << "Enter Customer Name: ";
				cin >> o.name;
				cout << "Enter Item: ";
				cin >> o.item;
				q.enqueue(o);
				break;

			case 2:
				q.dequeue();
				break;

			case 3:
				q.display();
				break;

			case 4:
				cout << "Exiting program...\n";
				break;

			default:
				cout << "Invalid choice! Try again.\n";
		}
	} while (choice != 4);

	return 0;
	
}
