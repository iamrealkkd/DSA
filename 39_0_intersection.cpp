#include <iostream>
using namespace std;

void printIntersection(int arr1[], int n1, int arr2[], int n2) {
    cout << "Intersection of the two arrays: ";
    for (int i = 0; i < n1; i++) {
        for (int j = 0; j < n2; j++) {
            if (arr1[i] == arr2[j]) {
                cout << arr1[i] << " ";
                break;
            }
        }
    }
    cout << endl;
}

int main() {
    int arr1[] = {1, 2, 3, 4, 5};
    int arr2[] = {4, 5, 6, 7, 8};
    int n1 = sizeof(arr1) / sizeof(arr1[0]);
    int n2 = sizeof(arr2) / sizeof(arr2[0]);

    printIntersection(arr1, n1, arr2, n2);

    return 0;
}
