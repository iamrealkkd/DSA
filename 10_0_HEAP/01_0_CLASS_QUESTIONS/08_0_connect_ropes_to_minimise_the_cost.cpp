#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int connectRopes(vector<int>& ropes)
{
    priority_queue<
        int,
        vector<int>,
        greater<int>
    > minh;

    for(int x : ropes)
    {
        minh.push(x);
    }

    int cost = 0;

    while(minh.size() >= 2)
    {
        int first = minh.top();
        minh.pop();

        int second = minh.top();
        minh.pop();

        cost += first + second;

        minh.push(first + second);
    }

    return cost;
}

int main()
{
    vector<int> ropes = {4, 3, 2, 6};
    cout << connectRopes(ropes);

    return 0;
}