
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
    T* minArr;
    int maxSize;
    int currentSize;

public:
    myStack(int size) {
        maxSize = size;
        currentSize = 0;
        arr = new T[maxSize];
        minArr = new T[maxSize];
    }

    ~myStack() {
        delete[] arr;
        delete[] minArr;
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

        arr[currentSize] = value;

        if (currentSize == 0)
            minArr[currentSize] = value;
        else if (value < minArr[currentSize - 1])
            minArr[currentSize] = value;
        else
            minArr[currentSize] = minArr[currentSize - 1];

        currentSize++;
        cout << "Element pushed.\n";
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

    T getMin() const {
        if (isEmpty()) {
            cout << "Stack is empty!\n";
            return T();
        }

        return minArr[currentSize - 1];
    }

    void display() const {
        if (isEmpty()) {
            cout << "Stack is empty.\n";
            return;
        }

        cout << "Stack (top to bottom): ";
        for (int i = currentSize - 1; i >= 0; i--)
            cout << arr[i] << " ";
        cout << endl;
    }
};

int main() {
    myStack<int> s(10);
    int choice, value;

    do {
        cout << "\n--- MINIMUM STACK MENU ---\n";
        cout << "1. Push element\n";
        cout << "2. Pop element\n";
        cout << "3. Show top element\n";
        cout << "4. Check empty\n";
        cout << "5. Check full\n";
        cout << "6. Display stack\n";
        cout << "7. Show minimum element\n";
        cout << "8. Exit\n";
        cout << "Enter choice: ";
        cin >> choice;

        switch (choice) {
        case 1:
            cout << "Enter value: ";
            cin >> value;
            s.push(value);
            break;

        case 2:
            if (!s.isEmpty())
                cout << "Removed: " << s.pop() << endl;
            else
                cout << "Cannot pop: stack is empty.\n";
            break;

        case 3:
            if (!s.isEmpty())
                cout << "Top: " << s.top() << endl;
            else
                cout << "Stack is empty.\n";
            break;

        case 4:
            cout << (s.isEmpty() ? "Yes, empty\n"
                : "No, not empty\n");
            break;

        case 5:
            cout << (s.isFull() ? "Yes, full\n"
                : "No, not full\n");
            break;

        case 6:
            s.display();
            break;

        case 7:
            if (!s.isEmpty())
                cout << "Minimum: " << s.getMin() << endl;
            else
                cout << "Stack is empty.\n";
            break;

        case 8:
            cout << "Program ended.\n";
            break;

        default:
            cout << "Invalid choice.\n";
        }
    } while (choice != 8);

    return 0;
}
