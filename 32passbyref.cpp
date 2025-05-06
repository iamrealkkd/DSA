#include<iostream>
using namespace std;
void chngearr(int arr[], int size){
    int i;
    cout<<"In function before changing the array values: "<<endl;
    for(i=0;i<size;i++){
        arr[i]=5*arr[i];
    }
}








int main(){
    int arr[5]={1,2,3,4,5};
    chngearr(arr,5);
    cout<<"In main function after changing the array values: "<<endl;
    for(int i=0;i<5;i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;

}