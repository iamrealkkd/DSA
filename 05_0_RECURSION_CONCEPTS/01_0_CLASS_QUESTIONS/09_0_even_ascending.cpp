#include<bits/stdc++.h>
using namespace std;

    void print(int n, int N){
      if(n > N){
        return;
      }
      cout << n << " ";
      print(n+2, N);
      
    }
int main(){
    print(2, 12);
}