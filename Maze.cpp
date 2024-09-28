#include <bits/stdc++.h>
using namespace std;

int n, m;
char mat[1005][1005];
bool vis[1005][1005];
int strX, strY;
int dx[4] = {0, 0, -1, 1};
int dy[4] = {1, -1, 0, 0};

pair<int, int> par[1005][1005];

void bfs(int x, int y) {
    queue<pair<int, int>> q;
    q.push({x, y});
    vis[x][y] = true;

    while (!q.empty()) {
        pair<int, int> parent = q.front();
        int chiX = parent.first;
        int chiY = parent.second;
        q.pop();

        if (mat[chiX][chiY] == 'D') {
            while (mat[chiX][chiY] != 'R') {
                pair<int, int> prev = par[chiX][chiY];
                if (mat[chiX][chiY] != 'D') {
                    mat[chiX][chiY] = 'X';
                }
                chiX = prev.first;
                chiY = prev.second;
            }
            return;
        }
        for (int i = 0; i < 4; i++) {
            int newX = chiX + dx[i];
            int newY = chiY + dy[i];

            if (newX >= 0 && newX < n && newY >= 0 && newY < m && !vis[newX][newY] && (mat[newX][newY] == '.' || mat[newX][newY] == 'D')) {
                vis[newX][newY] = true;
                par[newX][newY] = {chiX, chiY};
                q.push({newX, newY});
            }
        }
    }

}

int main() {
    cin >> n >> m;
    memset(vis, false, sizeof(vis));

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> mat[i][j];
            if (mat[i][j] == 'R') {
                strX = i;
                strY = j;
            }
        }
    }

bfs(strX, strY);

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cout << mat[i][j];
        }
        cout << endl;
    }

    return 0;
}
