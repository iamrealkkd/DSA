#include<bits/stdc++.h>
using namespace std;

int diagSumBrute(int arr[3][3], int rows, int columns){

    int sum = 0;
  for(int i = 0; i < rows; i++){
    for(int j = 0; j < columns; j++){
      if(i == j){
        sum += arr[i][j];//Primary Diagonal
      }else if(j == rows - i - 1){

        sum += arr[i][j];

        }
      }
        
    }
    return sum;
  }
  
 


int main(){
    int arr[3][3] = {{1,2,3}, {5,2,6}, {8,9,5}};
    int rows = 3;
    int columns = 3;
    cout<<diagSumBrute(arr, rows, columns) << '\n';

    return 0;
}