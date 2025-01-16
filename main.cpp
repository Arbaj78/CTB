#include "Library.h"
#include<iostream>

using namespace std;

int main()
{
   try {
        Library library;

        //ADD book
    
        library.addBook( Book("Book1","Author1","1234543434"));
        library.addBook(Book("Book2","Author2","3435143545"));

        //ADD MEMBERs
        LibraryMember member1("1", "Arbaj");
        LibraryMember member2("2", "Arya");
        library.addMember(member1);
        library.addMember(member2);

        vector<Book> searchResults = library.searchBooks("Book1");
        if (!searchResults.empty()) {
            member1.borrowBook(searchResults[0]);
        }

        cout << "After returning book:" << endl;
        library.displayBooks();

         } catch (const LibraryException &e) {
        cerr << "Error: " << e.what() << endl;
    }
        

   

    return 0;
}