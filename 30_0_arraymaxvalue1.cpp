#include<iostream>
using namespace std;
int main(){
    int i;
    int highest[5]={2,3,4,5,6};
    int max=highest[0];
    for(i=0;i<5;i++){
        if(highest[i]>max){
        max=highest[i];
        
    }
  
    }
    cout<<max<<endl;\
    cout<<highest[i]<<endl;
    return 0;
}