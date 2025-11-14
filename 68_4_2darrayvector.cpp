#include<bits/stdc++.h>
using namespace std;

int main(){
   vector<vector<int>> matrix={{1,2,3}, {5,8,6}, {9,6,4}};
   for(int i = 0; i<matrix.size(); i++){
    for(int j = 0; j<matrix[i].size(); j++){

        cout<<matrix[i][j]<< " ";

    }
    cout<<endl;

   }


   return 0;
}