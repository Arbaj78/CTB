
#include "Book.h"

Book::Book(const string &title, const string &author, const string &isbn)
    : title(title), author(author), isbn(isbn), is_borrowed(false) {}

string Book::getTitle() const { return title; }
string Book::getAuthor() const { return author; }
string Book::getISBN() const { return isbn; }
bool Book::isBorrowed() const { return is_borrowed; }

void Book::borrow() {
    if (is_borrowed) throw LibraryException(" already borrowed.");
    is_borrowed = true;
}

void Book::returnBook() {
    if (!is_borrowed) throw LibraryException(" not borrowed.");
    is_borrowed = false;
}

string Book::toString() const {
    return title + " by " + author + " (ISBN: " + isbn + ") - " + (is_borrowed ? "Borrowed" : "Available");
}