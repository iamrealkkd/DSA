#include <iostream>

using namespace std;

void swapMaxMin(int arr[], int size) {

    int max = arr[0];
    int min = arr[0];

    for (int i = 0; i < size; i++) {
        if (arr[i] > max) {
            max = arr[i];
        }
    }

    for (int i = 0; i < size; i++) {
        if (arr[i] < min) {
            min = arr[i];
        }
    }

    cout << "Max and Min values in the array are:" << endl;
    cout << max << endl;
    cout << min << endl;

    cout << "Swapping the values..." << endl;

    swap(max, min);

    cout << max << endl;
    cout << min << endl;
}

int main() {

    int arr[5] = {1, 2, 3, 4, 5};
    int size = 5;

    swapMaxMin(arr, size);

    return 0;
}