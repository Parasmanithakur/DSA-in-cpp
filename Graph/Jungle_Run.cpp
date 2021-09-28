//Jngle Run hackerearth
//implicit graph -2d
//bfs on grid
#include <iostream>
#include <vector>
#include <queue>

using namespace std;
char path[31][31];
bool isvalid(int x, int y, int n)
{
    if (x < 0 || y < 0 || x >= n || y >= n)
    {
        return false;
    }
    if (path[x][y] == 'P' || path[x][y] == 'E')
        return true;
    return false;
}
int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};
int bfs(int x, int y, int n)
{
    bool vist[n][n] = {false};
    queue<pair<int, int>> q;
    q.push({x, y});
    vist[x][y] = true;
    int dist[n][n] = {0};
    dist[x][y] = 0;
    int level = 0;
    while (!q.empty())
    {
        pair<int, int> p = q.front();

        q.pop();
        level++;
        for (int i = 0; i < 4; i++)
        {
            int X = p.first + dx[i], Y = p.second + dy[i];
            if (!vist[X][Y])
            {
                if (isvalid(X, Y, n))
                {
                    dist[X][Y] = dist[p.first][p.second] + 1;
                    q.push({X, Y});
                    vist[X][Y] = true;
                }
            }
            if (path[X][Y] == 'E')
                return dist[X][Y];
        }
    }
    return 0;
}
int main()
{
    int n;
    cin >> n;
    int x, y;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cin >> path[i][j];
            if (path[i][j] == 'S')
                x = i, y = j;
        }
    }
    cout << bfs(x, y, n) << endl;
}