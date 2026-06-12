#include<iostream>
#include<map>
#include<unordered_map>
using namespace std;

int main(){
    //creation
    //map<string, int>m;
    unordered_map<string, int>m;

    //insertion
    //1
    pair<string, int> p = make_pair("krishna", 1);
    m.insert(p);

    //2
    pair<string, int> p2("nikku", 2);
    m.insert(p2);

    //3
    m["rathore"] = 4;

    //what will happen
    //single entry for each key
    m["rathore"] = 5;//it will update the value from 4 to 5

    //searching
    cout <<  m["rathore"] << endl;//Output is 5
    cout <<  m.at("krishna") << endl;//Output is 1
    // cout <<  m.at("kkd") << endl; Output is key not found as it not existed
    cout <<  m["kkd"] << endl;//Output is 0, iskey coreesponding ek value bn jayegi 0
    cout <<  m.at("kkd") << endl;//ab dono 0 de diye pehle 0 nahi de rha the, because ab value 0 ban chuki hai

    //size
    cout << m.size() << endl;// o/p is 4
    
    //to check presence
    cout << m.count("bro") << endl;// o/p is 0(if it is not present in map)
    cout << m.count("krishna") << endl;// o/p is 1(if it is present in map not matter it's frequency)

    //erase
    m.erase("krishna");
    cout << m.size() << endl;//o/p is 3

    //traversing
    for(auto i:m){
        cout << i.first << " " << i.second << endl;
    }
    
    //traversing by iterator
    unordered_map<string, int> :: iterator it = m.begin();

    while(it != m.end()){
        cout << it -> first << " " << it -> second << endl;
        it++;
    }//isme sab unorder print hoga, if only map hota to order mai print hota


    return 0;
}