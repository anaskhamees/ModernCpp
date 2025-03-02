# ModernCpp


### String

`std::string` and `std::string_view` are two important classes in **C++ for handling text**.

✅ **`std::string`**: A dynamically allocated, mutable string.
✅ **`std::string_view`** (C++17): A lightweight, non-owning reference to a string.

**🔹 1. `std::string` (C++98 and later)**

### **✔ Key Features:**

- Owns and manages its memory.
- Supports dynamic resizing.
- Mutable (modifiable).
- Has **many utility functions**.

### **📌 Declaration and Initialization**

```c++
#include <iostream>
#include <string>

int main() {
    std::string str1 = "Hello";
    std::string str2("World");
    std::string str3 = str1 + " " + str2; // Concatenation
    std::cout << str3 << std::endl; // Output: Hello World
}
```



**🔹 2. `std::string` Member Functions**

## **🛠️ Capacity Functions**

| Function              | Description                                     |
| --------------------- | ----------------------------------------------- |
| `size()` / `length()` | Returns the number of characters in the string. |
| `capacity()`          | Returns the allocated storage capacity.         |
| `resize(n)`           | Resizes the string to `n` characters.           |
| `reserve(n)`          | Requests memory for at least `n` characters.    |
| `empty()`             | Returns `true` if the string is empty.          |
| `clear()`             | Erases all characters.                          |
| `shrink_to_fit()`     | Reduces memory usage.                           |

### **📌 Example:**

```c++
std::string str = "Hello";
std::cout << "Size: " << str.size() << ", Capacity: " << str.capacity() << std::endl;
str.reserve(50);
std::cout << "New Capacity: " << str.capacity() << std::endl;
```

------

## **🛠️ Modifiers**

| Function                 | Description                           |
| ------------------------ | ------------------------------------- |
| `operator+=`             | Appends characters or another string. |
| `append()`               | Adds content at the end.              |
| `insert(pos, str)`       | Inserts `str` at position `pos`.      |
| `replace(pos, len, str)` | Replaces part of the string.          |
| `erase(pos, len)`        | Removes characters.                   |
| `push_back(ch)`          | Adds a character at the end.          |
| `pop_back()`             | Removes the last character.           |

### **📌 Example**

```c++
std::string s = "Hello";
s.append(" World");
s.insert(6, "Beautiful ");
std::cout << s << std::endl;  // Output: Hello Beautiful World
```

------

## **🛠️ String Search Functions**

| Function           | Description                                   |
| ------------------ | --------------------------------------------- |
| `find(substring)`  | Returns the first occurrence index or `npos`. |
| `rfind(substring)` | Finds the last occurrence.                    |
| `substr(pos, len)` | Returns a substring.                          |
| `compare(str)`     | Lexicographically compares strings.           |
| `starts_with(str)` | Checks if string starts with `str`. (C++20)   |
| `ends_with(str)`   | Checks if string ends with `str`. (C++20)     |

### **📌 Example**

```
cppCopyEditstd::string s = "Hello World";
if (s.find("World") != std::string::npos) {
    std::cout << "Found!" << std::endl;
}
```

------

## **🛠️ Conversion Functions**

| Function         | Description                    |
| ---------------- | ------------------------------ |
| `stoi(str)`      | Converts string to `int`.      |
| `stof(str)`      | Converts string to `float`.    |
| `to_string(num)` | Converts a number to a string. |

```c++
std::string s = "123";
int num = std::stoi(s);
std::string newStr = std::to_string(num + 10);
std::cout << newStr << std::endl; // Output: 133
```

----------------------

--------------------

### 3. **`std::string_view` (C++17)**

A **lightweight alternative** to `std::string`.
✅ **Non-owning reference** to an existing string.
✅ Avoids unnecessary copies.
❌ Cannot be modified.

### **📌 Example**

```c++
#include <iostream>
#include <string_view>

void print(std::string_view sv) {
    std::cout << sv << std::endl;
}

int main() {
    std::string str = "Hello, world!";
    print(str); // No copy!
    print("Temporary string"); // Also works!
}
```

