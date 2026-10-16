
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;


class LibraryItem {
public:
    virtual void display() const = 0;
    virtual ~LibraryItem() {}
};


class Book : public LibraryItem {
private:
    string title;
    string author;
    int pages;

public:
    Book(string t, string a, int p)
        : title(t), author(a), pages(p) {}

    string getTitle() const { return title; }
    string getAuthor() const { return author; }
    int getPages() const { return pages; }

    void display() const override {
        cout << "Title: " << title << endl;
        cout << "Author: " << author << endl;
        cout << "Pages: " << pages << endl;
    }
};


class Newspaper : public LibraryItem {
private:
    string name;
    string date;
    string edition;

public:
    Newspaper(string n, string d, string e)
        : name(n), date(d), edition(e) {}

    string getName() const { return name; }
    string getDate() const { return date; }
    string getEdition() const { return edition; }

    void display() const override {
        cout << "Name: " << name << endl;
        cout << "Date: " << date << endl;
        cout << "Edition: " << edition << endl;
    }
};


template <class T, class Key, class Getter>
T* linearSearch(vector<T>& items, const Key& key,
    Getter getKey) {
    for (T& item : items) {
        if (getKey(item) == key) {
            return &item;
        }
    }
    return nullptr;
}


template <class T, class Key, class Getter>
T* binarySearch(vector<T>& items, const Key& key,
    Getter getKey) {
    int low = 0;
    int high = static_cast<int>(items.size()) - 1;

    while (low <= high) {
        int mid = low + (high - low) / 2;
        auto midKey = getKey(items[mid]);

        if (midKey == key) {
            return &items[mid];
        }
        else if (midKey < key) {
            low = mid + 1;
        }
        else {
            high = mid - 1;
        }
    }

    return nullptr;
}


class Library {
private:
    vector<Book> books;
    vector<Newspaper> newspapers;

public:
    void addBook(const Book& book) {
        books.push_back(book);
    }

    void addNewspaper(const Newspaper& newspaper) {
        newspapers.push_back(newspaper);
    }

    void displayCollection() const {
        cout << "\n--- Books ---\n";
        for (const Book& b : books) {
            b.display();
            cout << endl;
        }

        cout << "--- Newspapers ---\n";
        for (const Newspaper& n : newspapers) {
            n.display();
            cout << endl;
        }
    }

    void sortBooksByPages() {
        sort(books.begin(), books.end(),
            [](const Book& a, const Book& b) {
                return a.getPages() < b.getPages();
            });
    }

    void sortNewspapersByEdition() {
        sort(newspapers.begin(), newspapers.end(),
            [](const Newspaper& a, const Newspaper& b) {
                return a.getEdition() < b.getEdition();
            });
    }


    Book* searchBookByTitle(const string& title) {
        return linearSearch(
            books, title,
            [](const Book& b) {
                return b.getTitle();
            }
        );
    }


    Newspaper* searchNewspaperByName(const string& name) {
        vector<Newspaper> sortedNews = newspapers;


        sort(sortedNews.begin(), sortedNews.end(),
            [](const Newspaper& a, const Newspaper& b) {
                return a.getName() < b.getName();
            });

        Newspaper* found = binarySearch(
            sortedNews, name,
            [](const Newspaper& n) {
                return n.getName();
            }
        );

        if (found == nullptr) {
            return nullptr;
        }
