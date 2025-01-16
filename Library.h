#ifndef LIBRARY_H
#define LIBRARY_H
#include <vector>
#include "Book.h"
#include "LibraryMember.h"
using namespace std;


class Library {
private:
    vector<Book> books;
    vector<LibraryMember> members;

public:
    void addBook(const Book &book);
    void removeBook(const string &isbn);
    vector<Book> searchBooks(const string &title = "", const string &author = "") const;
    void addMember(const LibraryMember &member);
    void removeMember(const string &member_id);
    void displayBooks() const;
    void displayMembers() const;
};

#endif