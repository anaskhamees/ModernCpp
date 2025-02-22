 #pragma once
#include "User.hpp"

class Student: public User
{

	public:
	Student(std::string studentName, int studentId);
 	
 	void displayUserInfo() const override;
};
