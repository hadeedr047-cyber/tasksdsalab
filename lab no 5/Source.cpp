
#include <iostream>
#include <queue>
using namespace std;

int main() {
    queue<int> tickets;
    int choice, ticket_id;

    do
    {
        cout << "\n--- Customer Support Ticket System ---\n";
        cout << "1. Add a new ticket\n";
        cout << "2. Resolve a ticket\n";
        cout << "3. Check next ticket\n";
        cout << "4. Display all pending tickets\n";
        cout << "5. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice)
        {
        case 1:
            cout << "Enter 4-digit ticket ID: ";
            cin >> ticket_id;

            if (ticket_id >= 1000 && ticket_id <= 9999)
            {
                tickets.push(ticket_id);
                cout << "Ticket added successfully.\n";
            }
            else
            {
                cout << "Invalid ID! Enter a 4-digit number.\n";
            }
            break;

        case 2:
            if (tickets.empty())
            {
                cout << "No tickets to resolve.\n";
            }
            else
            {
                cout << "Ticket "
                    << tickets.front()
                    << " resolved successfully.\n";
                tickets.pop();
            }
            break;

        case 3:
            if (tickets.empty())
            {
                cout << "No pending tickets.\n";
            }
            else
            {
                cout << "Next ticket: "
                    << tickets.front() << endl;
            }
            break;

        case 4:
            if (tickets.empty())
            {
                cout << "No pending tickets.\n";
            }
            else
            {
                queue<int> temp = tickets;

                cout << "Pending tickets: ";

                while (!temp.empty())
                {
                    cout << temp.front() << " ";
                    temp.pop();
                }

                cout << endl;
            }
            break;

        case 5:
            cout << "Program ended.\n";
            break;

        default:
            cout << "Invalid choice!\n";
        }

    } while (choice != 5);

    return 0;
}