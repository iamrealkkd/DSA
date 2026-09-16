#include <iostream>
#include <unordered_set>
#include <vector>
using namespace std;
void permute(string ip, string op, vector<string> &v) {
  if (ip.size() == 0) {
    v.push_back(op);
    return;
  }

  unordered_set<char>mp;
  for(int i = 0; i < ip.size(); i++){
    if(mp.find(ip[i]) == mp.end()){
        mp.insert(ip[i]);
        string newIp = ip.substr(0, i) + ip.substr(i + 1);
        string newOp = op + ip[i];
        permute(newIp, newOp, v);
    }
  }
}
int main() {
  string s = "ABC";
  vector<string> v;
  permute(s, "", v);
  for (string x : v) {
    cout << x << endl;
  }

  return 0;
}