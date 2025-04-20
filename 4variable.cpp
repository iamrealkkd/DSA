#include <iostream>
using namespace std;

int main() {
    // Declare variables for length, width, and area
    float length, width, area;

    // Input length and width
    cout << "Enter the length of the rectangle: ";
    cin >> length;

    cout << "Enter the width of the rectangle: ";
    cin >> width;

    // Calculate the area
    area = length * width;

    // Display the result
    cout << "The area of the rectangle is: " << area << endl;

    return 0;
}
