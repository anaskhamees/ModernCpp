#include "Student.hpp"
#include <iostream>	


Student::Student(std::string studentName, int studentId):User(studentName,studentId)
{
}

 	void Student::displayUserInfo() const
 	{
 		std::cout<<"Student ID: "<<userId<<" , ";
 		std::cout<<" Student Name : "<<userName<<std::endl;
 	}
