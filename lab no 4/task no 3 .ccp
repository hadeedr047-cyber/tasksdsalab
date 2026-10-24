
#include <iostream>
#include <string>
using namespace std;

class myCarStack {
private:
    string* cars;
    int maxSize;
    int currentSize;

public:
    myCarStack(int size = 8) {
        maxSize = size;
        currentSize = 0;
        cars = new string[maxSize];
    }

    ~myCarStack() {
        delete[] cars;
    }

    bool isEmpty() const {
        return currentSize == 0;
    }

    bool isFull() const {
        return currentSize == maxSize;
    }

    int size() const {
        return currentSize;
    }

    void push(string car) {
        if (isFull()) {
            cout << "Parking lot is full!\n";
            return;
        }

        cars[currentSize++] = car;
        cout << "Car parked successfully.\n";
    }

    string pop() {
        if (isEmpty()) {
            cout << "Parking lot is empty!\n";
            return "";
        }

        return cars[--currentSize];
    }

    string top() const {
        if (isEmpty())
            return "";

        return cars[currentSize - 1];
    }

    bool search(string car) const {
        for (int i = 0; i < currentSize; i++) {
            if (cars[i] == car)
                return true;
        }
        return false;
    }

    void display() const {
        if (isEmpty()) {
            cout << "No cars parked.\n";
            return;
        }

        cout << "\nCars from top to bottom:\n";
        for (int i = currentSize - 1; i >= 0; i--)
            cout << cars[i] << endl;
    }

    bool removeCar(string car) {
        if (!search(car)) {
            cout << "Car not found!\n";
            return false;
        }

        myCarStack temp(maxSize);

        
        while (top() != car)
            temp.push(pop());

        
        pop();
        cout << "Car " << car << " removed.\n";

       
        while (!temp.isEmpty())
            push(temp.pop());

        return true;
    }
};

int main() {
    myCarStack parking(8);
    int choice;
    string car;

    do {
        cout << "\n--- PARKING LOT MENU ---\n";
        cout << "1. Park a car\n";
        cout << "2. Remove a car by number\n";
        cout << "3. View parked cars\n";
        cout << "4. Total cars parked\n";
        cout << "5. Search for a car\n";
        cout << "6. Show top car\n";
        cout << "7. Exit\n";
        cout << "Enter choice: ";
        cin >> choice;

        switch (choice) {
        case 1:
            cout << "Enter car number: ";
            cin >> car;

            if (parking.search(car))
                cout << "This car is already parked.\n";
            else
                parking.push(car);
            break;

        case 2:
            cout << "Enter car number to remove: ";
            cin >> car;
            parking.removeCar(car);
            break;

        case 3:
            parking.display();
            break;

        case 4:
            cout << "Total cars parked: "
                << parking.size() << "/8\n";
            break;

        case 5:
            cout << "Enter car number to search: ";
            cin >> car;

            if (parking.search(car))
                cout << "Car is present in parking lot.\n";
            else
                cout << "Car is not present.\n";
            break;

        case 6:
            if (parking.isEmpty())
                cout << "No car at the top.\n";
            else
                cout << "Top car: " << parking.top() << endl;
            break;

        case 7:
            cout << "Parking system closed.\n";
            break;

        default:
            cout << "Invalid choice.\n";
        }
    } while (choice != 7);

    return 0;
}
