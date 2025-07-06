#include <iostream>
using namespace std;
//function....
int uniq(int arr[],int size){
    int x=0;
    for(int i=1;i<size;i++){
       int unique=arr[x];
        if(unique!=arr[i]){
            cout<<unique<<" ";
            x++;
         }
    }

}

int main()
{
    // write your code here...
    int sz=6;
    int arr[sz]={3,2,1,4,5,2};
    uniq(arr,sz);
return 0;
}