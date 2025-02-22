 #pragma once
#include "User.hpp"

class Teacher: public User
{
	public:
	Teacher(std::string teacherName, int teacherId);
 	
 	void displayUserInfo() const override;
};
