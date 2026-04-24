#include <iostream>

using namespace std;

int main() {

    int arr[5] = {1, 2, 3, 4, 5};
    int size = 5;
    int sum = 0;

    for (int i = 0; i < size; i++) {
        sum += arr[i];
    }

    cout << "Sum of array is: " << sum << endl;

    return 0;
}