#include<iostream>
#include<climits>
using namespace std;

int main(){
    int i;
    int smallest[5]={2,3,4,5,6};
    int minval=INT_MAX;
    for(i=0;i<5;i++){
        if(smallest[i]<minval){
        minval=smallest[i];
        
    }
  
    }
    cout<<minval<<endl;
    cout<<smallest[i]<<endl;
    return 0;
}