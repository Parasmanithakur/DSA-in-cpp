//sort a k sorted array
//heap question
#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int main()
{
    vector<int> arr;
    int n, k;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        int x;
        cin >> x;
        arr.push_back(x);
    }
    priority_queue<int, vector<int>, greater<int>> pq;
    vector<int> ans;
    cin >> k;
    for (int i = 0; i < n; i++)
    {

        pq.push(arr[i]);

        if (pq.size() > k)
        {
            ans.push_back(pq.top());
            pq.pop();
        }
    }
    while (!pq.empty())
    {
        ans.push_back(pq.top());
        pq.pop();
    }
    for (int i : ans)
        cout << i << "  ";
    return 0;
}