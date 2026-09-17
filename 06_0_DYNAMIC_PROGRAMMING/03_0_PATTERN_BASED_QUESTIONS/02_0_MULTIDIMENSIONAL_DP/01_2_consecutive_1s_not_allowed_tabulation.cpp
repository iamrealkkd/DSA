#include <iostream>
#include <vector>
using namespace std;

int main() {
  int n = 3;

  vector<vector<int>> dp(n + 1, vector<int>(2, 0));

  dp[0][0] = 1;
  dp[0][1] = 1;

  for (int i = 1; i <= n; i++) {
    dp[i][0] = dp[i - 1][0] + dp[i - 1][1];
    dp[i][1] = dp[i - 1][0];
  }

  cout << dp[n][0] << endl;

  return 0;
}

// #include <iostream>
// #include <vector>
//     using namespace std;

// int main() {

//   int n = 3;

//   // ---------------------------------------------------------
//   // DP MATRIX
//   // ---------------------------------------------------------
//   //
//   // dp[i][prev]
//   //
//   // i    = kitni positions abhi consider kar rahe hain
//   // prev = previous value (0 or 1)
//   //
//   // n = 3, so matrix size = (n+1) x 2
//   //
//   //             prev
//   //             0    1
//   //          +---------+
//   // i = 0    |  0    0 |
//   // i = 1    |  0    0 |
//   // i = 2    |  0    0 |
//   // i = 3    |  0    0 |
//   //          +---------+
//   //
//   // Row    -> i
//   // Column -> prev
//   //
//   // ---------------------------------------------------------

//   vector<vector<int>> dp(n + 1, vector<int>(2, 0));

//   // ---------------------------------------------------------
//   // BASE CASE
//   // ---------------------------------------------------------
//   //
//   // dp[0][0] = 1
//   // dp[0][1] = 1
//   //
//   // Meaning:
//   // Agar 0 positions left hain, toh ek hi way hai:
//   //
//   //             "kuch mat karo"
//   //
//   // Ye previous value 0 ho ya 1,
//   // dono cases mein 1 valid way hai.
//   //
//   // Matrix:
//   //
//   //             prev
//   //             0    1
//   //          +---------+
//   // i = 0    |  1    1 |
//   // i = 1    |  0    0 |
//   // i = 2    |  0    0 |
//   // i = 3    |  0    0 |
//   //          +---------+

//   dp[0][0] = 1;
//   dp[0][1] = 1;

//   // ---------------------------------------------------------
//   // TABULATION
//   // ---------------------------------------------------------
//   //
//   // i = 1 se n tak matrix ko bottom-up fill karenge.
//   //
//   // IMPORTANT:
//   //
//   // Yahan 2 variables change nahi ho rahe.
//   //
//   // i -> loop ke through change ho raha hai.
//   //
//   // prev -> sirf 2 possible states hain:
//   //         0 and 1
//   //
//   // Hum inner loop lagane ke bajay directly dono
//   // columns calculate kar rahe hain:
//   //
//   // dp[i][0]
//   // dp[i][1]
//   //
//   // Isliye 2 loops ki zaroorat nahi hai.
//   //
//   // Agar inner loop lagate toh:
//   //
//   // for (int i = 1; i <= n; i++) {
//   //     for (int prev = 0; prev <= 1; prev++) {
//   //         ...
//   //     }
//   // }
//   //
//   // Lekin yahan prev ke sirf 2 states hain,
//   // isliye directly dono calculate kar diye.
//   //
//   // ---------------------------------------------------------

//   for (int i = 1; i <= n; i++) {

//     // -------------------------------------------------------
//     // dp[i][0]
//     // -------------------------------------------------------
//     //
//     // Current value = 0
//     //
//     // Agar 0 put karna hai,
//     // toh previous value 0 bhi ho sakti hai
//     // aur 1 bhi.
//     //
//     // Therefore:
//     //
//     // dp[i][0]
//     //     =
//     // dp[i-1][0] + dp[i-1][1]
//     //
//     // -------------------------------------------------------

//     dp[i][0] = dp[i - 1][0] + dp[i - 1][1];

