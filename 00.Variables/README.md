# ModernCpp
### 1. C++ Variables 

#### 1.1. Variables Initialization

--------------------------------------------------------------------------------------

- **Default Initialization**

  - Occurs when a variable is declared but not explicitly initialized.

  - Behavior:
    - **Fundamental types** (int, float, etc.) inside functions contain **garbage values**.
    - **Global/static variables** are **zero-initialized**.

```c++
int x;  // Uninitialized (contains garbage value)
static int y; // Zero-initialized
```

-  **Value Initialization (`Type var = Type();`)**
  - Ensures zero-initialization for fundamental types.

```c++
int x = int();  // x is initialized to 0
```

-  **Zero Initialization**
  - Used for global/static variables and `= {}` syntax.

```c++
int x{};  // x is initialized to 0
double d{}; // d is initialized to 0.0
```

-  **Direct Initialization (`Type var(value)`)**
  - Calls the constructor directly (for classes) or initializes primitive types.

```c++
int x(10);  // Direct initialization
std::string s("Hello");  // Calls std::string constructor
```

-  **Copy Initialization (`Type var = value;`)**

  - Uses the `=` operator.

  - May invoke implicit conversions.

```c++
int x = 10;  // Copy initialization
std::string s = "Hello";  // Copy initialization
```

-------------------------

- **List Initialization (`{}`) – Modern C++ (C++11+)**

  - **Prevents narrowing conversions**.

    >A **narrowing conversion** is a type of implicit conversion where a **larger** or **more precise** data type is converted into a **smaller** or **less precise** type, potentially causing **loss of data or precision**.

  - Works for fundamental types, structs, and STL containers.

```c++
int x{10};  // Direct list initialization
double d{3.14};  // OK
// int y{3.14};  // ERROR! Narrowing conversion

std::vector<int> v{1, 2, 3};  // Works for containers
```

C++11 **prevents** narrowing conversions when using **brace `{}` initialization**, making your code safer.

✅ **Allowed (No Narrowing)**

```c++
int a = 3.14;  // Allowed (C++03 and earlier)
int b{3};      // Allowed (C++11 and later)
```

❌ **Error (Prevents Narrowing)**

```
int x{3.14};  // ❌ Compilation error! Prevents data loss
char c{300};  // ❌ Error! Prevents out-of-range values
```

----------

**Why Does C++11 Prevent Narrowing in `{}` Initialization?**

- Prevents accidental loss of data.
- Avoids undefined behavior due to **overflow**.
- Helps catch **bugs at compile-time** instead of runtime.

----------------------

- **Braced Initialization (`={}`)**
  - Used in aggregate initialization and for explicit initialization.

```c++
struct Point {
    int x, y;
};
Point p = {1, 2};  // Aggregate initialization
```

- **Dynamic Initialization (Heap Allocation)**
  - Allocates memory dynamically.

```c++
int* p = new int(10);  // Allocates int on heap
delete p;
```

-  **Move Initialization (C++11+)**
  - Uses `std::move()` to transfer ownership of resources.

```c++
std::string s1 = "Hello";
std::string s2 = std::move(s1);  // s1 is now empty
```

| Initialization Type    | Syntax                            | Notes                       |
| ---------------------- | --------------------------------- | --------------------------- |
| **Default**            | `int x;`                          | May have garbage value      |
| **Value**              | `int x = int();`                  | Zero-initialization         |
| **Zero**               | `int x{};`                        | Zero-initialized            |
| **Direct**             | `int x(10);`                      | Constructor/direct call     |
| **Copy**               | `int x = 10;`                     | May involve conversions     |
| **List**               | `int x{10};`                      | Safer, prevents narrowing   |
| **Braced (`={}`)**     | `int x = {};`                     | Ensures zero-initialization |
| **Dynamic (`new`)**    | `int* p = new int(10);`           | Allocated on heap           |
| **Move (`std::move`)** | `std::string s2 = std::move(s1);` | Transfers ownership         |

------------------------------------------------------------------

#### 1.2. Casting in Cpp

| Feature                | C-Style Cast (`(type)expr`)          | `static_cast<Type>(expr)`             |
| ---------------------- | ------------------------------------ | ------------------------------------- |
| **Type Safety**        | Unsafe (can do multiple conversions) | Safer (only allows valid conversions) |
| **Readability**        | Hard to understand intent            | Clearly shows intent                  |
| **Error Checking**     | No compile-time checks               | Catches invalid conversions           |
| **Undefined Behavior** | Possible if misused                  | Avoids undefined behavior             |

#### 1.2.1. Examples

- **Normal Case**

```c++
#include <iostream>
using namespace std;

int main()
{
    float f = 3.5;

    // Implicit type case
    // float to int
    int a = f;
    cout << "The Value of a: " << a;

    // using static_cast for float to int
    int b = static_cast<int>(f);
    cout << "\nThe Value of b: " << b;
}

```

