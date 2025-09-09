#include<iostream>
using namespace std;
int main(){
    int i;
    int arr[5]={1,2,3,4,5};
    int size=5;
    int s=1;
    for(int i=0; i<size; i++){
        s*=arr[i];
    }
    cout<<"Product of array is: "<<s<<endl;
    return 0;
}