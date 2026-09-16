#include <iostream>
#include <vector>
#include <unordered_set>
using namespace std;

void permute(string ip, string op, vector<string> &v) {

    // Base Case
    if(ip.size() == 0) {
        v.push_back(op);
        return;
    }

    unordered_set<char> mp;

    for(int i = 0; i < ip.size(); i++) {

        // Skip duplicates
        if(mp.find(ip[i]) == mp.end()) {

            mp.insert(ip[i]);
            string newIP = ip.substr(0, i) + ip.substr(i + 1);
            string newOP = op + ip[i];

            permute(newIP, newOP, v);
        }
    }
}

int main() {

    string s = "ABC";

    vector<string> v;

    permute(s, "", v);

    for(string x : v) {
        cout << x << endl;
    }

    return 0;
}

// #include <iostream>
// #include <unordered_set>
// #include <vector>
// using namespace std;

// void permute(string ip, string op, vector<string> &v) {
//   // ============================================================
//   // FIRST CALL
//   // permute("ABC", "")
//   //
//   // ip = "ABC"
//   // op = ""
//   //
//   // ip empty nahi hai, so loop chalega.
//   // ============================================================

//   if (ip.size() == 0) {
//     // Agar input empty ho gaya,
//     // iska matlab ek complete permutation ban gaya.
//     v.push_back(op);
//     return;
//   }

//   // Ye set CURRENT LEVEL par use hue characters ko store karega.
//   // ABC mein koi duplicate nahi hai,
//   // isliye koi character skip nahi hoga.
//   unordered_set<char> mp;

//   for (int i = 0; i < ip.size(); i++) {
//     // ========================================================
//     // FIRST CALL: ip = "ABC", op = ""
//     // ========================================================

//     // ---------------- i = 0 ----------------
//     // ip[i] = 'A'
//     //
//     // A mp mein nahi hai, so A ko insert karo.
//     //
//     // mp = {A}
//     //
//     // newIP = "BC"
//     // newOP = "A"
//     //
//     // Ab recursion:
//     // permute("BC", "A")
//     // ========================================================

//     if (mp.find(ip[i]) == mp.end()) {
//       mp.insert(ip[i]);

//       string newIP = ip.substr(0, i) + ip.substr(i + 1);
//       string newOP = op + ip[i];

//       // ====================================================
//       // SECOND CALL
//       // permute("BC", "A")
//       //
//       // ip = "BC"
//       // op = "A"
//       // mp = {}
//       //
//       // i = 0 -> choose B
//       //
//       // newIP = "C"
//       // newOP = "AB"
//       //
//       // permute("C", "AB")
//       // ====================================================

//       permute(newIP, newOP, v);
//     }
//   }
// }

// /*
// ====================================================================
//                     COMPLETE DRY RUN FOR "ABC"
// ====================================================================


// CALL 1:
// permute("ABC", "")

// ip = "ABC"
// op = ""

//                     ""
//                  /   |   \
//                 A    B    C


// ------------------------------------------------------------
// i = 0
// ------------------------------------------------------------

// Choose A

// newOP = "" + "A"
//       = "A"

// newIP = "BC"

// CALL:
// permute("BC", "A")


//                     A
//                   /   \
//                  AB   AC


// ------------------------------------------------------------
// CALL 2:
// permute("BC", "A")
// ------------------------------------------------------------

// Choose B:

// newOP = "A" + "B"
//       = "AB"

// newIP = "C"

// CALL:
// permute("C", "AB")


//                     A
//                     |
//                    AB


// ------------------------------------------------------------
// CALL 3:
// permute("C", "AB")
// ------------------------------------------------------------

// Choose C:

// newOP = "AB" + "C"
//       = "ABC"

// newIP = ""

// CALL:
// permute("", "ABC")


// ------------------------------------------------------------
// CALL 4:
// permute("", "ABC")
// ------------------------------------------------------------

// ip.size() == 0

// BASE CASE!

// v.push_back("ABC")

// So:

// v = {
//     "ABC"
// }


// Return
// ------------------------------------------------------------


// Ab CALL 3 mein wapas aayenge.

// CALL 3:
// permute("C", "AB")

// "C" mein sirf ek character tha,
// isliye ye call complete ho gaya.

// Return.


// ------------------------------------------------------------
// Ab CALL 2 mein wapas
// permute("BC", "A")
// ------------------------------------------------------------

// Ab loop ka next iteration:

// i = 1

// Choose C

// newOP = "A" + "C"
//       = "AC"

// newIP = "B"

// CALL:
// permute("B", "AC")