- **Pointer to primitive data types**

  ```c++
  #include <iostream>
  using namespace std;
  
  int main()
  {
    int a = 10;
    char c = 'a';
    
    // Pass at compile time, 
    // may fail at run time
    int* q = (int*)&c;
    int* p = static_cast<int*>(&c);
    return 0;
  }
  
  ```

  ```c++
  #include <iostream>
  
  int main() {
      int x = 10;
      
      // Invalid conversion: C-Style Cast allows it, but static_cast does not
      double* ptr1 = (double*)&x;               // ❌ Dangerous! Allowed by C-Style Cast
      double* ptr2 = static_cast<double*>(&x);  // ❌ Compile-time error! Prevents mistake
  
      return 0;
  }
  
  ```

  

  ```c++
  #include <iostream>
  
  int main() {
      const int num = 100;
  
      // C-Style Cast (Removes const, unsafe)
      int* ptr1 = (int*)&num;  
  
      // static_cast (Does NOT allow removing const)
      // int* ptr2 = static_cast<int*>(&num);  // ❌ ERROR: static_cast prevents this
  
      *ptr1 = 50;  // Undefined behavior!
      std::cout << "Modified num: " << *ptr1 << "\n";
      
      return 0;
  }
  ```

  -----------------------------------------



#### 1.3. Constants in C++

In C++, constants are **fixed values** that do not change during program execution. They can be classified into different types:

**1.3.1. Literal Constants**

These are hard coded values directly used in the program. Examples:

```c++
int a = 10;     // Integer literal
double pi = 3.14; // Floating-point literal
char ch = 'A';  // Character literal
std::string str = "Hello"; // String literal
```

💡 **Types of Literal Constants:**

- **Integer literals**: `10`, `255`, `0xFF` (hex), `077` (octal), `0b1010` (binary)
- **Floating-point literals**: `3.14`, `2.5e3` (scientific notation)
- **Character literals**: `'A'`, `'\n'`, `'\t'`
- **String literals**: `"Hello"`, `"C++"`

-----------------------

**1.3.2. `const` Constants**

- `const` keyword makes a variable **read-only** (cannot be modified after initialization).
- It **must be initialized** at the time of declaration.

```c++
const int maxUsers = 100;  // ✅ Correct (constant integer)
maxUsers = 200;  // ❌ Error! Cannot modify a const variable
```

- Used for defining **constant values** to prevent accidental modifications.

----------------------------

**1.3.3. `constexpr` (Compile-time Constants)**

- `constexpr` ensures the constant is evaluated **at compile-time**, making it more efficient.
- Used in **constant expressions** (e.g., array sizes, template parameters).

```c++
constexpr int size = 10;   // ✅ Compile-time constant
int arr[size];  // ✅ Allowed because 'size' is known at compile-time
```

🚀 **`constexpr` is preferred** over `const` when the value is known **at compile time**.

-----------------

**1.3.4. `#define` Preprocessor Constants (Old Style)**

- `#define` defines a **macro** before compilation.
- It is **not type-safe** (no data type checking).

```c++
#define PI 3.14159
#define MAX 1000
int area = PI * r * r;
```

⚠️ **Avoid using `#define` for constants in modern C++**; use `constexpr` or `const` instead.

----------------

**1.3.5. Enumerations (`enum` & `enum class`)**

**`enum` (Old-style)**

Defines named integer constants:

```c++
enum Colors { RED = 1, GREEN = 2, BLUE = 3 };
Colors c = RED;  // ✅ Uses predefined constant
```

💡 `enum` values are implicitly convertible to `int`.



**`enum class` (Scoped Enum, Safer)**

Prevents implicit conversions and name conflicts:

```c++
enum class Colors { RED = 1, GREEN = 2, BLUE = 3 };
Colors c = Colors::RED;  // ✅ Safer, requires scope resolution
```

🚀 **Prefer `enum class`** in modern C++.

----------------

**1.3.6.`constexpr` Functions (Constant Expressions)**

- Functions that return a **constant value at compile time**.

```c++
constexpr int square(int x) { return x * x; }
constexpr int size = square(5);  // ✅ Computed at compile-time
```

## 

| Type                      | Description                       | Example                                   |
| ------------------------- | --------------------------------- | ----------------------------------------- |
| **Literal Constants**     | Hardcoded values                  | `10, 3.14, 'A', "Hello"`                  |
| **`const` Constants**     | Read-only variables               | `const int max = 100;`                    |
| **`constexpr` Constants** | Compile-time constants            | `constexpr int size = 10;`                |
| **`#define` Macros**      | Preprocessor constant (old style) | `#define PI 3.14159`                      |
| **`enum` & `enum class`** | Named integer constants           | `enum class Colors { RED, GREEN, BLUE };` |

👉 **Best Practice**: Use **`constexpr` or `const`** for modern C++ instead of `#define`.

---------

##### 1.3.7. Constexpr



```c++
constexpr int square(int x) {     
  return x * x; 
}  

constexpr int result = square(5);  // Computed at compile-time.
```



