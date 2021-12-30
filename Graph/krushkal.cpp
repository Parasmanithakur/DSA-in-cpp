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

typedef long long ll;

using namespace std;

vector<ll> parent(100005), Size(100005);
void make(ll v)
{
    parent[v] = v;
    Size[v] = 1;
}
ll find(ll n)
{
    if (n == parent[n])
        return n;
    else
        return parent[n] = find(parent[n]);
}
void Union(ll a, ll b)
{
    a = find(a);
    b = find(b);

    if (a != b)
    {
        if (Size[a] < Size[b])
            swap(a, b);

        parent[b] = a;
        Size[a] += Size[b];
    }
}
void solve()
{
    vector<pair<ll, pair<ll, ll>>> edges;
    ll n, m;
    cin >> n >> m;

    for (int i = 0; i < m; i++)
    {
        ll x, y, w;
        cin >> x >> y >> w;
        edges.push_back({w, {x, y}});
    }
    for (int i = 1; i <= n; i++)
    {
        make(i);
    }
    sort(edges.begin(), edges.end());
    ll sum = 0;
    for (int i = 0; i < m; i++)
    {
        ll x = edges[i].second.first, y = edges[i].second.second, w = edges[i].first;
        if (find(x) != find(y))
        {
            Union(x, y);
            sum += w;
            //cout << x << " " << y << endl;
        }
    }
    cout << sum << endl;
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);

    solve();

    return 0;
}

/*ip -6 9
5 4 9
1 4 1
5 1 4
4 3 5
4 2 3
1 2 2
3 2 3
3 6 8
2 6 7
op-17
