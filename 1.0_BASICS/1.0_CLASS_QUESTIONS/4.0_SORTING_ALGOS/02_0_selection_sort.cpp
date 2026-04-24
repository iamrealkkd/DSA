#include <iostream>
using namespace std;

int main() {

    int arr[] = {5, 2, 9, 1, 6};
    int n = 5;

    for(int i = 0; i < n-1; i++){

        int minIndex = i;

        for(int j = i+1; j < n; j++){
            if(arr[j] < arr[minIndex]){
                minIndex = j;
            }
        }

        swap(arr[i], arr[minIndex]);
    }

    cout << "Sorted Array:\n";

    for(int i = 0; i < n; i++){
        cout << arr[i] << " ";
    }

    return 0;
}