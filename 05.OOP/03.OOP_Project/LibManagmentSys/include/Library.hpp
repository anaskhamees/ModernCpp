 #pragma once
#include"Book.hpp"
#include "User.hpp"
#include <vector>

class Library
{
	private :
	
		std::vector<Book> books; // Composition
		std::vector<User*> users; // Aggregation
	public:
		void addBook(const Book& book);
		void addUser(User* user);
		void displayBooks() const;
		void displayUsers() const;
	~Library();

};
