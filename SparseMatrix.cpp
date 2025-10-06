#include <iostream>
#include <vector>
using namespace std;


struct Element {
    int row, col, value;
};

class SparseMatrix {
    int rows, cols;
    vector<Element> data; 

public:
    SparseMatrix(int r, int c) {
        rows = r;
        cols = c;
    }

    
    void insert(int r, int c, int val) {
        if (val == 0) return; 

        for (auto &e : data) {
            if (e.row == r && e.col == c) {
                e.value = val; 
                return;
            }
        }
        data.push_back({r, c, val}); 
    }

    void remove(int r, int c) {
        for (int i = 0; i < data.size(); i++) {
            if (data[i].row == r && data[i].col == c) {
                data.erase(data.begin() + i);
                return;
            }
        }
    }

    void display() {
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                bool found = false;
                for (auto &e : data) {
                    if (e.row == i && e.col == j) {
                        cout << e.value << " ";
                        found = true;
                        break;
                    }
                }
                if (!found) {
                	cout << "0 ";	
				}
            }
            cout << endl;
        }
    }

    
    void avgPerStudent() {
        for (int i = 0; i < rows; i++) {
            int sum = 0, count = 0;
            for (auto &e : data) {
                if (e.row == i) {
                    sum += e.value;
                    count++;
                }
            }
            if (count == 0) 
            {
            	cout << "Student " << i+1 << " has no marks\n";
			}
			
            else {
            	cout << "Student " << i+1 << " average = " << (double)sum/count << endl;
			}
        }
    }

    
    void avgPerSubject() {
        for (int j = 0; j < cols; j++) {
            int sum = 0, count = 0;
            for (auto &e : data) {
                if (e.col == j) {
                    sum += e.value;
                    count++;
                }
            }
            if (count == 0) {
            	cout << "Subject " << j+1 << " has no marks\n";
			}
            else cout << "Subject " << j+1 << " average = " << (double)sum/count << endl;
        }
    }
};

int main() {
    SparseMatrix s(4, 4);

   
    s.insert(1, 0, 85);
    s.insert(2, 3, 92);

    cout << "Matrix:\n";
    s.display();

    cout << "\nAverage per Student:\n";
    s.avgPerStudent();

    cout << "\nAverage per Subject:\n";
    s.avgPerSubject();

   
    cout << "\nUpdating (student 1, subject 1 -> 75)\n";
    s.insert(0, 0, 75);
    s.display();

   
    cout << "\nDeleting (student 2, subject 1)\n";
    s.remove(1, 0);
    s.display();

    return 0;
}

