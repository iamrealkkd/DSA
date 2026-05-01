#include <iostream>
#include <map>
using namespace std;

int main() {

  
    map<string, int> store;

   
    store["Belt"] = 800;
    store["Purse"] = 1500;
    store["Sunglass"] = 1200;

    
    cout << "Store Items and Prices:\n";

    for(auto item : store){
        cout << item.first << " : " << item.second << endl;
    }

    
    cout << "\nPrice of Belt = " << store["Belt"] << endl;

    return 0;
}