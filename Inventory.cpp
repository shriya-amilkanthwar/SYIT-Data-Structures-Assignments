#include <iostream>
#include <string>
using namespace std;

struct Product {
    int id;
    string name;
    int quantity;
    float price;
    Product* next;  // pointer for linked list
};

class Inventory {
    Product* head;

public:
    Inventory() {
        head = nullptr;
    }

    // Add product at end
    void addProduct(int id, string name, int qty, float price) {
        Product* newProd = new Product;
        newProd->id = id;
        newProd->name = name;
        newProd->quantity = qty;
        newProd->price = price;
        newProd->next = nullptr;

        if (head == nullptr) {
            head = newProd;
        } else {
            Product* temp = head;
            while (temp->next != nullptr) {
                temp = temp->next;
            }
            temp->next = newProd;
        }
        cout << "Product Added: " << name << endl;
    }

    // Update quantity
    void updateQuantity(int id, int newQty) {
        Product* temp = head;
        while (temp != nullptr) {
            if (temp->id == id) {
                temp->quantity = newQty;
                cout << "Quantity Updated for " << temp->name << endl;
                return;
            }
            temp = temp->next;
        }
        cout << "Product not found!" << endl;
    }

    // Calculate total inventory value
    void calculateTotalValue() {
        float total = 0;
        Product* temp = head;
        while (temp != nullptr) {
            total += temp->quantity * temp->price;
            temp = temp->next;
        }
        cout << "Total Inventory Value = " << total << endl;
    }

    // Display all products
    void display() {
        cout << "\nInventory List:\n";
        Product* temp = head;
        while (temp != nullptr) {
            cout << "ID: " << temp->id
                 << ", Name: " << temp->name
                 << ", Qty: " << temp->quantity
                 << ", Price: " << temp->price << endl;
            temp = temp->next;
        }
    }
};

int main() {
    Inventory inv;

    // Add some products
    inv.addProduct(101, "Laptop", 5, 50000);
    inv.addProduct(102, "Smartphone", 10, 20000);
    inv.addProduct(103, "Charger", 15, 500);

    inv.display();

    // Update quantity
    inv.updateQuantity(102, 12);

    // Calculate total value
    inv.calculateTotalValue();

    inv.display();

    return 0;
}

