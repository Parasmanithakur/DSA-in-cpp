//heaps
#include <queue>
#include <iostream>
#include <vector>

using namespace std;

int main()
{

    priority_queue<int> maxH;                            // max heap using p Queue
    priority_queue<int, vector<int>, greater<int>> minH; // min heap using P queue

    vector<int> arr;
    int n;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        int x;
        cin >> x;
        arr.push_back(x);
    }
    int k;
    cin >> k;
    for (int i = 0; i < arr.size(); i++)
    {
        maxH.push(arr[i]);
        if (maxH.size() > k)
            maxH.pop();
    }
    for (int i = 0; i < arr.size(); i++)
    {
        minH.push(arr[i]);
        if (minH.size() > k)
            minH.pop();
    }

    cout << "K th smallest number in arr " << maxH.top() << endl; // in nLogk

    cout << "k th largest number in arr " << minH.top();
    return 0;
}
