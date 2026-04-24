#include <iostream>

using namespace std;

int main() {

    int highest[5] = {2, 3, 4, 5, 6};
    int maximum = highest[0];

    for (int i = 0; i < 5; i++) {
        if (highest[i] > maximum) {
            maximum = highest[i];
        }
    }

    cout << maximum << endl;

    return 0;
}