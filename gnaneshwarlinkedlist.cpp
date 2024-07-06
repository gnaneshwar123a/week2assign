
#include <iostream>
#include <vector>

struct Element {
    int row;
    int col;
    int value;
    Element* next;
    Element(int r, int c, int v) : row(r), col(c), value(v), next(nullptr) {}
};

Element* addElement(Element* head, int row, int col, int value) {
    if (value == 0) return head;
    Element* newElement = new Element(row, col, value);
    if (head == nullptr) return newElement;
    Element* temp = head;
    while (temp->next != nullptr) {
        temp = temp->next;
    }
    temp->next = newElement;
    return head;
}

void showMatrix(const std::vector<std::vector<int>>& matrix) {
    for (const auto& row : matrix) {
        for (int val : row) {
            std::cout << val << " ";
        }
        std::cout << std::endl;
    }
}

void showLinkedList(Element* head) {
    std::cout << "Row	Column	Value	Next
";
    std::cout << "--------------------------------
";
    Element* temp = head;
    while (temp != nullptr) {
        std::cout << temp->row << "	" 
                  << temp->col << "	" 
                  << temp->value << "	" 
                  << static_cast<void*>(temp->next) << std::endl;
        temp = temp->next;
    }
}

void clearList(Element* head) {
    Element* temp = head;
    while (temp != nullptr) {
        Element* next = temp->next;
        delete temp;
        temp = next;
    }
}

int main() {
    int numRows, numCols;
    std::cout << "Number of rows: ";
    std::cin >> numRows;
    std::cout << "Number of columns: ";
    std::cin >> numCols;

    std::vector<std::vector<int>> mat(numRows, std::vector<int>(numCols));
    for (int i = 0; i < numRows; ++i) {
        for (int j = 0; j < numCols; ++j) {
            std::cout << "Element [" << i << "][" << j << "]: ";
            std::cin >> mat[i][j];
        }
    }

    std::cout << "Matrix:
";
    showMatrix(mat);

    Element* head = nullptr;
    for (int i = 0; i < numRows; ++i) {
        for (int j = 0; j < numCols; ++j) {
            head = addElement(head, i, j, mat[i][j]);
        }
    }

    std::cout << "Linked List:
";
    showLinkedList(head);

    clearList(head);

    return 0;
}
