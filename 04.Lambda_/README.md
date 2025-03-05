# ModernCpp

## Lambda Expression

### 1. **Lambda Expressions in C++**

A **lambda expression** in C++ is an **anonymous function** (a function without a name) that can be defined **inline**. Introduced in **C++11**, lambda expressions allow you to write short, function-like expressions in place without needing to declare a separate function.

A basic lambda expression syntax:

```c++
[ capture ] ( parameters ) -> return_type { body };
```

- **Capture**: Defines which variables from the surrounding scope are captured.
- **Parameters**: Function arguments (optional).
- **Return Type**: (Optional) Specifies the return type. If omitted, the return type is inferred.
- **Body**: The function logic.

------

### 2. **Drawbacks of Normal Functions & Advantages of Lambda Functions**

| **Normal Functions Drawbacks**                               | **Lambda Functions Advantages**                              |
| ------------------------------------------------------------ | ------------------------------------------------------------ |
| Need to define a separate function, leading to clutter.      | Can be defined **inline**, reducing unnecessary function declarations. |
| Cannot access variables from the enclosing scope without making them global or passing explicitly. | Can **capture** variables from their surrounding scope (closure). |
| Require explicit function declaration, making code lengthy for small operations. | More **concise** and **readable** for short, simple operations. |
| Function pointers lack type inference and flexibility.       | Can be stored in `std::function<>` and used as function objects. |

------

### 3. **Features of Lambda Functions**

- **Closures**: Can capture variables by value (`[=]`), by reference (`[&]`), or mix both.
- **Inline Definition**: No need for separate function declaration.
- **Type Inference**: No need to specify return type (`auto` inferred).
- **Immutability (by default)**: Captured variables are immutable unless explicitly marked as `mutable`.
- **Stateful**: Can store values from their environment.
- **Can be Assigned to Variables**: Acts as a function object (`std::function`).
- **Used in Standard Algorithms**: Works well with `std::for_each`, `std::sort`, etc.

------

### 4. **Use Cases & Examples**

#### **(A) Basic Syntax - No Parameters**

```c++
#include <iostream>
int main() {
    auto greet = []() { std::cout << "Hello, Lambda!\n"; };
    greet(); // Output: Hello, Lambda!
}
```

#### **(B) Lambda with Parameters**

```c++
#include <iostream>
int main() {
    auto add = [](int a, int b) { return a + b; };
    std::cout << add(5, 3) << "\n";  // Output: 8
}
```

#### **(C) Capturing Variables**

```c++
#include <iostream>
int main() {
    int x = 10, y = 20;

    auto capture_by_value = [x, y]() { return x + y; };
    auto capture_by_reference = [&x, &y]() { return ++x + ++y; };

    std::cout << capture_by_value() << "\n";   // Output: 30
    std::cout << capture_by_reference() << "\n"; // Output: 32 (modifies x and y)
}
```

#### **(D) Using `mutable` to Modify Captured Variables**

```c++
#include <iostream>
int main() {
    int x = 5;
    auto modify = [x]() mutable { x += 10; std::cout << x << "\n"; };
    
    modify(); // Output: 15
    std::cout << x << "\n"; // Output: 5 (original x is unchanged)
}
```

#### **(E) Specifying Return Type**

```c++
#include <iostream>
int main() {
    auto divide = [](double a, double b) -> double { return a / b; };
    std::cout << divide(10, 3) << "\n"; // Output: 3.33333
}
```

### Lambda Capture Modes:

1. `[ ] { }` → No captures.
2. `[=] { }` → Captures everything by **value**.
3. `[&] { }` → Captures everything by **reference**.
4. `[x] { }` → Captures `x` by **value**.
5. `[&x] { }` → Captures `x` by **reference**.
6. `[x, &] { }` → Captures `x` by **value**, everything else by **reference**.
7. `[&x, =] { }` → Captures `x` by **reference**, everything else by **value**.

These capture modes control how variables from the surrounding scope are accessed inside a lambda function. They are essential for managing variable lifetimes and avoiding unintended side effects in C++ programs.

### 1. **No Capture (`[]`)**

```c++
#include <iostream>

int main() {
    auto lambda = []() { std::cout << "Hello, Lambda!" << std::endl; };
    lambda(); // Output: Hello, Lambda!
    return 0;
}
```

