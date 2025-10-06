#include <iostream>
using namespace std;

class ProductList {
    struct Node {
        int id;
        string name;
        int quantity;
        float price;
        Node* next;
    };
    Node* head;

public:
    ProductList() { 
		head = nullptr;
	 }

    void addProduct(int id, string name, int qty, float price) {
        Node* n = new Node();
        n->id = id;
        n->name = name;
        n->quantity = qty;
        n->price = price;
        n->next = nullptr;

        if (head == nullptr) {
            head = n;
            return;
        }

        Node* temp = head;
        while (temp->next != nullptr)
            temp = temp->next;
        temp->next = n;
    }

    
    void updateQuantity(int id, int newQty) {
        Node* temp = head;
        while (temp != nullptr) {
            if (temp->id == id) {
                temp->quantity = newQty;
                cout << "Quantity updated for Product ID " << id << "\n";
                return;
            }
            temp = temp->next;
        }
        cout << "Product ID " << id << " not found!\n";
    }


    void calculateTotalValue() {
        float total = 0;
        Node* temp = head;
        while (temp != nullptr) {
            total += temp->quantity * temp->price;
            temp = temp->next;
        }
        cout << "Total Stock Value = " << total << endl;
    }

    void display() {
        if (head == nullptr) {
            cout << "No products in list!\n";
            return;
        }
        Node* temp = head;
        cout << "\nProduct List:\n";
        while (temp != nullptr) {
            cout << "ID: " << temp->id
                 << ", Name: " << temp->name
                 << ", Qty: " << temp->quantity
                 << ", Price: " << temp->price
                 << "\n";
            temp = temp->next;
        }
    }
};

int main() {
    ProductList list;
    int choice;

    do {
        cout << "\n--- Product Management Menu ---\n";
        cout << "1. Add Product\n";
        cout << "2. Update Quantity\n";
        cout << "3. Display Products\n";
        cout << "4. Calculate Total Value\n";
        cout << "5. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        if (choice == 1) {
            int id, qty;
            string name;
            float price;
            cout << "Enter Product ID: ";
            cin >> id;
            cout << "Enter Product Name: ";
            cin >> name;
            cout << "Enter Quantity: ";
            cin >> qty;
            cout << "Enter Price: ";
            cin >> price;
            list.addProduct(id, name, qty, price);
        } 
        else if (choice == 2) {
            int id, qty;
            cout << "Enter Product ID to update: ";
            cin >> id;
            cout << "Enter new Quantity: ";
            cin >> qty;
            list.updateQuantity(id, qty);
        } 
        else if (choice == 3) {
            list.display();
        } 
        else if (choice == 4) {
            list.calculateTotalValue();
        } 
        else if (choice == 5) {
            cout << "Exiting program...\n";
        } 
        else {
            cout << "Invalid choice! Try again.\n";
        }
    } while (choice != 5);

    return 0;
}