//     // -------------------------------------------------------
//     // dp[i][1]
//     // -------------------------------------------------------
//     //
//     // Current value = 1
//     //
//     // Consecutive 1 allowed nahi hai.
//     //
//     // Isliye previous value MUST be 0.
//     //
//     // Therefore:
//     //
//     // dp[i][1]
//     //     =
//     // dp[i-1][0]
//     //
//     // -------------------------------------------------------

//     dp[i][1] = dp[i - 1][0];

//     // -------------------------------------------------------
//     // DRY RUN
//     // -------------------------------------------------------
//     //
//     // Initially:
//     //
//     //             0    1
//     //          +---------+
//     // i = 0    |  1    1 |
//     // i = 1    |  0    0 |
//     // i = 2    |  0    0 |
//     // i = 3    |  0    0 |
//     //          +---------+
//     //
//     //
//     // i = 1:
//     //
//     // dp[1][0] = dp[0][0] + dp[0][1]
//     //          = 1 + 1
//     //          = 2
//     //
//     // dp[1][1] = dp[0][0]
//     //          = 1
//     //
//     // Matrix:
//     //
//     //             0    1
//     //          +---------+
//     // i = 0    |  1    1 |
//     // i = 1    |  2    1 |
//     // i = 2    |  0    0 |
//     // i = 3    |  0    0 |
//     //          +---------+
//     //
//     //
//     // i = 2:
//     //
//     // dp[2][0] = dp[1][0] + dp[1][1]
//     //          = 2 + 1
//     //          = 3
//     //
//     // dp[2][1] = dp[1][0]
//     //          = 2
//     //
//     // Matrix:
//     //
//     //             0    1
//     //          +---------+
//     // i = 0    |  1    1 |
//     // i = 1    |  2    1 |
//     // i = 2    |  3    2 |
//     // i = 3    |  0    0 |
//     //          +---------+
//     //
//     //
//     // i = 3:
//     //
//     // dp[3][0] = dp[2][0] + dp[2][1]
//     //          = 3 + 2
//     //          = 5
//     //
//     // dp[3][1] = dp[2][0]
//     //          = 3
//     //
//     // FINAL MATRIX:
//     //
//     //             0    1
//     //          +---------+
//     // i = 0    |  1    1 |
//     // i = 1    |  2    1 |
//     // i = 2    |  3    2 |
//     // i = 3    |  5    3 |
//     //          +---------+
//   }

//   // ---------------------------------------------------------
//   // ANSWER
//   // ---------------------------------------------------------
//   //
//   // Original recursive call was:
//   //
//   // rec(n, 0)
//   //
//   // So tabulation equivalent is:
//   //
//   // dp[n][0]
//   //
//   // n = 3
//   //
//   // dp[3][0] = 5
//   //
//   // Valid strings:
//   //
//   // 000
//   // 001
//   // 010
//   // 100
//   // 101
//   //
//   // Total = 5
//   // ---------------------------------------------------------

//   cout << dp[n][0] << endl;

//   return 0;
// }

// #include <iostream>
// #include <vector>
// using namespace std;

// int main() {

//   int n = 3;

//   // =========================================================
//   // DP TABLE
//   // =========================================================
//   //
//   // dp[i][prev] = number of valid binary strings when
//   //                i positions are remaining and
//   //                prev tells us the previous bit.
//   //
//   // prev = 0 -> previous bit was 0
//   // prev = 1 -> previous bit was 1
//   //
//   // So:
//   //
//   //              prev
//   //              0   1
//   //          ------------
//   //       i=0 | ?   ?
//   //       i=1 | ?   ?
//   //       i=2 | ?   ?
//   //       i=3 | ?   ?
//   //
//   // =========================================================

//   vector<vector<int>> dp(n + 1, vector<int>(2, 0));

//   // =========================================================
//   // BASE CASE
//   // =========================================================
//   //
//   // Recursive code mein:
//   //
//   // if (n == 0)
//   //     return 1;
//   //
//   // Matlab:
//   // Agar 0 positions remaining hain,
//   // toh ek valid way hai -> kuch bhi nahi karna.
//   //
//   // Ye previous bit 0 ho ya 1,
//   // dono cases mein 1 way hai.
//   //
//   // Therefore:
//   //
//   // rec(0, 0) = 1
//   // rec(0, 1) = 1
//   //
//   // DP mein:
//   //
//   dp[0][0] = 1;
//   dp[0][1] = 1;

