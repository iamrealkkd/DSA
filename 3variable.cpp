#include <iostream>
using namespace std;

int main() {
    // Declare two variables and a temporary variable
    int a = 5, b = 10, temp;

    // Display initial values
    cout << "Before swapping:" << endl;
    cout << "a = " << a << ", b = " << b << endl;

    // Swap the values using a third variable
    temp = a; // Store value of a in temp
    a = b;    // Assign value of b to a
    b = temp; // Assign value of temp (original a) to b

    // Display swapped values
    cout << "After swapping:" << endl;
    cout << "a = " << a << ", b = " << b << endl;

    return 0;
}
