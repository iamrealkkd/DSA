#include<iostream>
#include<vector>
using namespace std;
int main(){
    int ans=0;
    vector<int> num={4,1,2,1,2};
    for (int i :num){
        ans^=i;
    }
    cout<<ans<<endl;
    
}