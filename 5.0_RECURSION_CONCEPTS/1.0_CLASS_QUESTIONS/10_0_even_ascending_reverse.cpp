#include<bits/stdc++.h>
using namespace std;

    void print(int n){
      if(n == 2){
        cout << n << " ";
        return;
      }
      print(n-2);
      cout << n << " ";
    }
int main(){
    int N = 13;
    if(N % 2 == 1)N--;
    print(N);
}