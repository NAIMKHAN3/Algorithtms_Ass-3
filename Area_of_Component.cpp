#include <bits/stdc++.h>
using namespace std;

int n, m;

char mat[1005][1005];
bool vis[1005][1005];
int dx[4] = {-1, 1, 0, 0};
int dy[4] = {0, 0, -1, 1};

int dfs(int x, int y)
{
    if (x < 0 || x >= n || y < 0 || y >= m || vis[x][y] || mat[x][y] == '-')
    {
        return 0;
    }
    vis[x][y] = true;

    int area = 1;
    for (int i = 0; i < 4; i++)
    {
        area += dfs(x + dx[i], y + dy[i]);
    }

    return area;
}

int main()
{
    cin >> n >> m;
    memset(vis, false, sizeof(vis));

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cin >> mat[i][j];
        }
    }

    int minArea = INT_MAX;
    bool hasCom = false;

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (mat[i][j] == '.' && !vis[i][j])
            {
                hasCom = true;
                int area = dfs(i, j);
                minArea = min(minArea, area);
            }
        }
    }

    if (hasCom)
    {
        cout << minArea << endl;
    }
    else
    {
        cout << -1 << endl;
    }

    return 0;
}
