#include<bits/stdc++.h>
using namespace std;
int main(){

    map<string, int>k;

    k["tv"] = 100;
    k["purse"] = 100;
    k["belt"] = 45;
    k.insert({"glasses", 80});

    for(auto p: k){
        cout << p.first << " " << p.second << endl;//output will be sorted order
    }

    return 0;

}