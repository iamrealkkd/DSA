#include<iostream>
using namespace std;

void solve(int s, int d, int h, int n){
    if(n == 1){
        cout << "Moving Plate " << n << " from " << s << " to " << d << endl;
        return;
    }

    solve(s, h, d, n-1);
    cout << "Moving Plate " << n << " from " << s << " to " << d << endl;
    solve(h, d, s, n-1);
}

int main(){
    int n;
    cout << "Enter number of plates: ";
    cin >> n;

    int s = 1, h = 2, d = 3;
    solve(s, d, h, n);
}