### **✔ Benefits of `std::string_view`**

- Avoids copying large strings.
- Works with **string literals**, `std::string`, and `char*`.
- Efficient for **function parameters**.

**🔹 4. `std::string_view` Member Functions**

| Function              | Description                               |
| --------------------- | ----------------------------------------- |
| `size()` / `length()` | Returns the length.                       |
| `empty()`             | Checks if the view is empty.              |
| `remove_prefix(n)`    | Removes `n` characters from the start.    |
| `remove_suffix(n)`    | Removes `n` characters from the end.      |
| `substr(pos, len)`    | Returns a substring view.                 |
| `data()`              | Returns a pointer to the first character. |

### **📌 Example**

```c++
std::string_view sv = "Hello, World!";
std::cout << sv.substr(7) << std::endl;  // Output: World!
```



**🔹 5. `std::string` vs `std::string_view`**

| Feature              | `std::string`            | `std::string_view`      |
| -------------------- | ------------------------ | ----------------------- |
| **Memory Ownership** | Owns data                | Does not own            |
| **Mutability**       | Mutable                  | Immutable               |
| **Performance**      | Slower (copying)         | Faster (no copy)        |
| **Use Case**         | Storing & modifying text | Reading without copying |



**🔹 6. When to Use?**

- Use **`std::string`** when **modification** or **ownership** is needed.
- Use **`std::string_view`** for **read-only operations** to **avoid copies**.



**Summary**

✅ **`std::string`** is a powerful, dynamic string class.
✅ **`std::string_view`** is a lightweight **read-only reference** (C++17).
✅ Use **`std::string_view` in function parameters** to improve performance.
✅ C++20 adds **`starts_with()`** and **`ends_with()`** for better usability.





## 1. Strings in Modern c++

In C++, strings are typically managed using the `std::string` class from the Standard Library, which provides a more convenient and safer alternative to C-style strings (`char` arrays).

### Examples with `std::string` Member Functions

### 1. `string::append`

```c++
#include <iostream>
#include <string>

int main() {
    std::string str = "Hello";
    str.append(", World!"); // Append ", World!" to the end of str
    std::cout << "After append: " << str << std::endl; // Output the result
    return 0;
}
```

### Explanation

- `str.append(", World!");`: Adds the string ", World!" to the end of `str`.

### 2. `string::assign`

```c++
#include <iostream>
#include <string>

int main() {
    std::string str;
    str.assign("Hello, World!"); // Assign "Hello, World!" to str
    std::cout << "After assign: " << str << std::endl; // Output the result
    return 0;
}
```

### Explanation

- `str.assign("Hello, World!");`: Assigns the string "Hello, World!" to `str`.

### 3. `string::at`

```c++
#include <iostream>
#include <string>

int main() {
    std::string str = "Hello";
    try {
        char ch = str.at(1); // Access the character at index 1 (second character)
        std::cout << "Character at index 1: " << ch << std::endl; // Output the character
    } catch (const std::out_of_range &e) {
        std::cerr << "Index out of range: " << e.what() << std::endl; // Handle out-of-range error
    }
    return 0;
}
```

### Explanation

- `char ch = str.at(1);`: Accesses the character at index 1 (second character) in `str`, which is 'e'.

### 4. `string::back`

```c++
#include <iostream>
#include <string>

int main() {
    std::string str = "Hello";
    char ch = str.back(); // Access the last character
    std::cout << "Last character: " << ch << std::endl; // Output the character
    return 0;
}
```

### Explanation

- `char ch = str.back();`: Accesses the last character in `str`, which is 'o'.

### 5. `string::begin`

```c++
#include <iostream>
#include <string>

int main() {
    std::string str = "Hello";
    auto it = str.begin(); // Get iterator to the first character
    std::cout << "First character: " << *it << std::endl; // Output the character
    return 0;
}
```

### Explanation

