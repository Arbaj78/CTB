#include "Library.h"
#include <iostream>

void Library::addBook(const Book &book) {
    books.push_back(book);
}

void Library::removeBook(const string &isbn) {
    for (auto it = books.begin(); it != books.end(); ++it) {
        if (it->getISBN() == isbn) {
            if (it->isBorrowed()) throw LibraryException("Cannot remove");
            books.erase(it);
            return;
        }
    }
    throw LibraryException("Not found.");
}

vector<Book> Library::searchBooks(const string &title, const string &author) const {
    vector<Book> results;
    for (const auto &book : books) {
        if ((!title.empty() && book.getTitle().find(title) != string::npos) ||
            (!author.empty() && book.getAuthor().find(author) != string::npos)) {
            results.push_back(book);
        }
    }
    return results;
}

    void Library::addMember(const LibraryMember &member) {
    members.push_back(member);
}

void Library::removeMember(const string &member_id) {
    for (auto it = members.begin(); it != members.end(); ++it) {
        if (it->getId() == member_id) {
            if (!it->toString().empty()) throw LibraryException("Member has borrowed books and cannot be removed.");
            members.erase(it);
            return;
        }
    }
    throw LibraryException("Member not found.");
}

void Library::displayBooks() const {
    for (const auto &book : books) {
        cout << book.toString() << endl;
    }
}

void Library::displayMembers() const {
    for (const auto &member : members) {
        cout << member.toString() << endl;
    }
}

