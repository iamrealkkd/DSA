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
    hero.erase(hero.begin());//value at starting position 
    hero.erase(hero.begin()+2);//particular index
    hero.erase(hero.begin()+2, hero.begin()+5);//particular range

    for(int val:hero){
        cout<< val << " ";
    }

 }