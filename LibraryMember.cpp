#include "LibraryMember.h"
#include <algorithm>

LibraryMember::LibraryMember(const string &id, const string &name) : member_id(id), name(name) {}

string LibraryMember::getName() const { return name; }
string LibraryMember::getId() const { return member_id; }

void LibraryMember::borrowBook(Book &book) {
    if (borrowed_books.size() >= 3) throw LibraryException("can't borrow more than 3 books.");
    book.borrow();
    borrowed_books.push_back(&book);
}

void LibraryMember::returnBook(Book &book) {
    auto it = find(borrowed_books.begin(), borrowed_books.end(), &book);
    if (it == borrowed_books.end()) throw LibraryException("Not borrowed by this member.");
    book.returnBook();
    borrowed_books.erase(it);
}

string LibraryMember::toString() const {
    string result = "MemberID " + member_id + ", Name " + name + ", Borrowed Books: ";
    for (const auto &book : borrowed_books) {
        result += book->getTitle() + ", ";
    }
    return borrowed_books.empty() ? result + "None" : result.substr(0, result.size() - 2);
}