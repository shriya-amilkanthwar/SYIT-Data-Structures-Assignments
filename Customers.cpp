#include<iostream>
using namespace std;

struct Node{
	int Id;
	string name;
	string service;
	Node* next;
};
class Queue{
	Node* front;
	Node* rear;

	public :
		Queue()
		{
			front = nullptr;
			rear = nullptr;
		
		}
		Node* createNode(int id , string nm , string type)
		{
			Node* newNode = new Node();
			newNode->Id = id;
			newNode->name = nm;
			newNode->service = type;
			newNode->next = nullptr;
			
			return newNode;
		}
		
		bool isEmpty()
		{
			return (front==nullptr);
		}
		
		void insert(int id, string nm , string type)
		{
			Node* newNode = createNode(id,nm,type);
			
			
			if(rear == nullptr)
			{
				front = rear = newNode;
				
			}
			else
			{
				rear->next = newNode;
				rear = newNode;
			}

			
		}
		
		void deleteAtBegin()
		{
			if(isEmpty())
			{
				cout<<"Queue is empty";
				return;
			}
			Node* temp = front;
			cout<<endl<<"Data with id : "<<temp->Id<<" deleted\n"<<endl;
			front = front->next;
			if(front==nullptr)
			{
				rear = nullptr;
			}
			
			delete temp;
			
		}
		void peek()
		{
			if(isEmpty())
			{
				cout<<"Queue is empty";
				return;
			}
				cout<<"The First Customer is : \n";
				cout<<"Id : "<<front->Id<<endl;
				cout<<"Name : "<<front->name<<endl;
				cout<<"Service Type : ";
				cout<<front->service<<endl;
		}
		
		void display()
		{
			if(isEmpty())
			{
				cout<<"Queue is empty";
				return;
			}
			Node* temp = front;
			cout<<"Customer Details : \n";
			while(temp!=nullptr)
			{
				cout<<"Id : "<<temp->Id<<endl;
				cout<<"Name : "<<temp->name<<endl;
				cout<<"Service Type : ";
				cout<<temp->service<<" ";
				temp=temp->next;
				cout<<endl;
			}
		}
		
		void trackRequest(int requestID) {
        if (isEmpty()) {
            cout << "Queue is Empty\n";
            return;
        }

        Node* temp = front;
        bool found = false;

        while (temp != nullptr) {
            if (temp->Id == requestID) {
                cout << "\nRequest Found!\n";
                cout << "Customer ID: " << temp->Id << endl;
                cout << "Customer Name: " << temp->name << endl;
                cout << "Service Type: " << temp->service << endl;
                cout << "Status: In Queue (Pending Service)\n";
                found = true;
                break;
            }
            temp = temp->next;
        }

        if (!found) {
            cout << "Request ID not found in queue\n";
        }
    }
		
};


int main()
{
	Queue q;
	int choice;
	int id;
	string name,type;
	
	do {
		cout << "\n========================================\n";
		cout << "       Customer Service Menu      \n";
		cout << "========================================\n";
		cout << "1. Enqueue\n2. Dequeue\n3. Peek\n4. Display\n5. Track Request\n6. Exit\n";
		cout << "----------------------------------------\n";
		cout << "Enter your choice : ";
		
		cin>>choice;
		
		switch (choice) {
			case 1: { 
				cout<<"Enter Customer Id : ";
				cin>>id;
				cout<<"Enter Customer Name : ";
				cin>>name;
				cout<<"Enter Service Type : ";
				cin>>type;
				q.insert(id,name,type);
				break;
			}
			case 2: 
				q.deleteAtBegin();
				break;
				
			case 3: 
				q.peek();
				break;
				
			case 4: 
				q.display();
				break;
				
			case 5:
				cout << "Enter Request ID to Track: ";
                cin >> id;
                q.trackRequest(id);
                break;
				
			case 6: 
				cout << "\nExiting...\n";
				break;
				
			default:
				cout << "\nInvalid choice.\n";
				break;
		}
		
	} while (choice != 6);
	
	return 0;
}
