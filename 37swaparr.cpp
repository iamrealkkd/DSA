#include<iostream>
using namespace std;
int main(){
    int i;
    int arr[5]={2,3,4,5,6};
    int max=arr[0];
    int min=arr[0];
    for(i=0;i<5;i++){
        if(arr[i]>max){
        max=arr[i];
        
    }
  
    }
    for(i=0;i<5;i++){
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
    return 0;
}