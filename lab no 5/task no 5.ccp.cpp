
#include <iostream>
#include <queue>
#include <string>
using namespace std;

int main()
{
    queue<string> documents;
    int choice;
    string document_name;

    do
    {
        cout << "\n--- Document Printing System ---\n";
        cout << "1. Add a print job\n";
        cout << "2. Print a document\n";
        cout << "3. Check the next document\n";
        cout << "4. Display all print jobs\n";
        cout << "5. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice)
        {
        case 1:
            cout << "Enter document name: ";
            cin >> ws;
            getline(cin, document_name);

            documents.push(document_name);
            cout << "Document added successfully.\n";
            break;

        case 2:
            if (documents.empty())
            {
                cout << "No documents to print.\n";
            }
            else
            {
                cout << "Printing document: "
                    << documents.front() << endl;
                documents.pop();
            }
            break;

        case 3:
            if (documents.empty())
            {
                cout << "No documents in the queue.\n";
            }
            else
            {
                cout << "Next document to print: "
                    << documents.front() << endl;
            }
            break;

        case 4:
            if (documents.empty())
            {
                cout << "No print jobs pending.\n";
            }
            else
            {
                queue<string> temp = documents;

                cout << "Remaining print jobs:\n";

                while (!temp.empty())
                {
                    cout << temp.front() << endl;
                    temp.pop();
                }
            }
            break;

        case 5:
            cout << "Program ended.\n";
            break;

        default:
            cout << "Invalid choice! Try again.\n";
        }

    } while (choice != 5);

    return 0;
}