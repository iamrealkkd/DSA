#include<bits/stdc++.h>
using namespace std;

int diagSumOpti(int arr[3][3], int rows, int columns){

    int sum = 0;
    int i;
  for(i = 0; i < rows; i++){//rows can be n because here n is not present so
    sum += arr[i][rows - i - 1];
    if(i != rows - i - 1 ){
        sum += arr[i][rows - i - 1];
    }
  }
  return sum;
}
   

    
  
 


int main(){
    int arr[3][3] = {{1,2,3}, {5,2,6}, {8,9,5}};
    int rows = 3;
    int columns = 3;
    cout<<diagSumOpti(arr, rows, columns) << '\n';

    return 0;
}