```c++
const int x = rand();  // Valid, initialized at run-time.
```



- **`const` vs `constexpr` with Variables**
  - **Example 1: `const` Can Be Initialized at Runtime**

```c++
#include <iostream>

int main() {
    int n;
    std::cin >> n;  // User input at runtime

    const int c = n;   // ✅ OK: Can be assigned a runtime value
    constexpr int e = n; // ❌ ERROR: 'n' is not a constant expression

    return 0;
}
```

✅ `const` allows runtime values.
❌ `constexpr` **must be known at compile time**.

---------------------------

- **`constexpr` vs `const` with Functions**
  - **Example 2: Function Call at Compile-time vs Runtime**

```c++
#include <iostream>

constexpr int add(int a, int b) { return a + b; }

int main() {
    int x = 4, y = 3;
    int runtimeResult = add(x, y);    // ✅ Computed at runtime (parameters are not constexpr)
    constexpr int compileTimeResult = add(4, 3);  // ✅ Computed at compile-time

    std::cout << "Runtime: " << runtimeResult << std::endl;
    std::cout << "Compile-time: " << compileTimeResult << std::endl;

    return 0;
}
```

✅ `add(4,3)` is computed at compile-time because it has **constant values**.
✅ `add(x, y)` is computed at runtime because `x` and `y` are **not compile-time constants**.

-----------------

- **Using `constexpr` to Optimize Runtime Performance**
  - **Example 3: Factorial Calculation at Compile-time**

```c++
#include <iostream>

// Compile-time factorial
constexpr int factorial(int n) {
    return (n <= 1) ? 1 : (n * factorial(n - 1));
}

int main() {
    constexpr int fact5 = factorial(5);  // ✅ Computed at compile-time

    int n;
    std::cin >> n;
    int factN = factorial(n);  // ✅ Computed at runtime (n is unknown at compile-time)

    std::cout << "Factorial of 5: " << fact5 << std::endl;
    std::cout << "Factorial of " << n << ": " << factN << std::endl;

    return 0;
}
```

✅ `factorial(5)` is computed **at compile-time**, reducing runtime overhead.
✅ `factorial(n)` is computed **at runtime** when `n` is user input.

--------------------

- **`const` vs `constexpr` with Arrays**
  - **Example 4: `constexpr` in Array Size**

```c++
#include <iostream>

int main() {
    const int size1 = 5;     // ✅ Can be initialized at runtime
    constexpr int size2 = 10; // ✅ Must be compile-time known

    int arr1[size1];  // ❌ Error in some compilers (size1 is not always constexpr)
    int arr2[size2];  // ✅ Allowed (size2 is constexpr)

    return 0;
}
```

✅ `constexpr` ensures **compile-time evaluation**, making it suitable for array sizes.
❌ `const` may not always be **evaluated at compile-time**, causing issues.

## 

| Feature              | `const`                   | `constexpr`                             |
| -------------------- | ------------------------- | --------------------------------------- |
| **Evaluated**        | Runtime or Compile-time   | Always Compile-time                     |
| **Function Support** | ❌ No                      | ✅ Yes                                   |
| **Class Members**    | ✅ Yes                     | ✅ Yes                                   |
| **Performance**      | No compile-time guarantee | Can optimize runtime by computing early |

------------------------

- **Examples**

  ```c++
  #include <iostream>
  
  constexpr int getSize() {
      return 10;  // ✅ Evaluated at compile-time
  }
  
  int main() {
      int arr[getSize()];  // ✅ Valid, size is a compile-time constant
  
      // Fill the array with values
      for (int i = 0; i < getSize(); ++i) {
          arr[i] = i * 2;
      }
  
      // Print the array values
      std::cout << "Array contents: ";
      for (int i = 0; i < getSize(); ++i) {
          std::cout << arr[i] << " ";
      }
  
      return 0;
  }
  
  ```

  ```c++
  int getSizeRuntime() {
      return 10;  // ❌ Not a compile-time constant
  }
  
  int main() {
      int arr[getSizeRuntime()];  // ❌ ERROR: Size must be a compile-time constant
  }
  
  ```

  ```c++
  #include <iostream>
  
  constexpr int defaultSize() { return 5; }
  
  int main() {
      int arr1[defaultSize()];  // ✅ Compile-time constant
  
      int n;
      std::cout << "Enter array size: ";
      std::cin >> n;
  
      int arr2[n];  // ❌ ERROR: Variable length array (VLA) is not standard in C++
  
      // Use the arrays to avoid "unused variable" warnings
      arr1[0] = 1;
      std::cout << "arr1[0]: " << arr1[0] << std::endl;
  
      arr2[0] = 2;
      std::cout << "arr2[0]: " << arr2[0] << std::endl;
  
      return 0;
  }
  
  ```

  But Compile with :

  ```c++
  g++ -Wall -Werror -pedantic examples.cc -o app
  ```

  
