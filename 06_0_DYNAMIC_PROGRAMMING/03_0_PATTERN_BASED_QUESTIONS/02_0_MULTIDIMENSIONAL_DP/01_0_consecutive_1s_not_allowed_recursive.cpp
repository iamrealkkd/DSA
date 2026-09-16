#include <iostream>
using namespace std;

int rec(int n, int prev) {
  if (n == 0)
    return 1;

  int put0 = rec(n - 1, 0);

  int put1 = 0;

  if (prev != 1) {
    put1 = rec(n - 1, 1);
  }

  return put0 + put1;
}

int main() {
  int n = 3;

  cout << rec(n, 0) << endl;

  return 0;
}