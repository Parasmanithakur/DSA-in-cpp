// mInimum spanning tree
// greedy/ sorting
//appraoch by DSU

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
struct edges
{
    int a, b, w;
    /* data */
};

bool comp(edges x, edges y)
{
    if (x.w < y.w)
        return true;
    return false;
}

int parent[10001];
int find(int a)
{
    if (parent[a] == -1)
        return a;
    return parent[a] = find(parent[a]);
}
void merge(int a, int b)
{
    parent[a] = b;
}
edges a[10001];
int main()
{
    int n, m, x, y;
    cin >> n >> m;
    for (int i = 1; i <= n; i++)
    {
        parent[i] = -1;
    }
    for (int i = 0; i < m; i++)
    {
        cin >> a[i].a >> a[i].b >> a[i].w;
    }
    sort(a, a + m, comp);
    int sum = 0;
    for (int i = 0; i < m; i++)
    {
        x = find(a[i].a);
        y = find(a[i].b);
        if (x != y)
        {
            sum += a[i].w;
            merge(x, y);
        }
    }
    cout << sum << endl;
    return 0;
}
/*
input
4 5
1 2 7
1 4 6
4 2 9
4 3 8
2 3 6
o/p- 19*/