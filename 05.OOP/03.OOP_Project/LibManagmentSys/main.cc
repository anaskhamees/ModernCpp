#include "Library.hpp"
#include "Student.hpp"
#include "Teacher.hpp"

int main()
{
	Library lib;
	lib.addBook(Book("C++ Book",123,"Musa"));
	lib.addBook(Book("Linux Book",456,"Omar"));
	lib.addBook(Book("Android Book",789,"anas"));
	
	lib.addUser(new Student("ahmed",100));
	lib.addUser(new Teacher("ali",250));
	
	lib.displayBooks();
	
	return 0;
}
