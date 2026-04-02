#include <iostream>

using namespace std;

void changeArray(int arr[], int size) {

    cout << "Inside function:" << endl;

    for (int i = 0; i < size; i++) {
        int value = arr[i];
        value = 5 * value;
        cout << value << " ";
    }

    cout << endl;
}

int main() {

    int arr[5] = {1, 2, 3, 4, 5};

    changeArray(arr, 5);

    cout << "Inside main function:" << endl;

    for (int i = 0; i < 5; i++) {
        cout << arr[i] << " ";
    }

    cout << endl;

    return 0;
}