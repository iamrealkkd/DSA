#include<iostream>
using namespace std;
int main(){
    int highest[5]={2,3,4,5,6};
    int max=highest[0];
    for(int i=0;i<5;i++){
        if(highest[i]>max){
        max=highest[i];
        
    }
  
    }
    cout<<max<<endl;
    return 0;
}