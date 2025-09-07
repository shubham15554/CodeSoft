#include <iostream>
#include <vector>
#include <string>
using namespace std;

// Book structure
struct Book {
    string title;
    string author;
    string ISBN;
    bool available = true;
    int daysBorrowed = 0; // used for fine calculation
};

// Library system class
class Library {
private:
    vector<Book> books;

public:
    // Add a new book
    void addBook() {
        Book newBook;
        cout << "Enter Book Title: ";
        cin.ignore();
        getline(cin, newBook.title);
        cout << "Enter Author: ";
        getline(cin, newBook.author);
        cout << "Enter ISBN: ";
        getline(cin, newBook.ISBN);
        newBook.available = true;
        books.push_back(newBook);
        cout << "Book added successfully!\n";
    }

    // View all books
    void viewBooks() {
        if (books.empty()) {
            cout << "No books in the library.\n";
            return;
        }
        cout << "\nAvailable Books:\n";
        for (size_t i = 0; i < books.size(); i++) {
            cout << i + 1 << ". " << books[i].title << " by " << books[i].author
                 << " [ISBN: " << books[i].ISBN << "] - "
                 << (books[i].available ? "Available" : "Checked out") << "\n";
        }
    }

    // Search for a book
    void searchBook() {
        string keyword;
        cout << "Enter title, author, or ISBN to search: ";
        cin.ignore();
        getline(cin, keyword);

        bool found = false;
        for (auto &book : books) {
            if (book.title == keyword || book.author == keyword || book.ISBN == keyword) {
                cout << "Book found: " << book.title << " by " << book.author
                     << " [ISBN: " << book.ISBN << "] - "
                     << (book.available ? "Available" : "Checked out") << "\n";
                found = true;
            }
        }
        if (!found) cout << "No book found with that detail.\n";
    }

    // Check out a book
    void checkoutBook() {
        string isbn;
        cout << "Enter ISBN of the book to check out: ";
        cin.ignore();
        getline(cin, isbn);

        for (auto &book : books) {
            if (book.ISBN == isbn) {
                if (book.available) {
                    book.available = false;
                    cout << "Enter number of days to borrow: ";
                    cin >> book.daysBorrowed;
                    cout << "Book checked out successfully!\n";
                } else {
                    cout << "Book is already checked out.\n";
                }
                return;
            }
        }
        cout << "Book not found.\n";
    }

    // Return a book
    void returnBook() {
        string isbn;
        cout << "Enter ISBN of the book to return: ";
        cin.ignore();
        getline(cin, isbn);

        for (auto &book : books) {
            if (book.ISBN == isbn) {
                if (!book.available) {
                    int overdueDays;
                    cout << "Enter actual number of days borrowed: ";
                    cin >> overdueDays;

                    if (overdueDays > book.daysBorrowed) {
                        int fine = (overdueDays - book.daysBorrowed) * 10; // fine = ₹10 per day
                        cout << "Book returned late! Fine = Rs. " << fine << "\n";
                    } else {
                        cout << "Book returned on time. No fine.\n";
                    }

                    book.available = true;
                    book.daysBorrowed = 0;
                } else {
                    cout << "This book was not checked out.\n";
                }
                return;
            }
        }
        cout << "Book not found.\n";
    }
};

// Main Menu
int main() {
    Library lib;
    int choice;

    do {
        cout << "\n===== LIBRARY MANAGEMENT SYSTEM =====\n";
        cout << "1. Add Book\n";
        cout << "2. View Books\n";
        cout << "3. Search Book\n";
        cout << "4. Checkout Book\n";
        cout << "5. Return Book\n";
        cout << "6. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1: lib.addBook(); break;
            case 2: lib.viewBooks(); break;
            case 3: lib.searchBook(); break;
            case 4: lib.checkoutBook(); break;
            case 5: lib.returnBook(); break;
            case 6: cout << "Exiting... Goodbye!\n"; break;
            default: cout << "Invalid choice. Try again!\n";
        }
    } while (choice != 6);

    return 0;
}
