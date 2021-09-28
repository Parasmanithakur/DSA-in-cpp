//cses question -Counting Rooms
//find number of room made by connected '.' and '#' is wall
//implicit graph ,dfs on 2d
#include <iostream>
#include <vector>
#include <queue>

using namespace std;
char path[1001][1001];

int n, m;
bool isValid(int x, int y)
{
    if (x < 0 || y < 0 || x >= n || y >= m)
        return false;
    if (path[x][y] == '#')
        return false;
    return true;
}
bool vist[1001][1001];
int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};
void dfs(int x, int y)
{
    vist[x][y] = true;
    for (int i = 0; i < 4; i++)
    {
        if (vist[x + dx[i]][y + dy[i]] == false)
        {
            if (isValid(x + dx[i], y + dy[i]))
            {
                dfs(x + dx[i], y + dy[i]);
            }
        }
    }
}
int main()
{

    cin >> n >> m;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cin >> path[i][j];
        }
    }
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            vist[i][j] = false;
    int countRoom = 0;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (path[i][j] == '.' && vist[i][j] == false)
            {
                dfs(i, j);
                // cout << i << j << endl;
                countRoom++; //counting conected componets
            }
        }
    }
    cout << countRoom << endl;
}