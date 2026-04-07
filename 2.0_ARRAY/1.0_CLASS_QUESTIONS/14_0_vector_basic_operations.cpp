#include<bits/stdc++.h>
using namespace std;

int main(){

    vector<int> kkd;

    // inserting elements
    kkd.push_back(9);
    kkd.push_back(2);
    kkd.push_back(7);
    kkd.push_back(5);
    kkd.push_back(3);
    kkd.push_back(8);

    // constructs element directly inside vector
    kkd.emplace_back(4);

    // removes last element
    kkd.pop_back();

    cout << "Vectors are: ";

    // printing vector elements
    for(int val : kkd){
        cout << val << " ";
    }

    cout << '\n';

    cout << "Size of vector is: " << kkd.size() << '\n';
    cout << "Capacity of vector is: " << kkd.capacity() << '\n';
    cout << "Value at index 0: " << kkd[0] << '\n';
    cout << "Value at index 1: " << kkd.at(1) << '\n';
    cout << "Value at front: " << kkd.front() << '\n';
    cout << "Value at back: " << kkd.back() << '\n';

}