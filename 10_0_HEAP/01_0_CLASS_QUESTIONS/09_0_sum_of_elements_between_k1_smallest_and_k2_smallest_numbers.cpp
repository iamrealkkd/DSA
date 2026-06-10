#include <iostream>
#include <vector>
#include <queue>
using namespace std;

long long kthSmallest(vector<long long>& arr, long long k)
{
    priority_queue<long long> maxh;

    for(int i = 0; i < arr.size(); i++)
    {
        maxh.push(arr[i]);

        if(maxh.size() > k)
        {
            maxh.pop();
        }
    }

    return maxh.top();
}

long long sumBetweenTwoKth(vector<long long>& arr,
                           long long K1,
                           long long K2)
{
    long long first = kthSmallest(arr, K1);
    long long second = kthSmallest(arr, K2);

    long long sum = 0;

    for(int i = 0; i < arr.size(); i++)
    {
        if(arr[i] > first && arr[i] < second)
        {
            sum += arr[i];
        }
    }

    return sum;
}

int main()
{
    vector<long long> arr = {1, 3, 12, 5, 15, 11};

    long long K1 = 3;
    long long K2 = 6;

      cout << sumBetweenTwoKth(arr, K1, K2)
         << endl;

    return 0;
}