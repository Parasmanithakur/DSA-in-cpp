#include <iostream>
#include <vector>
#include <algorithm>
//maximum subarray sum
using namespace std;
int kadanes(int arr[], int n)
{
    int cur = 0, maxTilNow = 0;
    for (int i = 0; i < n; i++)
    {

        cur += arr[i];
        maxTilNow = max(cur, maxTilNow);
        if (cur < 0) // when cur gets Negative we ignore it
            cur = 0;
    }
    return maxTilNow;
}
int main()
{
    int n;
    cin >> n;
    int arr[n];
    for (int i = 0; i < n; i++)
        cin >> arr[i];
    int ans = kadanes(arr, n);
    cout << ans << endl;
}