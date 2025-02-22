/**
 * File : Library Items which can be borrowed like Books
 */
  #include <iostream>
 class Borrowable
 {
 	private:
 		std::string itemName; 
 		std::string borrowDate;
 	public :
 		//virtual void borrowItem()=0;
 		//virtual void returnItem()=0;
 		virtual ~Borrowable() {};
 }; 
 
