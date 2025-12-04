#include <iostream>
using namespace std;

// Class: Author
class Author {
private:
    string name;
    string degree;

public:
    Author(string n = "", string d = "") : name(n), degree(d) {}

    void inputAuthor() {
        cout << "Enter Author Name: ";
        getline(cin, name);
        cout << "Enter Author Degree: ";
        getline(cin, degree);
    }

    void displayAuthor() const {
        cout << "Author Name: " << name << endl;
        cout << "Author Degree: " << degree << endl;
    }
};

// Class: Publication
class Publication {
private:
    string location;
    string name;

public:
    Publication(string l = "", string n = "") : location(l), name(n) {}

    void inputPublication() {
        cout << "Enter Publication Name: ";
        getline(cin, name);
        cout << "Enter Publication Location: ";
        getline(cin, location);
    }

    void displayPublication() const {
        cout << "Publication Name: " << name << endl;
        cout << "Publication Location: " << location << endl;
    }
};

// Class: Book (has-a relationship with Author and Publication)
class Book {
private:
    string bookTitle;
    int noOfPages;
    float price;
    Author author;
    Publication publication;

public:
    void inputBook() {
        cout << "Enter Book Title: ";
        getline(cin, bookTitle);
        cout << "Enter Number of Pages: ";
        cin >> noOfPages;
        cout << "Enter Price: ";
        cin >> price;
        cin.ignore(); // Clear input buffer

        cout << "\n--- Enter Author Details ---\n";
        author.inputAuthor();

        cout << "\n--- Enter Publication Details ---\n";
        publication.inputPublication();
    }

    void displayBook() const {
        cout << "\n--- Book Details ---\n";
        cout << "Title: " << bookTitle << endl;
        cout << "Pages: " << noOfPages << endl;
        cout << "Price: Rs. " << price << endl;

        cout << "\n--- Author Details ---\n";
        author.displayAuthor();

        cout << "\n--- Publication Details ---\n";
        publication.displayPublication();
    }
};

// Main Function
int main() {
    Book myBook;

    myBook.inputBook();
    myBook.displayBook();

    return 0;
}

