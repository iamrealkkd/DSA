#include<bits/stdc++.h>
using namespace std;

bool linearSearch(int arr[3][3], int rows, int columns, int key){
  for(int i = 0; i < rows; i++){
    for(int j = 0; j < columns; j++){
        if(arr[i][j] == key)
        return true;
    }
  }
  return false;
}

int main(){
    int arr[3][3] = {{1,2,3}, {5,2,6}, {8,9,5}};
    int rows = 3;
    int columns = 3;
    cout<<linearSearch(arr, rows, columns, 8) << '\n';

    return 0;
}