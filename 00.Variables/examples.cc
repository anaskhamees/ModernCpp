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

