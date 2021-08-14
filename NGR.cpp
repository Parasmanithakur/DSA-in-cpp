//next greater element to right
//ngr
//stack question
#include <vector>
#include <stack>
#include <algorithm>
#include <iostream>
using namespace std;
vector<int> NGR(vector<int> arr)
{
    stack<int> s;
    vector<int> ans;
    int n = arr.size();
    for (int i = n - 1; i >= 0; i--) // traversing in reverse
    {

        if (!s.empty())
        {
            while (!s.empty() && s.top() <= arr[i])
                s.pop(); // poping out numbers ,As this no. will not be required
        }

        ans.push_back(s.empty() ? -1 : s.top()); //-1 if no NGR, s.top() if ngr present
        s.push(arr[i]);
    }
    reverse(ans.begin(), ans.end()); //reversing
    for (int i : ans)
    {
        cout << i << " ";
    }
    return ans;
}
vector<int> NGL(vector<int> arr)
{
    stack<int> s;
    vector<int> ans;
    int n = arr.size();
    for (int i = 0; i < n; i++) // traversing in reverse
    {

        if (!s.empty())
        {
            while (!s.empty() && s.top() <= arr[i])
                s.pop(); // poping out numbers ,As this no. will not be required
        }

        ans.push_back(s.empty() ? -1 : s.top()); //-1 if no NGR, s.top() if ngr present
        s.push(arr[i]);
    }
    //reverse(ans.begin(), ans.end()); //reversing
    for (int i : ans)
    {
        cout << i << " ";
    }
    return ans;
}
vector<int> NSL(vector<int> arr)
{
    stack<int> s;
    vector<int> ans;
    int n = arr.size();
    for (int i = 0; i < n; i++) // traversing in reverse
    {

        if (!s.empty())
        {
            while (!s.empty() && s.top() >= arr[i])
                s.pop(); // poping out numbers ,As this no. will not be required
        }

        ans.push_back(s.empty() ? -1 : s.top()); //-1 if no NGR, s.top() if ngr present
        s.push(arr[i]);
    }
    //reverse(ans.begin(), ans.end()); //reversing
    for (int i : ans)
    {
        cout << i << " ";
    }
    return ans;
}
vector<int> NSR(vector<int> arr)
{
    stack<int> s;
    vector<int> ans;
    int n = arr.size();
    for (int i = n - 1; i >= 0; i--) // traversing in reverse
    {

        if (!s.empty())
        {
            while (!s.empty() && s.top() >= arr[i])
                s.pop(); // poping out numbers ,As this no. will not be required
        }

        ans.push_back(s.empty() ? -1 : s.top()); //-1 if no NGR, s.top() if ngr present
        s.push(arr[i]);
    }
    reverse(ans.begin(), ans.end()); //reversing
    for (int i : ans)
    {
        cout << i << " ";
    }
    return ans;
}
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
    NGR(arr);
    cout << endl;
    NGL(arr);
    cout << endl;
    NSL(arr);
    cout << endl;
    NSR(arr);

    return 0;
}