### 2. **Capture Everything by Value (`[=]`)**

```c++
#include <iostream>

int main() {
    int x = 10, y = 20;
    auto lambda = [=]() { std::cout << x + y << std::endl; };
    lambda(); // Output: 30
    return 0;
}
```

> Variables `x` and `y` are copied into the lambda.

### 3. **Capture Everything by Reference (`[&]`)**

```c++
#include <iostream>

int main() {
    int x = 10, y = 20;
    auto lambda = [&]() { x += 5; y += 5; };
    lambda();
    std::cout << x << " " << y << std::endl; // Output: 15 25
    return 0;
}
```

> Modifications inside the lambda affect the original variables.

### 4. **Capture a Specific Variable by Value (`[x]`)**

```
cppCopyEdit#include <iostream>

int main() {
    int x = 10, y = 20;
    auto lambda = [x]() { std::cout << x << std::endl; };
    lambda(); // Output: 10
    return 0;
}
```

> `x` is copied; modifications inside the lambda won't affect the original `x`.

### 5. **Capture a Specific Variable by Reference (`[&x]`)**

```c++
#include <iostream>

int main() {
    int x = 10;
    auto lambda = [&x]() { x += 10; };
    lambda();
    std::cout << x << std::endl; // Output: 20
    return 0;
}
```

> `x` is captured by reference, so changes inside the lambda modify `x`.

### 6. **Capture `x` by Value and Everything Else by Reference (`[x, &]`)**

```c++
#include <iostream>

int main() {
    int x = 10, y = 20;
    auto lambda = [x, &]() { std::cout << x << " " << ++y << std::endl; };
    lambda();
    std::cout << y << std::endl; // Output: 21
    return 0;
}
```

> `x` is captured by value (unchanged in the outer scope), `y` is captured by reference (modified).

### 7. **Capture `x` by Reference and Everything Else by Value (`[&x, =]`)**

```c++
#include <iostream>

int main() {
    int x = 10, y = 20;
    auto lambda = [&x, =]() { x += 10; std::cout << y << std::endl; };
    lambda();
    std::cout << x << std::endl; // Output: 20
    return 0;
}
```

> `x` is modified as it's captured by reference, while `y` is captured by value and remains unchanged.

#### Function Wrapper

**What is `std::function`?**

`std::function` is a **general-purpose function wrapper** introduced in **C++11**. It allows you to store and use **callable objects** (such as lambdas, function pointers, or functors) with a **consistent function signature**.

------

### **Basic Syntax**

```c++
std::function<ReturnType(ParamType1, ParamType2, ...)> functionVariable;
```

- `ReturnType`: The type of value the function returns.
- `ParamType1, ParamType2, ...`: The parameter types of the function.
- `functionVariable`: The name of the function wrapper.

#### **(F) Using Lambdas with `std::function<>`**

```c++
#include <iostream>
#include <functional>

int main() {
    std::function<int(int, int)> multiply = [](int a, int b) { return a * b; };
    std::cout << multiply(4, 5) << "\n"; // Output: 20
}
```

>A function that **returns an `int`**
>
>Takes **two `int` parameters** as input
>
>Can store any callable object (like a lambda, function pointer, or functor) with the same signature.
>
>1. **Assigning a Lambda to `std::function`**
>
>   ```c++
>   multiply = [](int a, int b) { return a * b; };
>   ```
>
>   - This is an **anonymous function (lambda)** that takes two `int` arguments (`a` and `b`) and returns their product (`a * b`).
>   - `multiply` now holds this lambda, meaning you can use `multiply` as if it were a function.
>
>2. **Calling the Lambda through `std::function`**
>
>   ```c++
>   std::cout << multiply(4, 5) << "\n"; // Output: 20
>   ```
>
>   - This calls the lambda with arguments `4` and `5`, so it returns `4 * 5 = 20`, which gets printed.
>
>------
>
>### **Why Use `std::function`?**
>
>1. **Flexibility**: You can assign different callable objects (lambdas, function pointers, functors) to `std::function`.
>2. **Type Safety**: Ensures that the assigned callable matches the expected function signature.
>3. **Useful in Callbacks and Functional Programming**: Common in event handling, multi-threading, and high-order functions.
>
>------
>
>### **Example: Using `std::function` with Different Callables**
>
>```c++
>#include <iostream>
>#include <functional>
>
>int add(int x, int y) {
>    return x + y;
>}
>
>int main() {
>    std::function<int(int, int)> operation;  // Declare a function wrapper
>    
>    // Assign a normal function
>    operation = add;
>    std::cout << "Addition: " << operation(10, 5) << "\n"; // Output: 15
>
>    // Assign a lambda function
>    operation = [](int a, int b) { return a * b; };
>    std::cout << "Multiplication: " << operation(10, 5) << "\n"; // Output: 50
>
>    return 0;
>}
>```
>
>Here, `operation` is **reassigned** to different functions dynamically.