//   // =========================================================
//   // TABULATION
//   // =========================================================
//   //
//   // Recursive function:
//   //
//   // rec(n, prev)
//   //
//   // ko hum DP mein:
//   //
//   // dp[i][prev]
//   //
//   // ke through calculate kar rahe hain.
//   //
//   // i = 1 se n tak calculate karenge.
//   //
//   // =========================================================

//   for (int i = 1; i <= n; i++) {

//     // =====================================================
//     // CASE 1: PREVIOUS BIT = 0
//     // =====================================================
//     //
//     // Agar previous bit 0 hai,
//     // toh current position par:
//     //
//     // 0 bhi laga sakte hain
//     // 1 bhi laga sakte hain
//     //
//     // Recursive version:
//     //
//     // int put0 = rec(n - 1, 0);
//     //
//     // int put1 = 0;
//     //
//     // if (prev != 1) {
//     //     put1 = rec(n - 1, 1);
//     // }
//     //
//     // return put0 + put1;
//     //
//     // Yahan prev = 0 hai,
//     // isliye condition:
//     //
//     // prev != 1
//     //
//     // TRUE hogi.
//     //
//     // Therefore:
//     //
//     // put0 = dp[i - 1][0]
//     // put1 = dp[i - 1][1]
//     //
//     // Answer = put0 + put1
//     //
//     // =====================================================

//     dp[i][0] = dp[i - 1][0] + dp[i - 1][1];

//     // =====================================================
//     // CASE 2: PREVIOUS BIT = 1
//     // =====================================================
//     //
//     // Agar previous bit 1 hai,
//     // toh current position par 1 nahi laga sakte.
//     //
//     // Kyunki humein CONSECUTIVE 1s avoid karne hain.
//     //
//     // Recursive version:
//     //
//     // int put0 = rec(n - 1, 0);
//     //
//     // int put1 = 0;
//     //
//     // if (prev != 1) {
//     //     put1 = rec(n - 1, 1);
//     // }
//     //
//     // Yahan prev = 1 hai.
//     //
//     // Condition:
//     //
//     // prev != 1
//     //
//     // FALSE hogi.
//     //
//     // Isliye:
//     //
//     // put1 = 0
//     //
//     // Matlab current position par 1 daalne ke
//     // ZERO valid ways hain.
//     //
//     // Therefore:
//     //
//     // answer = put0 + put1
//     //        = put0 + 0
//     //
//     // put0 = dp[i - 1][0]
//     //
//     // So:
//     //
//     // dp[i][1] = dp[i - 1][0]
//     //
//     // IMPORTANT:
//     // YAHI RECURSIVE CODE KE
//     //
//     //      put1 = 0
//     //
//     // KA TABULATION VERSION HAI.
//     //
//     // Tabulation mein hum explicitly + 0 nahi likhte,
//     // kyunki:
//     //
//     // dp[i - 1][0] + 0
//     //
//     // simply:
//     //
//     // dp[i - 1][0]
//     //
//     // ban jaata hai.
//     //
//     // =====================================================

//     dp[i][1] = dp[i - 1][0];
//   }

//   // =========================================================
//   // PRINT DP TABLE
//   // =========================================================
//   //
//   // n = 3 ke liye table:
//   //
//   //              prev
//   //              0   1
//   //          ------------
//   //       i=0 | 1   1
//   //       i=1 | 2   1
//   //       i=2 | 3   2
//   //       i=3 | 5   3
//   //
//   // =========================================================

//   cout << "DP Table:\n";

//   for (int i = 0; i <= n; i++) {

//     cout << "i = " << i << " : ";

//     cout << dp[i][0] << " ";

//     cout << dp[i][1] << endl;
//   }

//   // =========================================================
//   // FINAL ANSWER
//   // =========================================================
//   //
//   // Starting mein previous bit 0 maan rahe hain.
//   //
//   // Isliye original recursive call thi:
//   //
//   // rec(n, 0)
//   //
//   // Tabulation mein uska equivalent:
//   //
//   // dp[n][0]
//   //
//   // =========================================================

//   cout << "\nAnswer = " << dp[n][0] << endl;

//   return 0;
// }

