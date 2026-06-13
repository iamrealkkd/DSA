#include <iostream>
using namespace std;

// Get i-th Bit
int getIthBit(int n, int i) {
    int mask = (1 << i);
    return (n & mask) > 0 ? 1 : 0;
}

// Set i-th Bit
void setIthBit(int &n, int i) {
    int mask = (1 << i);
    n = n | mask;
}

// Clear i-th Bit
void clearIthBit(int &n, int i) {
    int mask = ~(1 << i);
    n = n & mask;
}

// Update i-th Bit with value v (0 or 1)
void updateIthBit(int &n, int i, int v) {
    clearIthBit(n, i);

    int mask = (v << i);
    n = n | mask;
}

// Clear Last i Bits
void clearLastIBits(int &n, int i) {
    int mask = (-1 << i);
    n = n & mask;
}

int main() {

    int choice;

    cout << "1. Get i-th Bit\n";
    cout << "2. Set i-th Bit\n";
    cout << "3. Clear i-th Bit\n";
    cout << "4. Update i-th Bit\n";
    cout << "5. Clear Last i Bits\n";
    cout << "Enter Choice: ";
    cin >> choice;

    int n, i, v;

    switch (choice) {

        case 1:
            cout << "Enter n and i: ";
            cin >> n >> i;
            cout << getIthBit(n, i) << endl;
            break;

        case 2:
            cout << "Enter n and i: ";
            cin >> n >> i;
            setIthBit(n, i);
            cout << n << endl;
            break;

        case 3:
            cout << "Enter n and i: ";
            cin >> n >> i;
            clearIthBit(n, i);
            cout << n << endl;
            break;

        case 4:
            cout << "Enter n, i and value(0/1): ";
            cin >> n >> i >> v;
            updateIthBit(n, i, v);
            cout << n << endl;
            break;

        case 5:
            cout << "Enter n and i: ";
            cin >> n >> i;
            clearLastIBits(n, i);
            cout << n << endl;
            break;

        default:
            cout << "Invalid Choice!" << endl;
    }

    return 0;
}