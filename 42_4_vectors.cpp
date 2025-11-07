//iterators in vector
#include<bits/stdc++.h>
using namespace std;
int  main(){
 vector<int> jin = {1, 2, 5, 6, 7};
 cout<<"jin.end:"<<*(jin.end())<<endl;//point to the valueoflastindex+1
 vector<int>::iterator it;

 for(it = jin.begin(); it !=  jin.end(); it++){
    cout<< *(it) <<" ";
 }

 cout<<endl;

  vector<int>::reverse_iterator in;

 for(auto in = jin.rbegin(); in !=  jin.rend(); in++){
    cout<< *(in) <<" ";
 }

 return 0;

}