- `auto it = str.begin();`: Gets an iterator to the first character in `str`.

### 6. `string::clear`

```c++
#include <iostream>
#include <string>

int main() {
    std::string str = "Hello, World!";
    str.clear(); // Clear the string
    std::cout << "After clear: " << str << std::endl; // Output the result (empty string)
    return 0;
}
```

### Explanation

- `str.clear();`: Clears all characters from `str`, making it an empty string.

### 7. `string::compare`

```c++
#include <iostream>
#include <string>

int main() {
    std::string str1 = "Hello";
    std::string str2 = "World";
    int result = str1.compare(str2); // Compare str1 with str2
    if (result == 0) {
        std::cout << "Strings are equal" << std::endl;
    } else if (result < 0) {
        std::cout << "str1 is less than str2" << std::endl;
    } else {
        std::cout << "str1 is greater than str2" << std::endl;
    }
    return 0;
}
```

### Explanation

- `int result = str1.compare(str2);`: Compares `str1` with `str2` lexicographically.

### 8. `string::c_str`

```c++
#include <iostream>
#include <string>

int main() {
    std::string str = "Hello, World!";
    const char* cstr = str.c_str(); // Get C-style string
    std::cout << "C-style string: " << cstr << std::endl; // Output the C-style string
    return 0;
}
```

### Explanation

- `const char* cstr = str.c_str();`: Converts `str` to a C-style string (null-terminated character array).

### 9. `string::capacity`

```c++
#include <iostream>
#include <string>

int main() {
    std::string str = "Hello";
    std::cout << "Capacity: " << str.capacity() << std::endl; // Output the capacity
    return 0;
}
```

### Explanation

- `std::cout << "Capacity: " << str.capacity() << std::endl;`: Outputs the number of characters that `str` can hold before needing to allocate more memory.

### 10. `string::copy`

```c++
#include <iostream>
#include <string>

int main() {
    std::string str = "Hello, World!";
    char buffer[6];
    str.copy(buffer, 5, 0); // Copy first 5 characters to buffer
    buffer[5] = '\0'; // Null-terminate the buffer
    std::cout << "Buffer: " << buffer << std::endl; // Output the buffer
    return 0;
}
```

### Explanation

- `str.copy(buffer, 5, 0);`: Copies the first 5 characters of `str` into `buffer`.
- `buffer[5] = '\0';`: Null-terminates the buffer to make it a valid C-style string.

### 11. `string::crbegin`

```c++
#include <iostream>
#include <string>

int main() {
    std::string str = "Hello";
    auto it = str.crbegin(); // Get reverse constant iterator to the last character
    std::cout << "Last character using crbegin: " << *it << std::endl; // Output the character
    return 0;
}
```

### Explanation

- `auto it = str.crbegin();`: Gets a reverse constant iterator to the last character in `str`.

### 12. `string::crend`

```c++
#include <iostream>
#include <string>

int main() {
    std::string str = "Hello";
    auto it = str.crend(); // Get reverse constant iterator to one past the first character
    std::cout << "Using crend, no character to output" << std::endl;
    return 0;
}
```

### Explanation

- `auto it = str.crend();`: Gets a reverse constant iterator to one past the first character in `str`.

### 13. `string::data`

```c++
#include <iostream>
#include <string>

int main() {
    std::string str = "Hello, World!";
    const char* data = str.data(); // Get pointer to internal data
    std::cout << "Data: " << data << std::endl; // Output the data
    return 0;
}
```

### Explanation

- `const char* data = str.data();`: Gets a pointer to the internal character array of `str`.

### 14. `string::empty`

```c++
#include <iostream>
#include <string>

int main() {
    std::string str = "Hello";
    bool isEmpty = str.empty(); // Check if the string is empty
    std::cout << "Is empty: " << std::boolalpha << isEmpty << std::endl; // Output the result
    return 0;
}
```

### Explanation

