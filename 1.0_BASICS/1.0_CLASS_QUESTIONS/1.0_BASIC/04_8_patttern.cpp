#include<iostream>
using namespace std;
int main() {

int n = 3;
for(int i = n; i > 0; i--){
    for(int j = i; j > 0; j--){
    cout<<"*";
    }
    cout<<endl;
}
 for(int i = 0; i < n-1; i++){
     for(int j = 0; j < i+2; j++){
        cout<<"*";
     }
    cout<<endl;
 }
}
