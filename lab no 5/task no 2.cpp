
#include <iostream>
#include <stack>
using namespace std;

class Queue {
private:
    stack<int> s1, s2;

public:
   
    void enqueue(int value) {
        s1.push(value);
        cout << value << " inserted into queue.\n";
    }

    
    void dequeue() {
        if (s1.empty() && s2.empty()) {
            cout << "Queue is empty!\n";
            return;
        }

        if (s2.empty()) {
            while (!s1.empty()) {
                s2.push(s1.top());
                s1.pop();
            }
        }

        cout << "Deleted element: " << s2.top() << endl;
        s2.pop();
    }

    
    void frontElement() {
        if (s1.empty() && s2.empty()) {
            cout << "Queue is empty!\n";
            return;
        }

        if (s2.empty()) {
            while (!s1.empty()) {
                s2.push(s1.top());
                s1.pop();
            }
        }

        cout << "Front element: " << s2.top() << endl;
    }

   
    void display() {
        if (s1.empty() && s2.empty()) {
            cout << "Queue is empty!\n";
            return;
        }

        cout << "Queue elements: ";

        stack<int> temp = s2;

        while (!temp.empty()) {
            cout << temp.top() << " ";
            temp.pop();
        }

        temp = s1;
        stack<int> reverseStack;

        while (!temp.empty()) {
            reverseStack.push(temp.top());
            temp.pop();
        }

        while (!reverseStack.empty()) {
            cout << reverseStack.top() << " ";
            reverseStack.pop();
        }

        cout << endl;
    }
};

int main() {
    Queue q;
    int choice, value;

    do {
        cout << "\n--- Queue Using Two Stacks ---\n";
        cout << "1. Enqueue\n";
        cout << "2. Dequeue\n";
        cout << "3. Front Element\n";
        cout << "4. Display Elements\n";
        cout << "5. Exit\n";

        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
        case 1:
            cout << "Enter value: ";
            cin >> value;
            q.enqueue(value);
            break;

        case 2:
            q.dequeue();
            break;

        case 3:
            q.frontElement();
            break;

        case 4:
            q.display();
            break;

        case 5:
            cout << "Program terminated.\n";
            break;

        default:
            cout << "Invalid choice!\n";
        }

    } while (choice != 5);

    return 0;
}
