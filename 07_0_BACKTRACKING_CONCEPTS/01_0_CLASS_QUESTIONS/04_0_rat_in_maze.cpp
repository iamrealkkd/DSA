#include <bits/stdc++.h>
using namespace std;

struct Choice {
    char dname;
    int dx, dy;
};

bool isSolved(int x, int y, int n) {
    return x == n - 1 && y == n - 1;
}

bool isValid(int x, int y, int n, const vector<vector<int>> &arr) {
    return x >= 0 && x < n && y >= 0 && y < n && arr[x][y] == 1;
}

void solve(int x, int y, const int n, vector<string> &res, string &path,
           vector<vector<int>> &arr, const vector<Choice> &choices) {

    if (isSolved(x, y, n)) {
        res.push_back(path);
        return;
    }

    for (const auto &choice : choices) {
        int newX = x + choice.dx;
        int newY = y + choice.dy;

        if (isValid(newX, newY, n, arr)) {
            arr[x][y] = 0;
            path.push_back(choice.dname);
            solve(newX, newY, n, res, path, arr, choices);
            arr[x][y] = 1;
            path.pop_back();
        }
    }
}

class Solution {
public:
    vector<string> ratInMaze(vector<vector<int>> &mat) {
        int n = mat.size();
        vector<string> res;
        string path = "";
        vector<Choice> choices = {{'D', 1, 0}, {'L', 0, -1}, {'R', 0, 1}, {'U', -1, 0}};

        if (mat[0][0] == 1) {
            solve(0, 0, n, res, path, mat, choices);
        }

        return res;
    }
};

int main() {
    vector<vector<int>> maze = {
        {1, 0, 0, 0},
        {1, 1, 0, 1},
        {1, 1, 0, 0},
        {0, 1, 1, 1}
    };

    Solution obj;
    vector<string> result = obj.ratInMaze(maze);

    
    cout << "[";
    for (int i = 0; i < result.size(); i++) {
        cout << "\"" << result[i] << "\"";
        if (i != result.size() - 1)
            cout << ", ";
    }
    cout << "]" << endl;

    return 0;
}