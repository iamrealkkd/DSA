#include<bits/stdc++.h>
using namespace std;

int maxRowSum(int arr[3][3], int rows, int columns){
    int maxRowSum = INT_MIN;
  for(int i = 0; i < rows; i++){
    int rowSumI = 0;
    for(int j = 0; j < columns; j++){
      rowSumI += arr[i][j];
        
    }
    maxRowSum = max(maxRowSum, rowSumI);
  }
  return maxRowSum;
 
}

int main(){
    int arr[3][3] = {{1,2,3}, {5,2,6}, {8,9,5}};
    int rows = 3;
    int columns = 3;
    cout<<maxRowSum(arr, rows, columns) << '\n';

    return 0;
}