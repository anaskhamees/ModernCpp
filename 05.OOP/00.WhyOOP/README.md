

### **1. Programming Paradigms**

A **programming paradigm** is a fundamental style or approach to writing and structuring code. It provides a way of thinking about how software is designed, written, and executed. The three most common paradigms are:

**1.1. Procedural Programming (Structured Programming)**
Procedural programming is a subset of imperative programming that **organizes code into reusable functions or procedures** to improve modularity.

**Characteristics:**

- Uses **functions** to structure the program.

- Promotes **code reusability** and **readability**.

- Examples: C, Pascal, Python, JavaScript.


**1.2. Object-Oriented Programming (OOP)**
OOP is centered around **objects** that encapsulate both **data (attributes)** and **behavior (methods)**.

**Characteristics:**

- Uses **classes** and **objects**.
- Supports **inheritance, polymorphism, encapsulation, and abstraction**.
- Examples: Java, C++, Python, JavaScript.

**1.3. Functional Programming**
Functional programming treats **functions as first-class citizens**, meaning functions can be assigned to variables, passed as arguments, and returned from other functions.

- **Pure functions** (no side effects).
- Avoids **mutating data** (immutability).
- Uses **higher-order functions** (functions that operate on other functions).
- Examples: Haskell, Lisp, Scala, JavaScript (ES6+), Python.

**1.4. Declarative Programming**
Declarative programming focuses on **what should be done** rather than **how it should be done**.

**Characteristics:**

- Avoids explicit control flow (loops, conditionals).
- Uses **expressions** instead of statements.
- Examples: QML, SQL, HTML, CSS, React (JSX).

**Comparison of Paradigms**

| Paradigm              | Focuses On                      | Examples                   |
| --------------------- | ------------------------------- | -------------------------- |
| Imperative            | Step-by-step execution          | C, Python, JavaScript      |
| Procedural            | Code organization via functions | C, Pascal, Python          |
| Object-Oriented (OOP) | Objects & data encapsulation    | Java, C++, Python          |
| Functional            | Functions & immutability        | Haskell, JavaScript, Scala |
| Declarative           | Describing *what* to do         | SQL, HTML, React           |
| Logic                 | Rules & facts                   | Prolog, Datalog            |

------

------

### **2. Procedural Programming**

**Procedural Programming** is the most traditional programming paradigm, based on the concept of **procedures (or functions)** that operate on data. It follows a **top-down approach** where a program is broken into smaller procedures (functions) to handle different tasks.

#### **Characteristics of Procedural Programming:**

- Code is written as a sequence of instructions (step-by-step).
- Functions are used to structure the program.
- Data is stored in variables, and functions operate on that data.
- Uses control structures like loops (`for`, `while`) and conditionals (`if`, `switch`).
- Example languages: **C, Pascal, FORTRAN, BASIC**

**Example of Procedural Programming in C:**

```c
#include <stdio.h>

// Function to calculate the square of a number
int square(int x) {
    return x * x;
}

int main() {
    int num = 5;
    printf("Square of %d is %d\n", num, square(num));
    return 0;
}
```

In this example:

- The `square()` function takes an integer and returns its square.
- The `main()` function calls `square()` and prints the result.

#### **2.1. Limitations of Procedural Programming**

While procedural programming is simple and efficient for small programs, it has several drawbacks when used in complex applications:

1. **Difficult to manage large programs** – As programs grow, managing functions and variables becomes challenging.
2. **No Data Encapsulation** – Data is freely accessible throughout the program, making it prone to accidental modifications.
3. **Code Reusability is Limited** – Reusing code requires copying and modifying functions, leading to redundancy.
4. **High Complexity** – Debugging and modifying large procedural programs is difficult because functions depend on global data.
5. **Lack of Security** – There is no concept of **access control**; any function can modify any variable.

------

### **3. Why Should We Use OOP?**

To overcome the limitations of procedural programming, **Object-Oriented Programming (OOP)** was introduced. OOP helps in structuring software as a collection of objects that **interact** with each other. It models real-world problems more effectively and enhances **code reusability, maintainability, and security**.

------

### 4. Object-Oriented Programming (OOP)

OOP is a paradigm that organizes software design around **objects**, which are instances of **classes**. Objects combine both **data (attributes)** and **behavior (methods)** into a single unit.

#### Features of OOP:

1. **Encapsulation** – Wrapping data and methods together inside a class.
2. **Abstraction** – Hiding implementation details and exposing only essential features.
3. **Inheritance** – Enabling a new class to acquire properties and methods from an existing class.
4. **Polymorphism** – Allowing different classes to be treated as instances of the same class through method overriding and overloading.

**Example of OOP in C++:**

```c++
#include <iostream>
using namespace std;

// Class definition
class Car {
private:
    string brand;
    int speed;

public:
    // Constructor
    Car(string b, int s) {
        brand = b;
        speed = s;
    }

    // Method to display car details
    void showDetails() {
        cout << "Brand: " << brand << ", Speed: " << speed << " km/h" << endl;
    }
};

int main() {
    Car car1("Toyota", 180);
    car1.showDetails();  // Output: Brand: Toyota, Speed: 180 km/h
    return 0;
}
```

In this example:

- A `Car` class encapsulates `brand` and `speed` attributes.
- The constructor initializes values.
- The `showDetails()` method prints the details.

--------------------------------------------------------------

**4.1. Advantages of OOP**

1. **Code Reusability** – Inheritance allows code reuse, reducing duplication.
2. **Encapsulation Improves Security** – Data hiding ensures controlled access to attributes.
3. **Scalability** – OOP simplifies adding new features to large programs.
4. **Better Maintainability** – Modular code structure makes debugging and updates easier.
5. **Flexibility through Polymorphism** – The same function name can perform different tasks.
6. **Real-World Modeling** – Objects represent real-world entities, making software design intuitive.

----------------------------------------------------------------------

**4.2. Limitations of OOP**

1. **Increased Complexity** – OOP introduces additional concepts like classes, objects, inheritance, and polymorphism, making it harder for beginners.
2. **Higher Memory Usage** – Objects and classes consume more memory compared to procedural programming.
3. **Slower Execution Speed** – Due to abstraction and additional layers, OOP can be slower than procedural programming in some cases.
4. **Not Always Necessary** – For small scripts and simple programs, procedural programming might be more efficient.
5. **Tight Coupling Risk** – Improper OOP design may lead to dependencies between classes, making changes difficult.
