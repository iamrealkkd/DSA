#include<iostream>
using namespace std;
int main(){
    int smallest[5]={2,3,4,5,6};
    int min=smallest[0];
    for(int i=0;i<5;i++){
        if(smallest[i]<min){
        min=smallest[i];
        
    }
  
    }
    cout<<min<<endl;
    return 0;
}