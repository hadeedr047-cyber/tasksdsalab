
#include <iostream>
using namespace std;

template <typename T>
class AbstractStack {
public:
    virtual void push(T value) = 0;
    virtual T pop() = 0;
    virtual T top() const = 0;
    virtual bool isEmpty() const = 0;
    virtual bool isFull() const = 0;
    virtual ~AbstractStack() {}
};

template <typename T>
class myStack : public AbstractStack<T> {
private:
    T* arr;
    int maxSize;
    int currentSize;

public:
    myStack(int size) {
        maxSize = size;
        currentSize = 0;
        arr = new T[maxSize];
    }

    ~myStack() {
        delete[] arr;
    }

    bool isEmpty() const override {
        return currentSize == 0;
    }

    bool isFull() const override {
        return currentSize == maxSize;
    }

    void push(T value) override {
        if (isFull()) {
            cout << "Stack is full!\n";
            return;
        }

        arr[currentSize++] = value;
        cout << "Element pushed successfully.\n";
    }

    T pop() override {
        if (isEmpty()) {
            cout << "Stack is empty!\n";
            return T();
        }

        return arr[--currentSize];
    }

    T top() const override {
        if (isEmpty()) {
            cout << "Stack is empty!\n";
            return T();
        }

        return arr[currentSize - 1];
    }

    void display() const {
        if (isEmpty()) {
            cout << "Stack is empty.\n";
            return;
        }

        cout << "Stack (top to bottom): ";
        for (int i = currentSize - 1; i >= 0; i--) {
            cout << arr[i] << " ";
        }
        cout << endl;
    }
};

int main() {
    myStack<int> s(5);
    int choice, value;

    do {
        cout << "\n--- STACK MENU ---\n";
        cout << "1. Push\n";
        cout << "2. Pop\n";
        cout << "3. Show Top\n";
        cout << "4. Check Empty\n";
        cout << "5. Check Full\n";
        cout << "6. Display\n";
        cout << "7. Exit\n";
        cout << "Enter choice: ";
        cin >> choice;

        switch (choice) {
        case 1:
            cout << "Enter value: ";
            cin >> value;
            s.push(value);
            break;

        case 2:
            cout << "Removed: " << s.pop() << endl;
            break;

        case 3:
            cout << "Top: " << s.top() << endl;
            break;

        case 4:
            cout << (s.isEmpty() ? "Stack is empty\n"
                : "Stack is not empty\n");
            break;

        case 5:
            cout << (s.isFull() ? "Stack is full\n"
                : "Stack is not full\n");
            break;

        case 6:
            s.display();
            break;

        case 7:
            cout << "Program ended.\n";
            break;

        default:
            cout << "Invalid choice.\n";
        }
    } while (choice != 7);

    return 0;
}
