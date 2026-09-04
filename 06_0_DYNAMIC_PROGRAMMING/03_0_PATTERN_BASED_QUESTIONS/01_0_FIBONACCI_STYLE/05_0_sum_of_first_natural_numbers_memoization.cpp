#include<bits/stdc++.h>
using namespace std;
int sum(int n, vector<int>&dp){
    if(n == 0)return 0;
    if(dp[n] != -1) return dp[n];
    return dp[n] = n + sum(n - 1, dp);
}

int main(){
    int n;
    cin >> n;
    vector<int>dp(n + 1, -1);
    cout << sum(n, dp);
    return 0;
}