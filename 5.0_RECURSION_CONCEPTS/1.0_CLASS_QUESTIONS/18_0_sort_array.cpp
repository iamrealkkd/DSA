#include <iostream>
#include <vector>
using namespace std;

// Insert temp into its correct position in sorted vector v
void insert(vector<int>& v, int temp) {
    // Base case: if vector is empty OR last element <= temp
    if (v.size() == 0 || v[v.size() - 1] <= temp) {
        v.push_back(temp);
        return;
    }

    // Extract last element
    int val = v[v.size() - 1];
    v.pop_back();

    // Recurse
    insert(v, temp);

    // Put val back
    v.push_back(val);
}

// Sort the vector using recursion
void sort(vector<int>& v) {
    // Base case: empty vector
    if (v.size() == 0) {
        return;
    }

    // Extract last element
    int temp = v[v.size() - 1];
    v.pop_back();

    // Recursively sort remaining
    sort(v);

    // Insert temp into correct position
    insert(v, temp);
}

int main() {
    vector<int> v = {3, 1, 2};  // example input

    sort(v);

    for (int x : v) {
        cout << x << " ";
    }
    cout << endl;

    return 0;
}
/*
RECURSIVE SORT OF VECTOR
Input: v = [3,1,2]

Main Idea:
1) Remove last element
2) Recursively sort remaining vector
3) Insert removed element at correct position

----------------------------------------
START

v = [3,1,2]

sort(v)

----------------------------------------
CALL 1

sort([3,1,2])

temp = v[v.size()-1]
temp = 2

v.pop_back()

v = [3,1]

Now call recursion

sort([3,1])

----------------------------------------
CALL 2

sort([3,1])

temp = 1

v.pop_back()

v = [3]

Now recursion

sort([3])

----------------------------------------
CALL 3

sort([3])

temp = 3

v.pop_back()

v = []

Now recursion

sort([])

----------------------------------------
CALL 4 (BASE CASE)

sort([])

v.size() == 0
return

Now recursion stack starts returning

----------------------------------------
INSERT PHASE

insert([],3)

Condition:
v.size()==0

Push 3

v = [3]

----------------------------------------
INSERT 1

insert([3],1)

Check condition

v[v.size()-1] <= temp

3 <= 1  ❌

Store last element

val = 3

Remove it

v.pop_back()

v = []

Recursive call

insert([],1)

Condition true

push 1

v = [1]

Now restore removed element

v.push_back(val)

v = [1,3]

----------------------------------------
INSERT 2

insert([1,3],2)

Check condition

3 <= 2 ❌

Store last element

val = 3

Remove it

v.pop_back()

v = [1]

Recursive call

insert([1],2)

Check condition

1 <= 2 ✅

Push 2

v = [1,2]

Now restore removed element

v.push_back(3)

v = [1,2,3]

----------------------------------------
FINAL VECTOR

v = [1,2,3]

OUTPUT

1 2 3

----------------------------------------
RECURSION TREE

sort(3,1,2)
      |
sort(3,1)
      |
sort(3)
      |
sort()
      |
insert 3
insert 1
insert 2

----------------------------------------
MEMORY TRICK

REMOVE → SORT → INSERT

Take last element out
Sort remaining array
Insert element back at correct position

----------------------------------------
TIME COMPLEXITY

O(n^2)

----------------------------------------
SPACE COMPLEXITY

O(n) recursion stack


sort(3,1,2)
   |
sort(3,1)
   |
sort(3)
   |
sort()
   |
insert 3
insert 1
insert 2
*/