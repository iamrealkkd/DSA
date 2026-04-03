#include <iostream>
using namespace std;

int main() {

    int arr[5] = {2, 3, 4, 5, 6};
    int minValue = arr[0];

    for (int i = 1; i < 5; i++) {
        if (arr[i] < minValue) {
            minValue = arr[i];
        }
    }

    cout << "Minimum value: " << minValue << endl;

    return 0;
}