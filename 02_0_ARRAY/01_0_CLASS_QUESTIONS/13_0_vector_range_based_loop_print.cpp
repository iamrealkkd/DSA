#include<iostream>
#include<vector>
using namespace std;

int main(){

    vector<float> num = {1.2,2.6,3.5,4.8,5.9};

    // range-based loop to print vector elements
    for(float j : num){
        cout << j << endl;
    }

    return 0;
}