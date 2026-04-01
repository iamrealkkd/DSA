#include <iostream>
using namespace std;

int gcdRecursive(int a, int b) {

    if (b == 0)
        return a;

    return gcdRecursive(b, a % b);
}

int main() {

    int a, b;

    cout << "Enter two numbers: ";
    cin >> a >> b;

    cout << "GCD (Recursive) = " << gcdRecursive(a, b) << endl;

    return 0;
}