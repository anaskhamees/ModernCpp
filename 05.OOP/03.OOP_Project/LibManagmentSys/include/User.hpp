#pragma once
#include <iostream>

class User {
protected:
    std::string userName;
    int userId;

public:
    User();
    User(std::string userName, int userId);
    
    virtual ~User();

    virtual void displayUserInfo() const;
};

