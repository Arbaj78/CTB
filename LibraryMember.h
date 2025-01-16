#ifndef LIBRARY_MEMBER_H
#define LIBRARY_MEMBER_H

#include <string>
#include <vector>
#include "Book.h"
using namespace std;

class LibraryMember {
private:
    string member_id;
    string name;
    vector<Book *> borrowed_books;

public:
    LibraryMember(const string &id, const string &name);
    string getName() const;
    string getId() const;
    void borrowBook(Book &book);
    void returnBook(Book &book);
    string toString() const;
};

#endif