#include<bits/stdc++.h>
using namespace std;

int main(){

    vector<int> hero;

    // inserting elements
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

    // erase first element
    hero.erase(hero.begin()); 

    // erase element at index 2
    hero.erase(hero.begin() + 2); 

    // erase elements in range
    hero.erase(hero.begin() + 3, hero.begin() + 7); 

    // insert element at index 2
    hero.insert(hero.begin() + 2, 45);

    // hero.clear(); // clears elements but capacity remains same

    // printing vector
    for(int val : hero){
        cout << val << " ";
    }

    cout << "\n";

    // check if vector is empty
    cout << "isEmpty " << hero.empty();

}