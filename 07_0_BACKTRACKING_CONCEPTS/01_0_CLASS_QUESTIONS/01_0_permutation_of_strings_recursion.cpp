#include <iostream>
#include <vector>
#include <unordered_set>
using namespace std;

void permute(string ip, string op, vector<string> &v) {

    // Base Case
    if(ip.size() == 0) {
        v.push_back(op);
        return;
    }

    unordered_set<char> mp;

    for(int i = 0; i < ip.size(); i++) {

        // Skip duplicates
        if(mp.find(ip[i]) == mp.end()) {

            mp.insert(ip[i]);

            string newIP = ip.substr(0, i) + ip.substr(i + 1);
            string newOP = op + ip[i];

            permute(newIP, newOP, v);
        }
    }
}

int main() {

    string s = "ABC";

    vector<string> v;

    permute(s, "", v);

    for(string x : v) {
        cout << x << endl;
    }

    return 0;
}