// ------------------------------------------------------------
// CALL:
// permute("B", "AC")
// ------------------------------------------------------------

// Choose B

// newOP = "AC" + "B"
//       = "ACB"

// newIP = ""

// CALL:
// permute("", "ACB")


// BASE CASE!

// v.push_back("ACB")


// Ab:

// v = {
//     "ABC",
//     "ACB"
// }


// Return.


// ====================================================================
// AB "A" wala pura branch complete.
// ====================================================================



// CALL 1:
// permute("ABC", "")

// Ab loop ka next iteration:

// i = 1

// Choose B

// newOP = "" + "B"
//       = "B"

// newIP = "AC"

// CALL:
// permute("AC", "B")


//                     ""
//                   /   |   \
//                  A    B    C
//                       |
//                      BA


// ------------------------------------------------------------
// CALL:
// permute("AC", "B")
// ------------------------------------------------------------

// i = 0

// Choose A

// newOP = "B" + "A"
//       = "BA"

// newIP = "C"

// CALL:
// permute("C", "BA")


// Choose C:

// newOP = "BA" + "C"
//       = "BAC"

// newIP = ""

// BASE CASE!

// v.push_back("BAC")


// v = {
//     "ABC",
//     "ACB",
//     "BAC"
// }


// ------------------------------------------------------------
// Back to permute("AC", "B")
// ------------------------------------------------------------

// i = 1

// Choose C

// newOP = "B" + "C"
//       = "BC"

// newIP = "A"

// CALL:
// permute("A", "BC")


// Choose A:

// newOP = "BC" + "A"
//       = "BCA"

// newIP = ""

// BASE CASE!

// v.push_back("BCA")


// v = {
//     "ABC",
//     "ACB",
//     "BAC",
//     "BCA"
// }



// ====================================================================
// AB "B" wala pura branch complete.
// ====================================================================



// CALL 1:
// permute("ABC", "")

// Ab loop ka next iteration:

// i = 2

// Choose C

// newOP = "" + "C"
//       = "C"

// newIP = "AB"

// CALL:
// permute("AB", "C")


//                     ""
//                   /   |   \
//                  A    B    C
//                       |     |
//                     ...    CA


// ------------------------------------------------------------
// CALL:
// permute("AB", "C")
// ------------------------------------------------------------

// i = 0

// Choose A

// newOP = "C" + "A"
//       = "CA"

// newIP = "B"

// CALL:
// permute("B", "CA")


// Choose B:

// newOP = "CA" + "B"
//       = "CAB"

// newIP = ""

// BASE CASE!

// v.push_back("CAB")


// v = {
//     "ABC",
//     "ACB",
//     "BAC",
//     "BCA",
//     "CAB"
// }


// ------------------------------------------------------------
// Back to permute("AB", "C")
// ------------------------------------------------------------

// i = 1

// Choose B

// newOP = "C" + "B"
//       = "CB"

// newIP = "A"

// CALL:
// permute("A", "CB")


// Choose A:

// newOP = "CB" + "A"
//       = "CBA"

// newIP = ""

// BASE CASE!

// v.push_back("CBA")


// v = {
//     "ABC",
//     "ACB",
//     "BAC",
//     "BCA",
//     "CAB",
//     "CBA"
// }


// ====================================================================
// AB SAARE 6 PERMUTATIONS MIL GAYE.
// ====================================================================


// FINAL VECTOR:

// v = {
//     "ABC",
//     "ACB",
//     "BAC",
//     "BCA",
//     "CAB",
//     "CBA"
// }


// FINAL OUTPUT:

// ABC
// ACB
// BAC
// BCA
// CAB
// CBA

// ====================================================================
// IMPORTANT:

// newOP = op + ip[i]

//     Character ko OUTPUT mein add karta hai.


// newIP = ip.substr(0, i) + ip.substr(i + 1)

//     Jo character choose kiya,
//     usko INPUT se remove karta hai.


// Example:

// ip = "ABC"
// i = 1

// ip[i] = 'B'

// newOP = "" + "B"
//       = "B"

// newIP = "A" + "C"
//       = "AC"


// So:

// OLD:
// ip = "ABC"
// op = ""

//        choose B

// NEW:
// ip = "AC"
// op = "B"


// unordered_set<char> mp

//     Ek hi recursion level par same character ko
//     dobara choose hone se rokta hai.

// ====================================================================
// */

// int main() {
//   string s = "ABC";

//   vector<string> v;

//   // Starting call
//   permute(s, "", v);

//   // Saare permutations print karo
//   for (string x : v) {
//     cout << x << endl;
//   }

//   return 0;
// }