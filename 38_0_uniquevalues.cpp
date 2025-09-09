#include <iostream>
using namespace std;

void printUniqueNumbers(int arr[], int n) {
    int i,j;
    cout << "Unique numbers are: ";
    for (i = 0; i < n; i++) {
        int count =0;
        for (j = 0; j < n; j++) {
            if (arr[i] == arr[j]) {
                count++;
            }
            }
            if (count == 1) {
            cout << arr[i] << " ";
        }
        }
        
}


int main() {
    int arr[] = {1, 2, 2, 3, 4, 5, 6, 8, 8, 9, 10, 10};
    int n = sizeof(arr) / sizeof(arr[0]);

    printUniqueNumbers(arr, n);

    return 0;
}
