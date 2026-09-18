#include <iostream>
using namespace std;

int solve(int x, int y) {
  if (x == 0 && y == 0)
    return 1;

  if (x < 0 || y < 0)
    return 0;

  return solve(x - 1, y) + solve(x, y - 1);
}

int ways(int x, int y) { return solve(x, y); }

int main() {
  int x = 3;
  int y = 0;

  cout << ways(x, y);

  return 0;
}