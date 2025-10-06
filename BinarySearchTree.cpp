#include <iostream>
using namespace std;
struct Node{
	int data;
	Node* left;
	Node* right;
};
Node* createNode(int val)
{
	Node* newNode = new Node();
	newNode->data = val;
	newNode->left = nullptr;
	newNode->right = nullptr;
	return newNode;
}
Node* insert(Node* root, int item)
{
	Node* newNode = createNode(item);
	if(root==nullptr)
	{
		root = newNode;
	}
	else if(item < root->data)
	{
		root->left = insert(root->left,item);
	}
	else{
		root->right = insert(root->right,item);
	}
	return root;	
}
void display(Node* root)
{
	if(root!=nullptr)
	{
		display(root->left);
		cout<<root->data<<" ";
		display(root->right);
	}
}

Node* findMin(Node* root)
{
	while(root->left!=nullptr)
	{
		root = root->left;
	}
	return root;
}

Node* deleteNode(Node* root,int item)
{
	if(root==nullptr)
	{
		return root;
	}
	else if(item < root->data)
	{
		root->left = deleteNode(root->left,item);
	}
	else if(item>root->data)
	{
		root->right = deleteNode(root->right,item);
	}else{
		if(root->left==nullptr)
		{
			Node* temp = root->right;
			delete root;
			return temp;
		}else if(root->right==nullptr)
		{
			Node* temp = root->left;
			delete root;
			return temp;
		}else{
			Node* temp = findMin(root->right);
			root->data = temp->data;
			root->right = deleteNode(root->right,temp->data);
		}
	}
	return root;
}
bool search(Node* root,int item)
{
	if(root==nullptr)
	{
		return false;
	}
	if(item==root->data)
	{
		return true;
	}
	else if(item<root->data)
	{
		return search(root->left,item);
	}
	else{
		return search(root->right,item);
	}
}
int main()
{
	Node* root = NULL;
    int choice, value;

    do {
        cout << "\n--- Binary Search Tree Menu ---\n";
        cout << "1. Insert\n";
        cout << "2. Delete\n";
        cout << "3. Search\n";
        cout << "4. Display (Inorder)\n";
        cout << "5. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Enter value to insert: ";
                cin >> value;
                root = insert(root, value);
                break;

            case 2:
                cout << "Enter value to delete: ";
                cin >> value;
                root = deleteNode(root, value);
                break;

            case 3:
                cout << "Enter value to search: ";
                cin >> value;
                if (search(root, value))
                    cout << "Found!\n";
                else
                    cout << "Not Found!\n";
                break;

            case 4:
                cout << "Inorder Traversal: ";
                display(root);
                cout << endl;
                break;

            case 5:
                cout << "Exiting...\n";
                break;

            default:
                cout << "Invalid choice!\n";
        }
    } while (choice != 5);
	return 0;
}

