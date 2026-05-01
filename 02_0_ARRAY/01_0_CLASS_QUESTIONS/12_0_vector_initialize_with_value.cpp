#include<iostream>
#include<vector>
using namespace std;

int main(){

    vector<int> num(4,5);  // vector of size 4 with all values = 5

    cout << num[0] << endl;
    cout << num[1] << endl;
    cout << num[2] << endl;
    cout << num[3] << endl;

    return 0;
}