#### **(G) Lambda with `std::for_each` in Algorithms**

```c++
#include <iostream>
#include <vector>
#include <algorithm>

int main() {
    std::vector<int> nums = {1, 2, 3, 4, 5};

    std::for_each(nums.begin(), nums.end(), [](int n) {
        std::cout << n * n << " "; 
    });

    // Output: 1 4 9 16 25
}
```

#### **(H) Lambda as a Comparator in `std::sort`**

```c++
#include <iostream>
#include <vector>
#include <algorithm>

int main() {
    std::vector<int> nums = {5, 2, 8, 1, 3};

    std::sort(nums.begin(), nums.end(), [](int a, int b) { return a > b; });

    for (int n : nums)
        std::cout << n << " ";

    // Output: 8 5 3 2 1
}
```

#### **(I) Lambda in Threading**

```c++
#include <iostream>
#include <thread>

int main() {
    std::thread t([]() { std::cout << "Lambda in a thread\n"; });
    t.join();
}
```

### 

- **Lambda expressions** make C++ code **more expressive, concise, and efficient**.
- They are especially useful in **STL algorithms, functional programming, event handling, and multi-threading**.
- They provide **closures**, allowing access to variables in their surrounding scope.
- **Capture lists** provide flexibility in handling local variables.
- They can be used in **modern C++ paradigms**, improving performance and readability.

--------------

---------------

--------------------

### **`noexcept` in Function Declarations**

You can apply `noexcept` to:

1. **Normal Functions**

   ```c++
   void myFunction() noexcept;  // Guaranteed to not throw
   ```

2. **Lambda Expressions**

   ```c++
   auto lambda = []() noexcept { std::cout << "Noexcept Lambda\n"; };
   ```

3. **Destructors**

   ```c++
   class Example {
   public:
       ~Example() noexcept { std::cout << "Destructor\n"; }
   };
   ```

---------------------

---------------

### **L-Values and R-Values in Modern C++**

In **modern C++**, **L-values** and **R-values** are fundamental concepts that determine how objects are treated in memory and how they can be assigned, moved, or copied.

------

## **1. L-Value (Left Value)**

An **L-value** (locator value) refers to **an object that persists beyond a single expression** and has a **memory address**. It can appear on both the **left** and **right** sides of an assignment.

### **Examples of L-values**

```c++
int x = 10;  // 'x' is an L-value (it has a memory address)
x = 20;      // Allowed: L-value can be assigned a new value

std::string s = "Hello";  // 's' is an L-value
s = "World";              // L-value being reassigned
```

### **L-Values in Function Parameters**

```c++
void modify(int& a) { // L-value reference parameter
    a = 42;  // Allowed because 'a' is an L-value reference
}

int main() {
    int num = 10;
    modify(num); // ✅ Allowed (num is an L-value)
}
```

✅ **L-values are required for functions that take references (`int&`)**.

------

## **2. R-Value (Right Value)**

An **R-value** is a **temporary object** or **literal** that does not persist beyond a single expression.**
It **cannot** be assigned a new value directly because it **does not have a memory address**.

### **Examples of R-values**

```c++
int y = 5 + 3;  // '5 + 3' is an R-value
int z = 10;     
z = y + 2;      // 'y + 2' is an R-value

std::string greeting = "Hello" + std::string(" World"); // The result is an R-value
```

🔴 **You cannot assign to an R-value directly**:

```c++
(5 + 3) = 10;  // ❌ ERROR! R-value cannot be assigned
```

### **R-Values in Function Parameters**

```c++
void printValue(int&& a) {  // R-value reference parameter
    std::cout << a << std::endl;
}

int main() {
    printValue(42);   // ✅ Allowed: 42 is an R-value
    // int x = 10;
    // printValue(x); // ❌ ERROR: x is an L-value, not an R-value
}
```

✅ **R-value references (`int&&`) allow functions to accept and modify temporary values.**

------

## **3. R-Value References (`&&`) in Modern C++**

**Introduced in C++11**, `&&` allows us to bind to temporary objects, enabling **move semantics** and **perfect forwarding**.

### **Example: Move Semantics (Avoiding Unnecessary Copies)**

```c++
#include <iostream>
#include <string>

class MyClass {
public:
    std::string data;

    // Constructor
    MyClass(std::string d) : data(std::move(d)) { } // Moving instead of copying

    void show() { std::cout << data << std::endl; }
};

int main() {
    MyClass obj("Temporary String"); // Uses move constructor
    obj.show();  // Output: Temporary String
}
```

✅ **Using `std::move(d)`, we transfer ownership of the temporary string instead of copying it.**

------

## **4. L-Value vs R-Value Summary**

| Feature                       | L-Value                         | R-Value                     |
| ----------------------------- | ------------------------------- | --------------------------- |
| **Definition**                | Has a memory address (persists) | Temporary (no address)      |
| **Can be assigned?**          | ✅ Yes                           | ❌ No                        |
| **Can be passed to `int&`?**  | ✅ Yes                           | ❌ No                        |
| **Can be passed to `int&&`?** | ❌ No                            | ✅ Yes                       |
| **Use case**                  | Variables, persistent objects   | Temporary results, literals |

------

## **5. When to Use L-Values and R-Values?**

- **Use L-values (`T&`)** when modifying existing variables.
- **Use R-values (`T&&`)** when handling temporary values efficiently (e.g., move semantics).
- **Use `std::move`** to force an L-value into an R-value for optimization.

------

## **6. Practical Example: Move Constructor vs Copy Constructor**

```c++
#include <iostream>
#include <vector>

class Example {
public:
    std::vector<int> data;

    // Copy Constructor
    Example(const Example& other) {
        data = other.data;
        std::cout << "Copy Constructor\n";
    }

    // Move Constructor (R-value reference)
    Example(Example&& other) noexcept {
        data = std::move(other.data);
        std::cout << "Move Constructor\n";
    }
};

int main() {
    Example e1;
    Example e2 = e1;            // Calls Copy Constructor
    Example e3 = std::move(e1); // Calls Move Constructor
}
```

✅ **Using `std::move` prevents unnecessary copying and improves performance.**



### **Memory Layout of `e2 = e1`**

```c++
e1  --> [ data: {1,2,3} ]
e2  --> [ data: {1,2,3} ]  // Separate copy created
```



### **Memory Layout of `e3 = std::move(e1)`**

```c++
Before move:
e1  --> [ data: {1,2,3} ]
e3  --> [ uninitialized ]

After move:
e1  --> [ data: {} ]  // Now empty
e3  --> [ data: {1,2,3} ]  // Ownership transferred
```

✅ **No unnecessary copying, just moving pointers!**

✅ **Each object has its own copy of `data`**

| Feature                    | Copy Constructor (`Example(const Example&)`) | Move Constructor (`Example(Example&&)`) |
| -------------------------- | -------------------------------------------- | --------------------------------------- |
| **Takes**                  | `const Example&` (L-value reference)         | `Example&&` (R-value reference)         |
| **Creates a new copy?**    | ✅ Yes, deep copy of resources                | ❌ No, just moves resources              |
| **Performance**            | Slow (copies data)                           | Fast (moves data)                       |
| **Modifies the original?** | ❌ No, original stays the same                | ✅ Yes, original is left empt            |

------

### **Final Thoughts**

🚀 **L-values** are variables with **persistent storage**.
🔥 **R-values** are **temporary expressions** that **cannot be assigned**.
⚡ **R-value references (`&&`)** improve **performance** using **move semantics**.
