#include <iostream>
#include <iostream>
using namespace std;

void printDigits(int n) {
    while (n != 0) {
        int digit = n % 10;
        cout << digit << endl;
        n = n / 10;
    }
}

int main() {
    int n;

    cout << "Enter a number: ";
    cin >> n;

    cout << "Digits of the number are:\n";
    printDigits(n);

    return 0;
}