- `bool isEmpty = str.empty();`: Checks if `str` is empty.
- `std::cout << "Is empty: " << std::boolalpha << isEmpty << std::endl;`: Outputs `true` or `false` based on whether `str` is empty.

### 15. `string::erase`

```c++
#include <iostream>
#include <string>

int main() {
    std::string str = "Hello, World!";
    str.erase(5, 1); // Erase the character at index 5 (the comma)
    std::cout << "After erase: " << str << std::endl; // Output the result
    return 0;
}
```

### Explanation

- `str.erase(5, 1);`: Erases 1 character at index 5 (the comma), resulting in "Hello World!".

### 16. `string::find`

```c++
#include <iostream>
#include <string>

int main() {
    std::string str = "Hello, World!";
    size_t pos = str.find("World"); // Find the position of the substring "World"
    if (pos != std::string::npos) { // Check if the substring was found
        std::cout << "Found 'World' at position: " << pos << std::endl; // Output the position
    } else {
        std::cout << "'World' not found" << std::endl; // Output if not found
    }
    return 0;
}
```

### Explanation

- `size_t pos = str.find("World");`: Searches for the substring "World" in `str` and stores the position in `pos`.
- `if (pos != std::string::npos)`: Checks if "World" was found (`npos` indicates not found).
- `std::cout << "Found 'World' at position: " << pos << std::endl;`: Prints the position of "World".
- `std::cout << "'World' not found" << std::endl;`: Prints that "World" was not found if it is not present.

### 17. `string::find_first_not_of`

```c++
#include <iostream>
#include <string>

int main() {
    std::string str = "abcde";
    size_t pos = str.find_first_not_of("abc"); // Find the first character not in "abc"
    if (pos != std::string::npos) { // Check if such character was found
        std::cout << "First character not in 'abc' is at position: " << pos << std::endl; // Output the position
    } else {
        std::cout << "All characters are in 'abc'" << std::endl; // Output if all characters are in "abc"
    }
    return 0;
}
```

### Explanation

- `size_t pos = str.find_first_not_of("abc");`: Finds the first character in `str` that is not in "abc".
- `if (pos != std::string::npos)`: Checks if such a character was found.
- `std::cout << "First character not in 'abc' is at position: " << pos << std::endl;`: Prints the position of the first character not in "abc".
- `std::cout << "All characters are in 'abc'" << std::endl;`: Prints that all characters are in "abc" if no such character is found.

### 18. `string::find_first_of`

```c++
#include <iostream>
#include <string>

int main() {
    std::string str = "Hello, World!";
    size_t pos = str.find_first_of("aeiou"); // Find the first vowel
    if (pos != std::string::npos) { // Check if such character was found
        std::cout << "First vowel is at position: " << pos << std::endl; // Output the position
    } else {
        std::cout << "No vowels found" << std::endl; // Output if no vowels are found
    }
    return 0;
}
```

### Explanation

- `size_t pos = str.find_first_of("aeiou");`: Finds the first vowel in `str`.
- `if (pos != std::string::npos)`: Checks if a vowel was found.
- `std::cout << "First vowel is at position: " << pos << std::endl;`: Prints the position of the first vowel.
- `std::cout << "No vowels found" << std::endl;`: Prints that no vowels were found if none are present.

### 19. `string::find_last_not_of`

```c++
#include <iostream>
#include <string>

int main() {
    std::string str = "abcde";
    size_t pos = str.find_last_not_of("de"); // Find the last character not in "de"
    if (pos != std::string::npos) { // Check if such character was found
        std::cout << "Last character not in 'de' is at position: " << pos << std::endl; // Output the position
    } else {
        std::cout << "All characters are in 'de'" << std::endl; // Output if all characters are in "de"
    }
    return 0;
}
```

### Explanation

- `size_t pos = str.find_last_not_of("de");`: Finds the last character in `str` that is not in "de".
- `if (pos != std::string::npos)`: Checks if such a character was found.
- `std::cout << "Last character not in 'de' is at position: " << pos << std::endl;`: Prints the position of the last character not in "de".
- `std::cout << "All characters are in 'de'" << std::endl;`: Prints that all characters are in "de" if no such character is found.

