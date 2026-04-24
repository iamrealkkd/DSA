#include<bits/stdc++.h>
using namespace std;

void print(int n, int N){
    if(n == N){
        cout << n << " ";
        return;
    }
    cout << n << " ";
    print(n+1, N);
}
int main(){
    int N = 8;
    print(1, N);
}