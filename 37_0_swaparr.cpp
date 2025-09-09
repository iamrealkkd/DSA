#include<iostream>
using namespace std;
int swap(int arr[], int size){
    int i;
    int max=arr[0];
    int min=arr[0];
    for(i=0;i<size;i++){
        if(arr[i]>max){
        max=arr[i];
        
    }
  
    }
    for(i=0;i<size;i++){
        if(arr[i]<min){
        min=arr[i];
        
    }
  
    }
    cout<<"Max and Min values in the array are: "<<endl;
    cout<<max<<endl;\
    cout<<min<<endl;
    cout<<"Swapping the values..."<<endl;
    swap(max,min);
    cout<<max<<endl;
    cout<<min<<endl;
}
int main(){
    int size = 5;
    int arr[size] = {1, 2, 3, 4, 5};
    swap(arr, size);
    return 0;
}