### 20. `string::find_last_of`

```c++
#include <iostream>
#include <string>

int main() {
    std::string str = "Hello, World!";
    size_t pos = str.find_last_of("aeiou"); // Find the last vowel
    if (pos != std::string::npos) { // Check if such character was found
        std::cout << "Last vowel is at position: " << pos << std::endl; // Output the position
    } else {
        std::cout << "No vowels found" << std::endl; // Output if no vowels are found
    }
    return 0;
}
```

### Explanation

- `size_t pos = str.find_last_of("aeiou");`: Finds the last vowel in `str`.
- `if (pos != std::string::npos)`: Checks if a vowel was found.
- `std::cout << "Last vowel is at position: " << pos << std::endl;`: Prints the position of the last vowel.
- `std::cout << "No vowels found" << std::endl;`: Prints that no vowels were found if none are present.

### 21. `string::front`

```c++
#include <iostream>
#include <string>

int main() {
    std::string str = "Hello";
    char ch = str.front(); // Access the first character
    std::cout << "First character: " << ch << std::endl; // Output the character
    return 0;
}
```

### Explanation

- `char ch = str.front();`: Accesses the first character in `str`, which is 'H'.

### 22. `string::insert`

```c++
#include <iostream>
#include <string>

int main() {
    std::string str = "Hello, World!";
    str.insert(7, "beautiful "); // Insert "beautiful " at index 7
    std::cout << "After insert: " << str << std::endl; // Output the modified string
    return 0;
}
```

### Explanation

- `str.insert(7, "beautiful ");`: Inserts the string "beautiful " at index 7 in `str`, resulting in "Hello, beautiful World!".

### 23. `string::length` and `string::size`

```c++
#include <iostream>
#include <string>

int main() {
    std::string str = "Hello, World!";
    std::cout << "Length: " << str.length() << std::endl; // Output the length of the string
    std::cout << "Size: " << str.size() << std::endl; // Output the size of the string
    return 0;
}
```

### Explanation

- `std::cout << "Length: " << str.length() << std::endl;`: Outputs the length of `str`.
- `std::cout << "Size: " << str.size() << std::endl;`: Outputs the size of `str` (identical to length).

### 24. `string::max_size`

```c++
#include <iostream>
#include <string>

int main() {
    std::string str = "Hello, World!";
    std::cout << "Max size: " << str.max_size() << std::endl; // Output the maximum size of the string
    return 0;
}
```

### Explanation

- `std::cout << "Max size: " << str.max_size() << std::endl;`: Outputs the maximum size that `str` can hold.

### 25. `string::push_back`

```c++
#include <iostream>
#include <string>

int main() {
    std::string str = "Hello";
    str.push_back('!'); // Append '!' to the end of str
    std::cout << "After push_back: " << str << std::endl; // Output the modified string
    return 0;
}
```

### Explanation

- `str.push_back('!');`: Appends the character '!' to the end of `str`, resulting in "Hello!".

### 26. `string::pop_back`

```c++
#include <iostream>
#include <string>

int main() {
    std::string str = "Hello!";
    str.pop_back(); // Remove the last character
    std::cout << "After pop_back: " << str << std::endl; // Output the modified string
    return 0;
}
```

### Explanation

- `str.pop_back();`: Removes the last character from `str`, resulting in "Hello".

### 27. `string::replace`

```c++
#include <iostream>
#include <string>

int main() {
    std::string str = "Hello, World!";
    str.replace(7, 5, "Universe"); // Replace "World" (5 characters at index 7) with "Universe"
    std::cout << "After replace: " << str << std::endl; // Output the modified string
    return 0;
}
```

### Explanation

- `str.replace(7, 5, "Universe");`: Replaces 5 characters starting at index 7 ("World") with "Universe", resulting in "Hello, Universe!".

### 28. `string::reserve`

