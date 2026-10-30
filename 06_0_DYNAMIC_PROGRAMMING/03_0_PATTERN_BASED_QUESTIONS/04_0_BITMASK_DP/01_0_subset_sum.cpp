#include<bits/stdc++.h>
using namespace std;
int main(){
    vector<int> k = {1, 2, 3};
    int n = k.size();
    int p = 1 << n;
    vector<int>s(p);
    for(int mask = 0; mask < p; mask++){
        for(int bit = 0; bit < n; bit++){
            if(mask & (1 << bit)) s[mask] += k[bit];
        }
    }
    for(int i : s)cout << i << " ";
}