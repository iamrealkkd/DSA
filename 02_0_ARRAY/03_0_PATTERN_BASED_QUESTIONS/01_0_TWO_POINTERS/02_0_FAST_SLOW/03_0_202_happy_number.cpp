#include <iostream>
using namespace std;

class Solution {
public:
  int squaresum(int n) {
    int sum = 0;

    while (n > 0) {
      int dig = n % 10;
      sum += dig * dig;
      n /= 10;
    }

    return sum;
  }

  bool isHappy(int n) {
    int slow = n;
    int fast = n;

    do {
      slow = squaresum(slow);
      fast = squaresum(squaresum(fast));
    } while (slow != fast);

    return slow == 1;
  }
};

int main() {
  Solution obj;

  int n = 19;

  if (obj.isHappy(n))
    cout << n << " is a Happy Number." << endl;
  else
    cout << n << " is NOT a Happy Number." << endl;

  return 0;
}