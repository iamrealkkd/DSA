#include <iostream>
using namespace std;

void moduloExamples(int x, int y, int m) {

    int addition = (x % m + y % m) % m;

    int subtraction = (x % m - y % m + m) % m;

    long long multiplication = (1LL * (x % m) * (y % m)) % m;

    cout << "Modular Addition: " << addition << endl;
    cout << "Modular Subtraction: " << subtraction << endl;
    cout << "Modular Multiplication: " << multiplication << endl;

}

int main() {

    int x, y, m;

    cout << "Enter x y and modulus m: ";
    cin >> x >> y >> m;

    moduloExamples(x, y, m);

    return 0;
}