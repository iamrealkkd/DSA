#include<iostream>
using namespace std;

void check(int x){

    if(x & 1) cout << "Odd" << endl;
    else  cout << "Even" << endl;  
}

int main(){
     check(4);
     check(5);

}