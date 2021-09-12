// { Driver Code Starts
#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <map>
#include <string>
#include <stack>
#include <unordered_map>
#include <queue>
using namespace std;
// gfg question
// } Driver Code Ends
class Solution
{
public:
    vector<int> kthLargest(int k, int arr[], int n)
    {
        // code here
        vector<int> v;
        priority_queue<int, vector<int>, greater<int>> minH; // min heap
        for (int i = 0; i < n; i++)
        {
            if (minH.size() < k)
            {
                minH.push(arr[i]);
            }
            else if (minH.size() == k)
            {
                if (minH.top() < arr[i])
                {
                    minH.pop();
                    minH.push(arr[i]);
                }
            }
            if (minH.size() < k)
                v.push_back(-1);
            else
                v.push_back(minH.top());
        }
        return v;
    }
};

// { Driver Code Starts.
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int k, n;
        cin >> k >> n;
        int arr[n];
        for (int i = 0; i < n; i++)
            cin >> arr[i];

        Solution ob;
        vector<int> v = ob.kthLargest(k, arr, n);
        for (int i : v)
            cout << i << " ";
        cout << endl;
    }
    return 0;
} // } Driver Code Ends