```c++
#include <iostream>
#include <string>

int main() {
    std::string str;
    str.reserve(50); // Reserve capacity for 50 characters
    std::cout << "Reserved capacity: " << str.capacity() << std::endl; // Output the reserved capacity
    return 0;
}
```

### Explanation

- `str.reserve(50);`: Reserves enough memory for `str` to hold 50 characters without reallocation.

### 29. `string::resize`

```c++
#include <iostream>
#include <string>

int main() {
    std::string str = "Hello";
    str.resize(10, 'x'); // Resize the string to 10 characters, padding with 'x'
    std::cout << "After resize: " << str << std::endl; // Output the modified string
    return 0;
}
```

### Explanation

- `str.resize(10, 'x');`: Resizes `str` to 10 characters, padding with 'x' if necessary, resulting in "Helloxxxxx".

### 30. `string::rfind`

```c++
#include <iostream>
#include <string>

int main() {
    std::string str = "Hello, World! World!";
    size_t pos = str.rfind("World"); // Find the last occurrence of "World"
    if (pos != std::string::npos) { // Check if such occurrence was found
        std::cout << "Last 'World' found at position: " << pos << std::endl; // Output the position
    } else {
        std::cout << "'World' not found" << std::endl; // Output if not found
    }
    return 0;
}
```

### Explanation

- `size_t pos = str.rfind("World");`: Finds the last occurrence of "World" in `str`.
- `if (pos != std::string::npos)`: Checks if "World" was found.
- `std::cout << "Last 'World' found at position: " << pos << std::endl;`: Prints the position of the last occurrence of "World".
- `std::cout << "'World' not found" << std::endl;`: Prints that "World" was not found if it is not present.

### 31. `string::substr`

```c++
#include <iostream>
#include <string>

int main() {
    std::string str = "Hello, World!";
    std::string sub = str.substr(7, 5); // Get substring starting at index 7 of length 5
    std::cout << "Substring: " << sub << std::endl; // Output the substring
    return 0;
}
```

### Explanation

- `std::string sub = str.substr(7, 5);`: Extracts a substring from `str` starting at index 7 with length 5, resulting in "World".

### 32. `string::swap`

```c++
#include <iostream>
#include <string>

int main() {
    std::string str1 = "Hello";
    std::string str2 = "World";
    str1.swap(str2); // Swap the contents of str1 and str2
    std::cout << "After swap, str1: " << str1 << std::endl; // Output the modified str1
    std::cout << "After swap, str2: " << str2 << std::endl; // Output the modified str2
    return 0;
}
```

### Explanation

- `str1.swap(str2);`: Swaps the contents of `str1` and `str2`.



## String view

`std::string_view` is a lightweight, non-owning view of a substring of another string. It is part of the C++17 standard library and provides an efficient way to work with substrings without copying data. It is particularly useful when you need to pass around parts of strings or perform read-only operations without the overhead of constructing `std::string` objects.

### Key Features of `std::string_view`:

1. **Non-owning**: It does not own the data it points to. It is simply a view over an existing string.
2. **Efficient**: Since it does not own the data, operations like copying a `std::string_view` are cheap.
3. **Safe**: You can use it to safely refer to substrings without risking dangling pointers, provided the original string remains in scope.

### Basic Usage of `std::string_view`:

#### Example 1: Creating a `std::string_view`

```c++
#include <iostream>
#include <string>
#include <string_view>

int main() {
    std::string str = "Hello, World!";
    std::string_view sv(str); // Create a string_view of the entire string
    std::cout << "string_view: " << sv << std::endl;
    return 0;
}
```

### Explanation:

- `std::string str = "Hello, World!";`: Define a `std::string`.
- `std::string_view sv(str);`: Create a `std::string_view` that views the entire string `str`.
- `std::cout << "string_view: " << sv << std::endl;`: Print the contents of the `std::string_view`.

#### Example 2: Creating a Substring View

