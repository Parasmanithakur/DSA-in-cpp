#include <iostream>
#include <vector>
#include <queue>
#include <math.h>
#include <cstring>
#include <algorithm>
using namespace std;
typedef long long ll;
void fillPrimes(vector<int> &prime, int high)
{
    bool ck[high + 1];
    memset(ck, true, sizeof(ck));
    ck[1] = false;
    ck[0] = false;
    for (int i = 2; (i * i) <= high; i++)
    {
        if (ck[i] == true)
        {
            for (int j = i * i; j <= high; j = j + i)
            {
                ck[j] = false;
            }
        }
    }
    for (int i = 2; i * i <= high; i++)
    {
        if (ck[i] == true)
        {
            prime.push_back(i);
        }
    }
}

vector<int> segmentedSieve(int low, int high)
{
    bool prime[high - low + 1];

    memset(prime, true, sizeof(prime));

    vector<int> chprime;
    fillPrimes(chprime, high);

    for (int i : chprime)
    {
        int lower = (low / i);

        if (lower <= 1)
        {
            lower = i + i;
        }
        else if (low % i)
        {
            lower = (lower * i) + i;
        }
        else
        {
            lower = (lower * i);
        }
        for (int j = lower; j <= high; j = j + i)
        {
            prime[j - low] = false;
        }
    }
    vector<int> ans;
    for (int i = low; i <= high; i++)
    {
        if (prime[i - low] == true)
        {
            ans.push_back(i);
        }
    }
    return ans;
}
vector<int> adj[100001];
vector<int> prime4 = segmentedSieve(999, 9999);

bool isValid(int x, int y)
{
    int flag = 0;
    while (x > 0)
    {
        if (y % 10 != x % 10)
            flag++;

        x = x / 10;
        y = y / 10;
    }

    if (flag == 1)
        return true;
    else
        return false;
}
void addEgde(int u, int v)
{
    adj[u].push_back(v);
    adj[v].push_back(u);
}
void buildGraph()
{
    for (int i = 0; i < prime4.size(); i++)
    {
        for (int j = i + 1; j < prime4.size(); j++)
        {
            if (isValid(prime4[i], prime4[j]))
            {
                addEgde(prime4[i], prime4[j]);
                //cout << prime4[j];
            }
        }
    }
}

bool vist[10001];
int dist[10001] = {0};
void bfs(int node)
{

    vist[node] = 1;
    dist[node] = 0;
    queue<int> q;

    q.push(node);
    while (!q.empty())
    {
        int cur = q.front();
        q.pop();
        for (int child : adj[cur])
        {
            if (!vist[child])
            {
                q.push(child);
                dist[child] = dist[cur] + 1;
                vist[child] = 1;
            }
        }
    }
}
int main()
{
    ll t;
    cin >> t;
    buildGraph();
    while (t--)
    {
        ll low, high;
        cin >> low >> high;
        for (int i = 999; i < 9999; i++)
            dist[i] = -1, vist[i] = 0;
        bfs(low);
        if (dist[high] != -1)
            cout << dist[high] << endl;
        else
            cout << "IMPOSSIBLE" << endl;
    }
}
