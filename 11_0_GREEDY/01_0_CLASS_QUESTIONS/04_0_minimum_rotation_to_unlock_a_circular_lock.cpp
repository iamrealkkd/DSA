#include <iostream>
#include <cmath>
using namespace std;

class Solution {
public:
    int rotationCount(long long R, long long D)
    {
        int ans = 0;
        int first, second;

        while (R)
        {
            first = R % 10;
            second = D % 10;

            R /= 10;
            D /= 10;

            ans += min(abs(first - second),
                       10 - abs(first - second));
        }

        return ans;
    }
};

int main()
{
    long long R = 123;
    long long D = 321;

    Solution obj;

    cout << obj.rotationCount(R, D) << endl;

    return 0;
}