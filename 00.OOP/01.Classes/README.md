# Classes and Objects
### **Memory Allocation for a Class Instance (Object)**

When you create an **object** from a class in C++, memory is allocated for the **non-static data members (attributes)** of the class. However, methods and static members are not stored in each instance. Instead:

1. **Each object gets its own copy of non-static data members** (variables).
2. **Methods are shared among all instances** of the class and exist only once in memory.
3. **Static members are shared among all instances** and are stored separately in a fixed memory location.

-----------------------

When you instantiate an object of a class, memory is allocated in different regions:

#### **Example Class**

```c++
class Example {
public:
    int a;            // Non-static member variable
    static int b;     // Static member variable
    void func() {}    // Member function
};

int Example::b = 0;   // Static member initialization

int main() {
    Example obj1; // Object creation
}
```

When `obj1` is created, memory is allocated as follows:

| **Component**     | **Stored in Memory**            | **Allocated Per Object?**            |
| ----------------- | ------------------------------- | ------------------------------------ |
| `a` (non-static)  | Inside the object in stack/heap | ✅ Yes, each object gets its own copy |
| `b` (static)      | Separate memory (Data Segment)  | ❌ No, shared by all objects          |
| `func()` (method) | Stored in **Code Segment**      | ❌ No, shared by all objects          |

------

### **How Methods Work in Memory**

- Member functions are stored **only once** in the **code segment**.
- Objects access member functions through a **hidden pointer (`this`)**, which tells the function which object's data it should operate on.

For example, when calling:

```c++
obj1.func();
```

- The function **does not exist inside `obj1`**.
- Instead, `func()` is located in a shared memory area, and `obj1` passes itself (`this` pointer) when calling it.

------

### **Is There a "Link" to the Class?**

Yes, in a way:

- **Virtual tables (`vtable`)**: If the class has **virtual functions**, the object stores a pointer to the **vtable**, which allows it to dynamically resolve function calls at runtime.
- **RTTI (Run-Time Type Information)**: If `typeid` or dynamic casting is used, some compilers add extra hidden metadata about the class.
