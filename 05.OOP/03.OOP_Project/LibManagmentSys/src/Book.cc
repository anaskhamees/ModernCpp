#include "Book.hpp"
#include <iostream>

Book::Book(std::string bookName, int bookId, std::string bookAuthor)
{
	this->bookName=bookName;
	this->bookId=bookId;
	this->bookAuthor=bookAuthor;
	this->isAvaiable=true;
}

void Book::displayBookInfo() const{

	std::cout<<"Book ID: "<<bookId<<" , ";
	std::cout<<"BookName: "<<bookName<<" , ";
	std::cout<<"BookAuthor: "<<bookAuthor<<" , ";
	std::cout<<"Availability: "<<(isAvaiable ? "Yes":"No")<<std::endl;
}

bool Book::checkAvailability()const {return isAvaiable;}

void Book::borrowBook(){isAvaiable=false;}
void Book::returnBook(){isAvaiable=true;}

