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

// #include <iostream>
//     using namespace std;

// int rec(int n, int prev) {

//   // MAIN CALL:
//   // rec(3, 0)
//   //
//   // n = 3, prev = 0
//   // n == 0? NO
//   //
//   // First calculate:
//   // put0 = rec(2, 0)
//   //
//   // =====================================================
//   // rec(2, 0)
//   // n == 0? NO
//   //
//   // put0 = rec(1, 0)
//   //
//   // =====================================================
//   // rec(1, 0)
//   // n == 0? NO
//   //
//   // put0 = rec(0, 0)
//   //
//   // =====================================================
//   // rec(0, 0)
//   // n == 0? YES
//   // return 1
//   //
//   // So rec(1,0) gets:
//   // put0 = 1

//   if (n == 0)
//     return 1;

//   int put0 = rec(n - 1, 0);

//   // For rec(1,0):
//   // rec(0,0) returned 1
//   // Therefore:
//   // put0 = 1

//   int put1 = 0;

//   // IMPORTANT:
//   // We initialize put1 = 0.
//   //
//   // Why?
//   // Because if prev == 1, we are NOT allowed to put 1 again.
//   // In that case, "put1" contributes 0 valid ways.

//   if (prev != 1) {

//     // For rec(1,0):
//     // prev = 0
//     // 0 != 1 → TRUE
//     //
//     // Therefore:
//     // put1 = rec(0,1)
//     //
//     // rec(0,1):
//     // n == 0 → YES
//     // return 1
//     //
//     // Therefore:
//     // put1 = 1
//   }

//   // For rec(1,0):
//   //
//   // put0 = 1
//   // put1 = 1
//   //
//   // return 1 + 1 = 2
//   //
//   // Therefore:
//   // rec(1,0) = 2

//   return put0 + put1;
// }

// int main() {

//   int n = 3;

//   // Starting call:
//   // rec(3,0)

//   cout << rec(n, 0) << endl;

//   // ------------------------------------------------------
//   // Let's trace the remaining calls:
//   //
//   // rec(3,0)
//   //
//   // put0 = rec(2,0)
//   //
//   // We already calculate:
//   // rec(2,0) = 3
//   //
//   // Therefore:
//   // put0 = 3
//   //
//   //
//   // Now put1:
//   //
//   // put1 = 0
//   //
//   // prev = 0
//   // 0 != 1 → TRUE
//   //
//   // So:
//   // put1 = rec(2,1)
//   //
//   // ------------------------------------------------------
//   // rec(2,1)
//   //
//   // put0 = rec(1,0)
//   //
//   // rec(1,0) = 2
//   //
//   // Therefore:
//   // put0 = 2
//   //
//   // put1 = 0
//   //
//   // prev = 1
//   // 1 != 1 → FALSE
//   //
//   // So the if block DOES NOT RUN.
//   //
//   // put1 remains 0.
//   //
//   // Therefore:
//   // rec(2,1) = 2 + 0 = 2
//   //
//   // ------------------------------------------------------
//   //
//   // Back to rec(3,0):
//   //
//   // put0 = 3
//   // put1 = 2
//   //
//   // return 3 + 2 = 5
//   //
//   // FINAL ANSWER = 5

//   return 0;
// }
