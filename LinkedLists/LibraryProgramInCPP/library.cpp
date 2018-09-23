// library.cpp

#include <iostream>
#include <string.h>
#include <ctype.h>
#include "genSLLst.h"
using namespace std;
struct PersonNode;				// forward declarations;
struct AuthorNode;
struct BookNode;

struct CheckedOutBookNode {
	AuthorNode *author;
	BookNode *book;
};

class CheckedOutBook : public SinglyLinkedList<CheckedOutBookNode> {
public:
	~CheckedOutBook() { SetToNull(); }
};

struct BookNode {
	char *title;
	PersonNode *person;
	BookNode() { person = 0; }
	int operator== (const BookNode& bk)
		{return strcmp(title,bk.title) == 0; }
};
class Book : public SinglyLinkedList<BookNode> {
public:
	~Book() { SetToNull(); }
};

struct AuthorNode {
	char *name;
	Book books;
	int operator== (const AuthorNode& ar)
		{ return strcmp(name,ar.name) == 0; }
};

class Author : public SinglyLinkedList<AuthorNode> { } catalog['Z' +1];

struct PersonNode {
	char *name;
	CheckedOutBook books;
	int operator== (const PersonNode& pn)
		{ return strcmp(name,pn.name) == 0; }
};

class Person : public SinglyLinkedList<PersonNode> {
public:
	friend void CheckOutBook();
} people;

ostream&
operator<< (ostream& out, const BookNode& bk)
{
	out << "     * " << bk.title;
	if (bk.person)
		out << " - checked out to " << bk.person->name;
	out << endl;
	return out;
}
ostream&
operator<< (ostream& out, const AuthorNode& ar)
{
	out << ar.name << endl << ' ';
	ar.books.PrintAll(out);
	return out;
}

int
operator== (CheckedOutBookNode& bk1, const CheckedOutBookNode& bk2)
{
	return strcmp(bk1.book->title, bk2.book->title) == 0 &&
		   strcmp(bk1.author->name,bk2.author->name) == 0;
}

ostream&
operator<< (ostream& out, const CheckedOutBookNode& bk)
{
	out << "    * " << bk.author->name << ", "
	                << bk.book->title << endl;
	return out;
}

ostream&
operator<< (ostream& out, const PersonNode& pr)
{
	out << pr.name;
	if (!(pr.books.IsEmpty())) {
		out << " has the following books: \n ";
		pr.books.PrintAll(out);
	}
	else out << " has no books\n";
	return out;
}

char*
GetString(char *msg)
{	char s[82], i, *destin;
	cout << msg;
	cin.get(s,80);
	while (cin.get(s[81]) && s[81] != '\n');   // discard overflowing characters;
	destin = new char[strlen(s) +1];
	for (i = 0; destin[i] = toupper(s[i]); i++);
	return destin;
}

void
Status()
{	register int i;

	cout << "Library has the following books: \n\n ";
	for (i = 'A'; i <='Z'; i++)
		if (!catalog[i].IsEmpty())
			catalog[i].PrintAll(cout);
	cout << "\nThe following people are using the library:\n\n ";
	people.PrintAll(cout);
}

void
IncludeBook()
{	AuthorNode newAuthor, *oldAuthor;
	BookNode newBook;

	newAuthor.name = GetString("Enter author's name: ");
	newBook.title = GetString("Enter the title of the book: ");
	oldAuthor = catalog[newAuthor.name[0]].Find(newAuthor);
	if (oldAuthor == 0) {
		newAuthor.books.Add(newBook);
		catalog[newAuthor.name[0]].Add(newAuthor);
	}
	else oldAuthor->books.Add(newBook);
}

void
CheckOutBook()
{	PersonNode person, *personRef;
	AuthorNode author, *authorRef = 0;
	BookNode book, *bookRef = 0;
	CheckedOutBookNode bookToCheckOut;

	person.name = GetString("Enter person's name: ");
	while (!authorRef) {
		author.name = GetString("Enter author's name: ");
		if (!(authorRef = catalog[author.name[0]].Find(author)))
			cout << "Misspelled author's name\n";
	}
	while (!bookRef) {
		book.title = GetString("Enter the title of the book: ");
		if (!(bookRef = authorRef->books.Find(book)))
			cout << "Misspelled title\n";
	}
	bookToCheckOut.author = authorRef;
	bookToCheckOut.book = bookRef;
	personRef = people.Find(person);
	if (!personRef) {	// a new person in the library;
		person.books.Add(bookToCheckOut);
		people.Add(person);
		bookRef->person = &people.head->info;
	}
	else {
		personRef->books.Add(bookToCheckOut);
		bookRef->person = personRef;
	}
}

void
ReturnBook()
{	PersonNode person, *personRef = 0;
	CheckedOutBookNode checkedOutBook;
	BookNode book, *bookRef = 0;
	AuthorNode author, *authorRef = 0;

	while (!personRef) {
		person.name = GetString("Enter a person's name: ");
		if (!(personRef = people.Find(person)))
			cout << "Person's name misspelled\n";
	}
	while (!authorRef) {
		author.name = GetString("Enter author's name: ");
		if (!(authorRef = catalog[author.name[0]].Find(author)))
			cout << "Misspelled author's name\n";
	}
	while (!bookRef) {
		book.title = GetString("Enter the title of the book: ");
		if (!(bookRef = authorRef->books.Find(book)))
			cout << "Misspelled title\n";
	}
	checkedOutBook.author = authorRef;
	checkedOutBook.book      = bookRef;
	bookRef->person = 0;
	personRef->books.Remove(checkedOutBook);
}

int Menu()
{	int option;

	cout << "\nEnter one of the following options:\n"
		 << "1. Include a book in the catalog\n2. Check out a book\n"
		 << "3. Return a book\n4. Status\n5. Exit\n"
		 << "Your Option? ";
	cin >> option;
	cin.get();  // discard eoln;
	return option;
}

main ()
{
	while (1)
		switch (Menu()) {
			case 1: IncludeBook(); break;
			case 2: CheckOutBook(); break;
			case 3: ReturnBook(); break;
			case 4: Status(); break;
			case 5: return 0;
			otherwise: cout << "Wrong option, try again:";
		}
}




























































































































