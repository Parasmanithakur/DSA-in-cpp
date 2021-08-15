//stock span question
//stack similar to NGL
#include <iostream>
#include <vector>
#include <stack>
#include <algorithm>

using namespace std;

int main()
{
    int n;
    cin >> n;
    vector<int> arr;
    for (int i = 0; i < n; i++)
    {
        int x;
        cin >> x;
        arr.push_back(x);
    }
    stack<pair<int, int>> s;
    vector<int> ans;

    for (int i = 0; i < n; i++) // traversing in reverse
    {

        if (!s.empty())
        {
            while (!s.empty() && s.top().first <= arr[i])
                s.pop(); // poping out numbers ,As this no. will not be required
        }

        ans.push_back(s.empty() ? i + 1 : i - s.top().second); //-1 if no NGR, s.top() if ngr present
        s.push(make_pair(arr[i], i));
    }
    for (int i : ans)
    {
        cout << i << " ";
    }
}
