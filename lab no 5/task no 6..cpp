
#include <iostream>
#include <queue>
#include <string>
using namespace std;

struct Package
{
    int packageID;
    string address;
    int startTime;
    int endTime;
};

class DeliverySystem
{
private:
    queue<Package> packages;

public:
    
    void enqueue(int id, string address, int start, int end)
    {
        Package p;
        p.packageID = id;
        p.address = address;
        p.startTime = start;
        p.endTime = end;

        packages.push(p);

        cout << "Package added successfully.\n";
    }

   
    void front()
    {
        if (packages.empty())
        {
            cout << "No packages available.\n";
            return;
        }

        Package p = packages.front();

        cout << "Front Package ID: " << p.packageID << endl;
        cout << "Address: " << p.address << endl;
        cout << "Delivery Window: "
            << p.startTime << " - " << p.endTime << endl;
    }

    
    void display()
    {
        if (packages.empty())
        {
            cout << "No packages in the queue.\n";
            return;
        }

        queue<Package> temp = packages;

        cout << "\nPackages in Queue:\n";

        while (!temp.empty())
        {
            Package p = temp.front();

            cout << "Package ID: " << p.packageID << endl;
            cout << "Address: " << p.address << endl;
            cout << "Delivery Window: "
                << p.startTime << " - " << p.endTime << endl;
            cout << "----------------------\n";

            temp.pop();
        }
    }

    
    void timeToDeliver(int currentTime)
    {
        while (!packages.empty())
        {
            Package p = packages.front();

            if (currentTime < p.startTime)
            {
                cout << "Package " << p.packageID
                    << " is not ready for delivery yet.\n";
                return;
            }

            if (currentTime > p.endTime)
            {
                cout << "Package " << p.packageID
                    << " has expired. Skipping package.\n";

                packages.pop();
                continue;
            }

            cout << "Package " << p.packageID
                << " can be delivered now.\n";
            return;
        }

        cout << "No packages available for delivery.\n";
    }

    
    void dequeue(int currentTime)
    {
        while (!packages.empty())
        {
            Package p = packages.front();

            if (currentTime > p.endTime)
            {
                cout << "Package " << p.packageID
                    << " has expired. Removing package.\n";

                packages.pop();
                continue;
            }

            if (currentTime < p.startTime)
            {
                cout << "Package " << p.packageID
                    << " is not ready for delivery.\n";
                return;
            }

            cout << "Package " << p.packageID
                << " delivered successfully to "
                << p.address << ".\n";

            packages.pop();
            return;
        }

        cout << "No packages to deliver.\n";
    }
};

int main()
{
    DeliverySystem ds;
    int choice, id, start, end, currentTime;
    string address;

    do
    {
        cout << "\n===== Package Delivery System =====\n";
        cout << "1. Add Package\n";
        cout << "2. Deliver Package\n";
        cout << "3. View Front Package\n";
        cout << "4. Display All Packages\n";
        cout << "5. Check Delivery Time\n";
        cout << "6. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice)
        {
        case 1:
            cout << "Enter Package ID: ";
            cin >> id;

            cout << "Enter Delivery Address: ";
            cin >> ws;
            getline(cin, address);

            cout << "Enter Start Time (0-23): ";
            cin >> start;

            cout << "Enter End Time (0-23): ";
            cin >> end;

            if (start < 0 || start > 23 ||
                end < 0 || end > 23 || start > end)
            {
                cout << "Invalid delivery time window.\n";
                break;
            }

            ds.enqueue(id, address, start, end);
            break;

        case 2:
            cout << "Enter Current Time (0-23): ";
            cin >> currentTime;

            if (currentTime < 0 || currentTime > 23)
            {
                cout << "Invalid current time.\n";
                break;
            }

            ds.dequeue(currentTime);
            break;

        case 3:
            ds.front();
            break;

        case 4:
            ds.display();
            break;

        case 5:
            cout << "Enter Current Time (0-23): ";
            cin >> currentTime;

            if (currentTime < 0 || currentTime > 23)
            {
                cout << "Invalid current time.\n";
                break;
            }

            ds.timeToDeliver(currentTime);
            break;

        case 6:
            cout << "Exiting program.\n";
            break;

        default:
            cout << "Invalid choice. Try again.\n";
        }

    } while (choice != 6);

    return 0;
}
