#include "Teacher.hpp"
#include <iostream>	

Teacher::Teacher(std::string teacherName, int teacherId):User(teacherName,teacherId)
{
}

 	void Teacher::displayUserInfo() const
 	{
 		std::cout<<"Teacher ID: "<<userId<<" , ";
 		std::cout<<" Teacher Name : "<<userName<<std::endl;
 	}
