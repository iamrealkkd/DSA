#include <iostream>
using namespace std;

bool isArmstrong(int n) {
    int copyN = n;
    int sumOfCubes = 0;

    while (n > 0) {
        int dig = n % 10;
        sumOfCubes += dig * dig * dig;
        n /= 10;
    }

    return sumOfCubes == copyN;
}

int main() {
    int n;

    cout << "Enter a number: ";
    cin >> n;

    if (isArmstrong(n))
        cout << n << " is an Armstrong number\n";
    else
        cout << n << " is NOT an Armstrong number\n";

    return 0;
}