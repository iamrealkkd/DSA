#include<iostream>
using namespace std;
int main(){
    int n;
    int s = 0;
    cout << "Enter a number: ";
    cin >> n;
    for(int i = 1; i <= n; i++) 
    {
        if(i%2==0){
            s=s+i;
        }

    }
    cout << "Sum of even numbers from 1 to " << n << " is: " << s << endl;
}