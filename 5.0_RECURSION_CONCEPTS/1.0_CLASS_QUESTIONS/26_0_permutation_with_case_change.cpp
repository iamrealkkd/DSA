#include <bits/stdc++.h>
using namespace std;

void solve(string ip, string op)
{
    // base condition
    if(ip.length() == 0)
    {
        cout << op << endl;
        return;
    }

    // case 1: uppercase
    string op1 = op;
    // case 2: lowercase
    string op2 = op;
    op1.push_back(tolower(ip[0]));
    op2.push_back(toupper(ip[0]));
    

    // input ka first character remove
    ip.erase(ip.begin() + 0);

    // recursive calls
    solve(ip, op1);
    solve(ip, op2);
}

int main()
{
    string ip = "AB";
    string op = "";

    solve(ip, op);

    return 0;
}