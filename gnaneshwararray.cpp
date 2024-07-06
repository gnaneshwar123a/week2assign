
#include <iostream>
#include <vector>
#include <iomanip>

using namespace std;

// Define a structure to store non-zero elements
struct NonZeroEntry {
    int r;
    int c;
    int val;
};

class SparseMatrix {
private:
    vector<NonZeroEntry> entries;
    vector<vector<int>> originalMatrix;
    int rowCount;
    int colCount;

public:
    // Constructor initializes the original matrix size
    SparseMatrix(int rows, int cols) : rowCount(rows), colCount(cols), originalMatrix(rows, vector<int>(cols, 0)) {}

    // Function to read a sparse matrix from user input
    void inputMatrix() {
        cout << "Enter the elements for a " << rowCount << "x" << colCount << " matrix:" << endl;
        int i = 0;
        while (i < rowCount) {
            int j = 0;
            while (j < colCount) {
                cout << "Enter element for Row [" << i << "] Column [" << j << "]: ";
                cin >> originalMatrix[i][j];
                if (originalMatrix[i][j] != 0) {
                    entries.push_back({i, j, originalMatrix[i][j]});
                }
                ++j;
            }
            ++i;
        }
    }

    // Function to display the original full matrix
    void showFullMatrix() {
        cout << "\nMatrix Entered" << endl;
        for (auto &row : originalMatrix) {
            for (auto elem : row) {
                cout << setw(5) << elem;
            }
            cout << endl;
        }
    }

    // Function to display the sparse matrix representation
    void showSparseMatrix() {
        cout << "\nSparse Matrix Representation:" << endl;
        cout << "Row\tColumn\tValue\n";
        for (auto &entry : entries) {
            cout << setw(4) << entry.r << '\t' 
                 << setw(6) << entry.c << '\t' 
                 << setw(5) << entry.val << endl;
        }
    }
};

int main() {
    int rowNum, colNum;
    cout << "Enter total number of rows: ";
    cin >> rowNum;
    cout << "Enter total number of columns: ";
    cin >> colNum;

    // Create a SparseMatrix object
    SparseMatrix sparseMatrix(rowNum, colNum);

    // Read matrix from user input
    sparseMatrix.inputMatrix();

    // Display the original full matrix
    sparseMatrix.showFullMatrix();

    // Display the sparse matrix representation
    sparseMatrix.showSparseMatrix();

    return 0;
}
