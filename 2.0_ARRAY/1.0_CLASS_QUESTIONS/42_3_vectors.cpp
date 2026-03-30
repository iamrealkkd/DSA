#include<bits/stdc++.h>
using namespace std;
int  main(){
     
    vector<int> hero;

    hero.push_back(5);
    hero.push_back(9);
    hero.push_back(4);
    hero.push_back(2);
    hero.push_back(1);
    hero.push_back(10);
    hero.push_back(15);
    hero.push_back(16);
    hero.push_back(19);
    hero.push_back(11);
    hero.erase(hero.begin());//value at starting position, removed 5
    hero.erase(hero.begin()+2);//particular index, removed 2
    hero.erase(hero.begin()+3, hero.begin()+7);//particular range, removed 2
    hero.insert(hero.begin()+2, 45);
    // hero.clear();clear the vector size not capacity, it will remain same

    for(int val:hero){
        cout<< val << " ";
    }

    cout<<"\n";
    cout<<"isEmpty"<<" "<<hero.empty();

 }