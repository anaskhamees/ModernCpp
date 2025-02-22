#include <iostream>
#include <vector>
#include <string>

// Borrowable Interface
class Borrowable {
public:
    virtual void borrowItem() = 0;
    virtual void returnItem() = 0;
    virtual ~Borrowable() {}
};

// Book Class
class Book : public Borrowable {
private:
    std::string title;
    std::string author;
    int bookID;
    bool isAvailable;
public:
    Book(std::string title, std::string author, int bookID)
        : title(title), author(author), bookID(bookID), isAvailable(true) {}
    void displayInfo() const {
        std::cout << "Book ID: " << bookID << ", Title: " << title << ", Author: " << author
                  << ", Available: " << (isAvailable ? "Yes" : "No") << std::endl;
    }
    bool checkAvailability() const { return isAvailable; }
    void borrowItem() override {
        if (isAvailable) {
            isAvailable = false;
            std::cout << "Book borrowed successfully!" << std::endl;
        } else {
            std::cout << "Book is not available!" << std::endl;
        }
    }
    void returnItem() override {
        isAvailable = true;
        std::cout << "Book returned successfully!" << std::endl;
    }
};

// User Class
class User {
protected:
    std::string name;
    int userID;
public:
    User(std::string name, int userID) : name(name), userID(userID) {}
    virtual void displayInfo() const {
        std::cout << "User ID: " << userID << ", Name: " << name << std::endl;
    }
    virtual ~User() {}
};

// Student Class
class Student : public User {
public:
    Student(std::string name, int userID) : User(name, userID) {}
    void displayInfo() const override {
        std::cout << "Student - ID: " << userID << ", Name: " << name << std::endl;
    }
};

// Teacher Class
class Teacher : public User {
public:
    Teacher(std::string name, int userID) : User(name, userID) {}
    void displayInfo() const override {
        std::cout << "Teacher - ID: " << userID << ", Name: " << name << std::endl;
    }
};

// Library Class
class Library {
private:
    std::vector<Book> books;
    std::vector<User*> users;
public:
    void addBook(const Book& book) {
        books.push_back(book);
    }
    void addUser(User* user) {
        users.push_back(user);
    }
    void displayBooks() const {
        std::cout << "Library Books: " << std::endl;
        for (const auto& book : books) {
            book.displayInfo();
        }
    }
    ~Library() {
        for (auto user : users) {
            delete user;
        }
    }
};

// Main Function
int main() {
    Library lib;
    lib.addBook(Book("C++ Primer", "Lippman", 101));
    lib.addBook(Book("Effective C++", "Scott Meyers", 102));
    lib.addUser(new Student("Alice", 1));
    lib.addUser(new Teacher("Dr. Smith", 2));
    
    lib.displayBooks();
    return 0;
}

