#include "User.hpp"

User::User() : userName(""), userId(0) {}

User::User(std::string userName, int userId) : userName(userName), userId(userId) {}

User::~User() {}

void User::displayUserInfo() const {  
    std::cout << "User: " << userName << ", ID: " << userId << std::endl;
}

