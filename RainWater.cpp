//Rain water traping question
//looks like histogram but different approach is required
#include <iostream>
#include <stack>
#include <vector>
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
    vector<int> mxl;
    mxl.push_back(arr[0]);
    for (int i = 1; i < n; i++)
    {
        mxl.push_back(max(mxl[i - 1], arr[i]));
    }
    vector<int> mxr(n);
    mxr[n - 1] = arr[n - 1];
    for (int i = n - 2; i >= 0; i--)
    {
        mxr[i] = (max(mxr[i + 1], arr[i]));
    }

    int ans = 0;
    vector<int> water(n);
    for (int i = 0; i < n; i++)
    {
        water[i] = min(mxl[i], mxr[i]) - arr[i];
    }
    for (int i = 0; i < n; i++)
    {
        ans += water[i];
    }
    cout << ans;
}