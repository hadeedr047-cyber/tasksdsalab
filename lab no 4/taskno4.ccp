
#include <iostream>
#include <string>
using namespace std;

class TextStack {
private:
    string* arr;
    int maxSize;
    int currentSize;

public:
    TextStack(int size = 1000) {
        maxSize = size;
        currentSize = 0;
        arr = new string[maxSize];
    }

    ~TextStack() {
        delete[] arr;
    }

    bool isEmpty() const {
        return currentSize == 0;
    }

    bool isFull() const {
        return currentSize == maxSize;
    }

    void push(string value) {
        if (isFull()) {
            cout << "History stack is full!\n";
            return;
        }

        arr[currentSize++] = value;
    }

    string pop() {
        if (isEmpty())
            return "";

        return arr[--currentSize];
    }

    void clear() {
        currentSize = 0;
    }
};

int main() {
    string text = "";
    string input;
    int choice;

    TextStack undoStack;
    TextStack redoStack;

    do {
        cout << "\n--- TEXT EDITOR ---\n";
        cout << "Current text: [" << text << "]\n";
        cout << "1. Type text\n";
        cout << "2. Delete last character\n";
        cout << "3. Undo\n";
        cout << "4. Redo\n";
        cout << "5. Display text\n";
        cout << "6. Exit\n";
        cout << "Enter choice: ";
        cin >> choice;

        switch (choice) {
        case 1:
            cout << "Enter text to add: ";
            getline(cin >> ws, input);

            
            if (undoStack.isFull()) {
                cout << "Undo history is full!\n";
                break;
            }

            undoStack.push(text);
            text += input;

            
            redoStack.clear();

            cout << "Text added successfully.\n";
            break;

        case 2:
            if (text.empty()) {
                cout << "No text to delete.\n";
                break;
            }

            if (undoStack.isFull()) {
                cout << "Undo history is full!\n";
                break;
            }

            undoStack.push(text);
            text.pop_back();
            redoStack.clear();

            cout << "Last character deleted.\n";
            break;

        case 3:
            if (undoStack.isEmpty()) {
                cout << "Nothing to undo.\n";
                break;
            }

            if (redoStack.isFull()) {
                cout << "Redo history is full!\n";
                break;
            }

            
            redoStack.push(text);

            
            text = undoStack.pop();

            cout << "Undo successful.\n";
            break;

        case 4:
            if (redoStack.isEmpty()) {
                cout << "Nothing to redo.\n";
                break;
            }

            if (undoStack.isFull()) {
                cout << "Undo history is full!\n";
                break;
            }

            
            undoStack.push(text);

            
            text = redoStack.pop();

            cout << "Redo successful.\n";
            break;

        case 5:
            cout << "Current text: " << text << endl;
            break;

        case 6:
            cout << "Text editor closed.\n";
            break;

        default:
            cout << "Invalid choice.\n";
        }

    } while (choice != 6);

    return 0;
}
