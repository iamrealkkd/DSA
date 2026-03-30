#include<iostream>
using namespace std;

int main() {
    int n = 4;

    int start = 1;

    for(int i = 1; i <= n; i++) {

        int x = start;

        for(int j = 1; j <= i; j++) {
            cout << x << " ";
            x += 2;
        }

        start = start + i;
        cout << endl;
    }

    return 0;
}
