#ifndef BOOK_H
#define BOOK_H
#include <string>
#include <stdexcept>
using namespace std;

class LibraryException : public exception {
private:
    string message;
public:
    explicit LibraryException(const string &msg) : message(msg) {}
    const char *what() const noexcept override {
        return message.c_str();
    }
};

class Book {
private:
    string title;
    string author;
    string isbn;
    bool is_borrowed;

public:
    Book(const string &title, const string &author, const string &isbn);
    string getTitle() const;
    string getAuthor() const;
    string getISBN() const;
    bool isBorrowed() const;
    void borrow();
    void returnBook();
    string toString() const;
};

#endif