
#include <iostream>
#include <stdexcept>
using namespace std;

// 1. Abstract Base Class
template <class T>
class AbstractQueue {
public:
    virtual void enQueue(T value) = 0;
    virtual T deQueue() = 0;
    virtual T front() const = 0;
    virtual bool isEmpty() const = 0;
    virtual bool isFull() const = 0;

    virtual ~AbstractQueue() {}
};


template <class T>
class myQueue : public AbstractQueue<T> {
private:
    T* arr;
    int capacity;
    int frontIndex;
    int rearIndex;
    int count;

public:
  
    myQueue(int size) {
        capacity = size;
        arr = new T[capacity];

        frontIndex = 0;
        rearIndex = -1;
        count = 0;
    }

    
    ~myQueue() {
        delete[] arr;
    }

    // Insert element at rear
    void enQueue(T value) override {
        if (isFull()) {
            cout << "Queue is Full! Cannot insert.\n";
            return;
        }

        rearIndex = (rearIndex + 1) % capacity;
        arr[rearIndex] = value;
        count++;

        cout << value << " inserted successfully.\n";
    }

    
    T deQueue() override {
        if (isEmpty()) {
            throw underflow_error("Queue is Empty!");
        }

        T value = arr[frontIndex];

        frontIndex = (frontIndex + 1) % capacity;
        count--;

        if (count == 0) {
            frontIndex = 0;
            rearIndex = -1;
        }

        return value;
    }

   
    T front() const override {
        if (isEmpty()) {
            throw underflow_error("Queue is Empty!");
        }

        return arr[frontIndex];
    }

    
    bool isEmpty() const override {
        return count == 0;
    }

  
    bool isFull() const override {
        return count == capacity;
    }

 
    void display() const {
        if (isEmpty()) {
            cout << "Queue is Empty!\n";
            return;
        }

        cout << "Queue elements (Front to Rear): ";

        for (int i = 0; i < count; i++) {
            cout << arr[(frontIndex + i) % capacity] << " ";
        }

        cout << endl;
    }
};


int main() {
    int size;

    cout << "Enter maximum size of Queue: ";
    cin >> size;

    if (size <= 0) {
        cout << "Invalid queue size!\n";
        return 1;
    }

    myQueue<int> q(size);

    int choice, value;

    do {
        cout << "\n===== QUEUE MENU =====\n";
        cout << "1. Enqueue (Insert)\n";
        cout << "2. Dequeue (Remove)\n";
        cout << "3. Front Element\n";
        cout << "4. Check if Empty\n";
        cout << "5. Check if Full\n";
        cout << "6. Display Queue\n";
        cout << "7. Exit\n";

        cout << "Enter your choice: ";
        cin >> choice;

        try {
            switch (choice) {

            case 1:
                cout << "Enter value to insert: ";
                cin >> value;
                q.enQueue(value);
                break;

            case 2:
                cout << "Removed element: "
                    << q.deQueue() << endl;
                break;

            case 3:
                cout << "Front element: "
                    << q.front() << endl;
                break;

            case 4:
                if (q.isEmpty())
                    cout << "Queue is Empty.\n";
                else
                    cout << "Queue is not Empty.\n";
                break;

            case 5:
                if (q.isFull())
                    cout << "Queue is Full.\n";
                else
                    cout << "Queue is not Full.\n";
                break;

            case 6:
                q.display();
                break;

            case 7:
                cout << "Program Terminated.\n";
                break;

            default:
                cout << "Invalid Choice! Try Again.\n";
            }
        }
        catch (const exception& e) {
            cout << "Error: " << e.what() << endl;
        }

    } while (choice != 7);

    return 0;
}

