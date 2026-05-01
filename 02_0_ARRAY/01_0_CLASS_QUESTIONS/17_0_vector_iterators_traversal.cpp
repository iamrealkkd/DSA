#include<bits/stdc++.h>
using namespace std;

int main(){

    vector<int> jin = {1, 2, 5, 6, 7};

    // NOTE: end() points to position after the last element
    // dereferencing it is undefined, but shown here for concept
    cout << "jin.end: " << *(jin.end()) << endl;

    vector<int>::iterator it;

    // forward traversal using iterator
    for(it = jin.begin(); it != jin.end(); it++){
        cout << *(it) << " ";
    }

    cout << endl;

    // reverse traversal using reverse iterator
    for(auto in = jin.rbegin(); in != jin.rend(); in++){
        cout << *(in) << " ";
    }

    return 0;
}