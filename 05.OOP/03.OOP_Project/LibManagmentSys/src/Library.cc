#include "Library.hpp"
#include <iostream>

void Library::addBook(const Book& book)
{
	books.push_back(book);
}

void Library::addUser(User* user)
{
	users.push_back(user);
}

void Library::displayBooks()const
{
	std::cout<<" Library Books: \n";
	
	for(const auto book : books)
	{
		book.displayBookInfo();
	}
}

Library::~Library()
{
	for(auto user: users)
	{
		delete user;
	}
}



