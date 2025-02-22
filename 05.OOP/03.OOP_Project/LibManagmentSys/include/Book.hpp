/**
 * Book Class will inhernt from Borrowable class 
 */
  #pragma once
 #include "Borrowable.hpp"

 class Book:public Borrowable
 {
 	private:
	 	std::string bookName;
	 	int bookId;
	 	std::string bookAuthor;
	 	bool isAvaiable;
	public:
		Book(std::string bookName, int bookId, std::string bookAuthor);
		
		//getter
		void displayBookInfo() const;
		// check if book exist or Not in Lib
		bool checkAvailability() const;
		
		void borrowBook() ;
		void returnBook() ;
		
		~Book(){};
		
 	
 };
