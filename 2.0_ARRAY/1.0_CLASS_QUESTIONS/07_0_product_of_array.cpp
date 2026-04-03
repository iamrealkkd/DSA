#include <iostream>

using namespace std;

int main() {

    int arr[5] = {1, 2, 3, 4, 5};
    int size = 5;
    int product = 1;

    for (int i = 0; i < size; i++) {
        product *= arr[i];
    }

    cout << "Product of array is: " << product << endl;

    return 0;
}