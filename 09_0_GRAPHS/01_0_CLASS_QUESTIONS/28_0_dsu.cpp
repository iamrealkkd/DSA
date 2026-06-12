#include <iostream>
#include <vector>
using namespace std;

class DSU {
private:
    vector<int> parent;
    vector<int> rank;

public:
    DSU(int n) {
        parent.resize(n);
        rank.resize(n, 1);

        for (int i = 0; i < n; ++i)
            parent[i] = i;
    }

    int find(int node) {
        if (parent[node] == node)
            return node;

        return parent[node] = find(parent[node]);
    }

    void union_sets(int a, int b) {
        int leaderA = find(a);
        int leaderB = find(b);

        if (leaderA != leaderB) {
            if (rank[leaderA] < rank[leaderB]) {
                parent[leaderA] = leaderB;
                rank[leaderB] += rank[leaderA];
            } else {
                parent[leaderB] = leaderA;
                rank[leaderA] += rank[leaderB];
            }
        }
    }
};

int main() {
    DSU dsu(7);

    dsu.union_sets(0, 1);
    dsu.union_sets(1, 2);
    dsu.union_sets(3, 4);

    cout << "Leader of 0: " << dsu.find(0) << endl;
    cout << "Leader of 1: " << dsu.find(1) << endl;
    cout << "Leader of 2: " << dsu.find(2) << endl;
    cout << "Leader of 3: " << dsu.find(3) << endl;
    cout << "Leader of 4: " << dsu.find(4) << endl;

    return 0;
}