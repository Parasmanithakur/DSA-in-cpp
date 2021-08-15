
//Maximum area of histogram
//a variation of nsl,nsr
#include <iostream>
#include <vector>
#include <stack>
#include <algorithm>
#include <cmath>
using namespace std;
vector<int> NSL(vector<int> arr)
{
    stack<pair<int, int>> s;
    vector<int> ans;
    int n = arr.size();
    for (int i = 0; i < n; i++)
    {

        if (!s.empty())
        {
            while (!s.empty() && s.top().first >= arr[i])
                s.pop();
        }

        ans.push_back(s.empty() ? -1 : s.top().second);
        s.push(make_pair(arr[i], i));
    }
    //reverse(ans.begin(), ans.end()); //reversing

    return ans;
}
vector<int> NSR(vector<int> arr)
{
    stack<pair<int, int>> s;
    vector<int> ans;
    int n = arr.size();
    for (int i = n - 1; i >= 0; i--) // traversing in reverse
    {

        if (!s.empty())
        {
            while (!s.empty() && s.top().first >= arr[i])
                s.pop(); // poping out numbers ,As this no. will not be required
        }

        ans.push_back(s.empty() ? n : s.top().second);
        s.push(make_pair(arr[i], i));
    }
    reverse(ans.begin(), ans.end()); //reversing

    return ans;
}
int main()
{
    int n;
    cin >> n;
    vector<int> arr, arr1, arr2;
    for (int i = 0; i < n; i++)
    {
        int x;
        cin >> x;
        arr.push_back(x);
    }

    arr1 = NSL(arr);
    arr2 = NSR(arr);
    int ans = 0;
    for (int i = 0; i < n; i++)
    {
        //  cout << arr[i] << " _ " << arr2[i] << " " << arr1[i] << " " << endl;
        ans = max(ans, (arr2[i] - arr1[i] - 1) * arr[i]);
    }
    cout << ans << endl;
    return 0;
}