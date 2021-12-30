#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <map>
#include <string>
#include <stack>
#include <queue>
#include <unordered_map>
#include <unordered_set>
#include <map>
#include <set>
#include <climits>
#include <cstring>

#define inf INT_MAX;
#define minf INT_MIN
#define deb(x) cout << #x << "=" << x << endl
#define deb2(x, y) cout << #x << "=" << x << "," << #y << "=" << y << endl
#define debarr(arr)     \
    for (auto &i : arr) \
    cout << i           \
         << " "
#define mod 1000000007
const int N = 1e3 + 10;
typedef long long ll;

using namespace std;
ll dist[N][N];
void solve()
{
    ll n, m;
    cin >> n >> m;
    for (int i = 0; i <= n; i++)
    {
        for (int j = 0; j <= n; j++)
        {
            if (i == j)
                dist[i][j] = 0;
            else

                dist[i][j] = inf;
        }
    }

    for (int i = 0; i < m; i++)
    {
        ll x, y, wt;
        cin >> x >> y >> wt;
        dist[x][y] = wt;
    }
    for (int k = 1; k <= n; k++)
    {
        for (int i = 1; i <= n; i++)
        {
            for (int j = 1; j <= n; j++)
            {
                dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
            }
        }
    }
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            if (dist[i][j] != INT_MAX)
            {
                cout << dist[i][j] << " ";
            }
            else
                cout << "I ";
        }
        cout << endl;
    }
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);

    solve();

    return 0;
}
/*Ip
6 9
1 2 1
1 3 5
2 3 2
3 5 2
2 4 2
4 5 3
4 6 1
5 6 2

op 0 1 3 3 5 4 
I 0 2 2 4 3 
I I 0 I 2 4 
I I I 0 3 1 
I I I I 0 2 
I I I I I 0
 */
