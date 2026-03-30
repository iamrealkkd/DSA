#include<bits/stdc++.h>
using namespace std;
int main(){
    cout << "Normal Vector:" " ";
    vector<int> reel = {1, 2, 3, 5};
    for(int val: reel){
        cout<< val<< " ";
    }
    cout << '\n';
    cout << "Same Value Vector:" " ";
    vector<int> same(5, -9);//using in dynamic programming
    for(int val: same){
        cout<< val<< " ";
    }
    cout << '\n';
    cout << "Initialize Vector 2 with Values of 1:" " ";
    vector<int> v1 = {1, 2, 3, 5};
    vector<int> v2(v1);
    for(int val : v2){

        cout<< val << " ";
    }
}