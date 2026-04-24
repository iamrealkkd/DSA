#include <iostream>
using namespace std;

int gcdIterative(int a, int b) {

    while (a > 0 && b > 0) {

        if (a > b)
            a = a % b;
        else
            b = b % a;

    }

    if (a == 0)
        return b;
    else
        return a;
}

int main() {

    int a, b;

    cout << "Enter two numbers: ";
    cin >> a >> b;

    cout << "GCD (Iterative) = " << gcdIterative(a, b) << endl;

    return 0;
}