```c++
#include <iostream>
#include <string>
#include <string_view>

int main() {
    std::string str = "Hello, World!";
    std::string_view sv(str.c_str() + 7, 5); // Create a string_view of "World"
    std::cout << "Substring view: " << sv << std::endl;
    return 0;
}
```

### Explanation:

- `std::string str = "Hello, World!";`: Define a `std::string`.
- `std::string_view sv(str.c_str() + 7, 5);`: Create a `std::string_view` that views the substring "World".
- `std::cout << "Substring view: " << sv << std::endl;`: Print the contents of the `std::string_view`.

#### Example 3: Using `std::string_view` in Functions

```c++
#include <iostream>
#include <string>
#include <string_view>

void printSubstring(std::string_view sv) {
    std::cout << "Substring: " << sv << std::endl;
}

int main() {
    std::string str = "Hello, World!";
    printSubstring(str.substr(7, 5)); // Pass a substring to the function
    return 0;
}
```

### Explanation:

- `void printSubstring(std::string_view sv)`: Define a function that takes a `std::string_view` as a parameter.
- `std::cout << "Substring: " << sv << std::endl;`: Print the `std::string_view`.
- `printSubstring(str.substr(7, 5));`: Call the function with a substring of `str`.

#### Example 4: Using `std::string_view` with Literals

```c++
#include <iostream>
#include <string_view>

int main() {
    std::string_view sv("Hello, World!", 5); // Create a string_view of "Hello"
    std::cout << "Literal view: " << sv << std::endl;
    return 0;
}
```

### Explanation:

- `std::string_view sv("Hello, World!", 5);`: Create a `std::string_view` that views the first 5 characters of the string literal.
- `std::cout << "Literal view: " << sv << std::endl;`: Print the contents of the `std::string_view`.

### Methods and Operations with `std::string_view`:

#### Example 5: Using `data()`, `size()`, and `empty()`

```c++
#include <iostream>
#include <string>
#include <string_view>

int main() {
    std::string str = "Hello, World!";
    std::string_view sv(str);
    std::cout << "Data: " << sv.data() << std::endl;   // Output the data pointer
    std::cout << "Size: " << sv.size() << std::endl;   // Output the size of the view
    std::cout << "Is empty: " << std::boolalpha << sv.empty() << std::endl; // Check if the view is empty
    return 0;
}
```

### Explanation:

- `std::string_view sv(str);`: Create a `std::string_view` that views the entire string `str`.
- `sv.data()`: Returns a pointer to the character data.
- `sv.size()`: Returns the size of the view.
- `sv.empty()`: Checks if the view is empty.

#### Example 6: Using `remove_prefix()` and `remove_suffix()`

```c++
#include <iostream>
#include <string>
#include <string_view>

int main() {
    std::string str = "Hello, World!";
    std::string_view sv(str);
    sv.remove_prefix(7); // Remove the first 7 characters
    sv.remove_suffix(1); // Remove the last character
    std::cout << "After remove_prefix and remove_suffix: " << sv << std::endl;
    return 0;
}
```

### Explanation:

- `sv.remove_prefix(7);`: Removes the first 7 characters, resulting in "World!".
- `sv.remove_suffix(1);`: Removes the last character, resulting in "World".

#### Example 7: Using `compare()`

```c++
#include <iostream>
#include <string>
#include <string_view>

int main() {
    std::string str1 = "Hello";
    std::string str2 = "Hello, World!";
    std::string_view sv1(str1);
    std::string_view sv2(str2.substr(0, 5)); // Create a view of "Hello"
    if (sv1.compare(sv2) == 0) { // Compare the two views
        std::cout << "Views are equal" << std::endl;
    } else {
        std::cout << "Views are not equal" << std::endl;
    }
    return 0;
}
```

### Explanation:

- `std::string_view sv2(str2.substr(0, 5));`: Create a `std::string_view` of the substring "Hello".
- `sv1.compare(sv2) == 0`: Compares the two views. If they are equal, it prints "Views are equal".

