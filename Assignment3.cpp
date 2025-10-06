#include <iostream>
using namespace std;

struct Node{
	int pId;
	string pName;
	string condition;
	Node* next;
};

Node* createNode(int id, string n, string c)
{
	Node* newNode = new Node();
	newNode->pId = id;
	newNode->pName = n;
	newNode->condition = c;
	newNode->next = nullptr;
	return newNode;
}

void addPatient(Node*& head,int id, string n, string c)
{
	Node* patient = createNode(id,n,c);
	if(head==nullptr)
	{
		head = patient;
		return;
	}
	Node* temp = head;
	while(temp->next!=nullptr)
	{
		temp=temp->next;
	}
	temp->next = patient;
	cout<<"New Patient Added\n";
}

void removePatient(Node*& head)
{
	if(head==nullptr)
	{
		"No available Patient\n";
		return;
	}
	Node* temp = head;
	head = head->next;
	delete temp;
	cout<<"Patient Removed Successfully!!\n";
}

void displayQueue(Node* head) {
    if (head == nullptr) {
        cout << "No Patients in Queue\n";
        return;
    }
    cout << "Patient Details :\n";
    Node* temp = head;
    while (temp != nullptr) {
        cout << "ID: " << temp->pId 
             << "  Name: " << temp->pName 
             << "  Condition: " << temp->condition << endl;
        temp = temp->next;
    }
}

void searchPatient(Node* head, int id) {
    Node* temp = head;
    while (temp != nullptr) {
        if (temp->pId == id) {
            cout << "Patient Found!!!\n";
            cout << "ID: " << temp->pId 
                 << "  Name: " << temp->pName 
                 << "  Condition: " << temp->condition << endl;
            return;
        }
        temp = temp->next;
    }
    cout << "Patient with ID " << id << " not found.\n";
}

void updatePatient(Node* head, int id, string newName, string newCondition) {
    Node* temp = head;
    while (temp != nullptr) {
        if (temp->pId == id) {
            temp->pName = newName;
            temp->condition = newCondition;
            cout << "Patient Information Updated Successfully!\n";
            return;
        }
        temp = temp->next;
    }
    cout << "Patient not found for update.\n";
}


int main() {
    Node* head = nullptr;
    int choice, id;
    string name, condition;

    do {
        cout << "\n--- Hospital Management ---\n";
        cout << "1. Add Patient\n";
        cout << "2. Remove Patient\n";
        cout << "3. Display Queue\n";
        cout << "4. Search Patient\n";
        cout << "5. Update Patient Information\n";
        cout << "6. Exit\n";
        cout << "Enter choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Enter ID: ";
                cin >> id;
                cout << "Enter Name: ";
                cin >> name;
                cout << "Enter Condition: ";
                cin >> condition;
                addPatient(head, id, name, condition);
                break;

            case 2:
                removePatient(head);
                break;

            case 3:
                displayQueue(head);
                break;

            case 4:
                cout << "Enter ID to search: ";
                cin >> id;
                searchPatient(head, id);
                break;

            case 5:
                cout << "Enter ID to update: ";
                cin >> id;
                cout << "Enter new Name: ";
                cin >> name;
                cout << "Enter new Condition: ";
                cin >> condition;
                updatePatient(head, id, name, condition);
                break;

            case 6:
                cout << "Exiting..\n";
                break;

            default:
                cout << "Invalid Choice!\n";
        }
    } while (choice != 6);

    return 0;
}
