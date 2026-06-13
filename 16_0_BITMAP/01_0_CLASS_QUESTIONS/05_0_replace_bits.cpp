#include <iostream>
using namespace std;

// Clear bits from i to j
void clearBitsInRange(int &n, int i, int j) {
    int a = (~0) << (j + 1);
    int b = (1 << i) - 1;
    int mask = a | b;

    n = n & mask;
}

// Replace bits from i to j with m
void replaceBits(int &n, int i, int j, int m) {
    clearBitsInRange(n, i, j);

    int mask = (m << i);
    n = n | mask;
}

int main() {

    int n = 15;
    int i = 1;
    int j = 3;
    int m = 2;

    replaceBits(n, i, j, m);

    cout << n << endl;

    return 0;
}