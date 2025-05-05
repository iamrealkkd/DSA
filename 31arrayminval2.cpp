#include<iostream>
#include<climits>
using namespace std;

int main(){
    int smallest[5]={2,3,4,5,6};
    int max=INT_MAX;
    for(int i=0;i<5;i++){
        if(smallest[i]<max){
        max=smallest[i];
        
    }
  
    }
    cout<<max<<endl;
    return 0;
}