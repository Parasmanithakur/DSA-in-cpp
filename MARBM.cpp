//maximum area of rectangle of binary matrix
//basicly 2d version of MAH

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
int MAH(vector<int> arr)
{
    int n = arr.size();

    vector<int> arr1, arr2;

    arr1 = NSL(arr);
    arr2 = NSR(arr);
    int ans = 0;
    for (int i = 0; i < n; i++)
    {
        //  cout << arr[i] << " _ " << arr2[i] << " " << arr1[i] << " " << endl;
        ans = max(ans, (arr2[i] - arr1[i] - 1) * arr[i]);
    }
    return ans;
}
int main()
{
    int n, m;
    cin >> n >> m;
    int arr[100][100];
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
        {
            cin >> arr[i][j];
        }
    vector<int> h;
    for (int j = 0; j < m; j++)
    {
        h.push_back(arr[0][j]);
    }

    int ans = MAH(h);
    //cout << ans << endl;

    for (int i = 1; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (arr[i][j] == 0)
                h[j] = 0;
            else
                h[j] += arr[i][j];
        }

        ans = max(ans, MAH(h));
    }
    cout << ans;
    return 0;
}