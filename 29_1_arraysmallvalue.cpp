#include<iostream>
#include<climits>
using namespace std;
int main(){
    int smallest=INT_MAX;
    int num[5];
    cout<<"Enter 5 numbers: "<<endl;
    for(int i=0;i<5;i++){
        cin>>num[i];
    }
    for(int i=0;i<5;i++){
        if(num[i]<smallest){
        smallest=num[i];
        
    }
  
    }
    cout<<"The smallest num is"<<" "<<smallest<<endl;
    return 0;
}