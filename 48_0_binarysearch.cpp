#include<iostream>
#include<vector>
using namespace std;

int binarySearch(vector<int>arr, int target){
    int st = 0, end = arr.size()-1;

    while(st <= end){
        int mid = st+(end-st)/2;

        if(target > arr[mid]){
            st = mid+1;
        }
        else if(target < arr[mid]){
            end = mid-1;
        }
        else{
            return mid;
        }


    }

    return -1;

}

int main(){
    vector<int> arr = {10,5,9,6};
    int target = 9;

    cout<<binarySearch(arr, target);

    
}