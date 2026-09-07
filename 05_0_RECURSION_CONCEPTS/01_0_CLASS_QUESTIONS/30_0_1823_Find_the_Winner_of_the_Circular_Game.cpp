#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
  void solve(vector<int> &v, int k, int index, int &ans) {
    if (v.size() == 1) {
      ans = v[0];
      return;
    }

    index = (index + k) % v.size();
    v.erase(v.begin() + index);

    solve(v, k, index, ans);
  }

  int findTheWinner(int n, int k) {
    k = k - 1;

    vector<int> v;

    for (int i = 1; i <= n; i++) {
      v.push_back(i);
    }

    int index = 0;
    int ans = -1;

    solve(v, k, index, ans);

    return ans;
  }
};

int main() {
  int n, k;
  cin >> n >> k;

  Solution obj;
  cout << obj.findTheWinner(n, k);

  return 0;
}

// #include <bits/stdc++.h>

// /*
// C++ ki almost saari commonly used libraries ko include karta hai.

// Isse vector, iostream, etc. use kar sakte hain.
// */

// using namespace std;

// /*
// std:: baar-baar likhne ki zarurat nahi padegi.

// Example:
// std::vector ki jagah sirf vector likh sakte hain.
// */


// class Solution {

// /*
// Solution naam ki class bana rahe hain.

// LeetCode mein usually isi class ke andar solution likhna hota hai.
// */

// public:

// /*
// Class ke andar jo functions public hain,
// unhe class ke bahar se bhi access kiya ja sakta hai.
// */


//     void solve(vector<int>& v, int k, int index, int& ans) {

//     /*
//     solve() recursive function hai.

//     v     -> currently bache hue people ko store karta hai.
//     k     -> k-1 ki value hai, kyunki current person already count ho chuka hai.
//     index -> jahan se counting continue karni hai.
//     ans   -> final winner store karega.

//     & ka matlab reference hai.

//     Isliye v aur ans mein kiye changes
//     original variable mein bhi reflect honge.
//     */


//         if (v.size() == 1) {

//         /*
//         Base Case:

//         Agar vector mein sirf ek person bach gaya,
//         to wahi winner hai.
//         */


//             ans = v[0];

//             /*
//             Vector ka only remaining person
//             ans mein store kar do.
//             */


//             return;

//             /*
//             Recursion ko yahin stop kar do.
//             */
//         }


//         index = (index + k) % v.size();

//         /*
//         Ab calculate kar rahe hain ki
//         kaunsa person eliminate hoga.

//         index = current position
//         k     = kitne positions move karna hai

//         % v.size() circular movement ke liye use hota hai.


//         Example:

//         v = [1,2,3,4,5]
//         index = 0
//         k = 1

//         index = (0 + 1) % 5
//               = 1

//         index 1 par person 2 hai.

//         Isliye person 2 eliminate hoga.
//         */


//         v.erase(v.begin() + index);

//         /*
//         Calculated index wale person ko
//         vector se remove kar do.


//         v.begin()
//         -> vector ke first element ka iterator.


//         v.begin() + index
//         -> required index wale element par point karta hai.


//         Example:

//         v = [1,2,3,4,5]
//         index = 1


//         v.erase(v.begin() + 1)


//         Result:

//         [1,3,4,5]
//         */


//         solve(v, k, index, ans);

//         /*
//         Ab ek person remove ho chuka hai.

//         Remaining people ke saath
//         same process dobara perform karenge.

//         Ye recursive call hai.


//         SAME index pass kar rahe hain because
//         deletion ke baad next person automatically
//         isi index par aa jata hai.
//         */

//     }



//     int findTheWinner(int n, int k) {

//     /*
//     Ye main function hai jo winner find karega.

//     n -> total number of people
//     k -> har k-th person eliminate hoga.
//     */


//         k = k - 1;

//         /*
//         Current person ko counting mein
//         already count kar liya gaya hai.


//         Example:

//         k = 2

//         Current person -> count 1
//         Next person   -> count 2 -> eliminate


//         Current index se next eliminated person tak
//         sirf k-1 positions move karna hai.


//         Therefore:

//         k = 2 -> k becomes 1
//         k = 3 -> k becomes 2
//         */


//         vector<int> v;

//         /*
//         Empty vector create kar rahe hain.

//         Isme saare people store honge.
//         */


//         for (int i = 1; i <= n; i++) {

//         /*
//         1 se n tak loop chalega.


//         Example n = 5:

//         i = 1
//         i = 2
//         i = 3
//         i = 4
//         i = 5
//         */


//             v.push_back(i);

//             /*
//             Har person ko vector ke end mein
//             add kar rahe hain.


//             Step by step:

//             i = 1 -> [1]

//             i = 2 -> [1,2]

//             i = 3 -> [1,2,3]

//             i = 4 -> [1,2,3,4]

//             i = 5 -> [1,2,3,4,5]
//             */

//         }



//         int index = 0;

//         /*
//         Counting person 1 se start karenge.


//         Vector 0-based indexing use karta hai:


//         index 0 -> person 1
//         index 1 -> person 2
//         index 2 -> person 3
//         index 3 -> person 4
//         index 4 -> person 5
//         */



//         int ans = -1;

//         /*
//         Initially winner pata nahi hai.

//         Isliye ans ko -1 se initialize kar rahe hain.
//         */



//         solve(v, k, index, ans);

//         /*
//         Recursive process start kar rahe hain.

//         solve() repeatedly people ko remove karega
//         jab tak sirf ek person nahi bach jata.
//         */



//         return ans;

//         /*
//         Last remaining person ko return kar do.
//         */

//     }

// };



// // int main() {

// //     /*
// //     Program execution yahan se start hota hai.
// //     */



// //     int n, k;

// //     /*
// //     n = number of people
// //     k = elimination counting
// //     */



// //     cin >> n >> k;

// //     /*
// //     User se n aur k input le rahe hain.


// //     Example input:

// //     5 2
// //     */



// //     Solution obj;

// //     /*
// //     Solution class ka object create kar rahe hain.
// //     */



// //     cout << obj.findTheWinner(n, k);

// //     /*
// //     findTheWinner() function ko call kar rahe hain.

// //     Function winner return karega.

// //     cout us winner ko print karega.
// //     */



// //     return 0;

// //     /*
// //     Program successfully terminate ho gaya.
// //     */

// // }