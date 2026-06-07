#include <iostream>
#include <vector>
#include <queue>
using namespace std;

class Solution {
public:
    int snakesAndLadders(vector<vector<int>>& board) {

        int n = board.size();

        // Making the board easier to comprehend
        int node = 1;
        bool flag = true;

        vector<int> connection(n * n + 1, -1);

        for (int i = n - 1; i >= 0; i--) {

            if (flag) {

                for (int j = 0; j < n; j++) {

                    if (board[i][j] != -1) {
                        int destination = board[i][j];
                        connection[node] = destination;
                    }

                    node += 1;
                }

            } else {

                for (int j = n - 1; j >= 0; j--) {

                    if (board[i][j] != -1) {
                        int destination = board[i][j];
                        connection[node] = destination;
                    }

                    node += 1;
                }
            }

            flag = !flag;
        }

        vector<bool> visited(n * n + 1, false);

        queue<int> q;
        q.push(1);
        visited[1] = true;

        int moves = 0;

        while (!q.empty()) {

            int sz = q.size();

            while (sz--) {

                int curr = q.front();
                q.pop();

                if (curr == n * n) {
                    return moves;
                }

                for (int dice = 1; dice <= 6; dice++) {

                    int next = curr + dice;

                    if (next > n * n)
                        continue;

                    if (connection[next] != -1) {
                        next = connection[next];
                    }

                    if (!visited[next]) {
                        visited[next] = true;
                        q.push(next);
                    }
                }
            }

            moves++;
        }

        return -1;
    }
};

int main() {

    vector<vector<int>> board = {
        {-1,-1,-1,-1,-1,-1},
        {-1,-1,-1,-1,-1,-1},
        {-1,-1,-1,-1,-1,-1},
        {-1,35,-1,-1,13,-1},
        {-1,-1,-1,-1,-1,-1},
        {-1,15,-1,-1,-1,-1}
    };

    Solution obj;

    cout << "Minimum Moves = "
         << obj.snakesAndLadders(board)
         << endl;

    return 0;
}