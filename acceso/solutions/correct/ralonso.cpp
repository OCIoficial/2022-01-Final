#include <iostream>
#include <queue>
#include <tuple>
#include <vector>

using namespace std;

int main() {
    const tuple<int, int> directions[4] = { {0, 1}, {1, 0}, {0, -1}, {-1, 0} };

    const int blocked = -1;
    const int open = 0;
    const int reachable = 1;
    
    int m, n, x, y, f, e, a, b, c, z, r = 0;
    
    ios_base::sync_with_stdio(false);

    cin >> m >> n;

    vector<vector<int>> city(2 * m + 1, vector<int>(2 * n + 1, blocked));

    for (int i = 0; i < m; ++i) {
        for (int j = 0; j < n; j++) {
            city[2 * i + 1][2 * j + 1] = open;
        }
    }

    for (int i = 0; i < m; ++i) {
        cin >> z;
        for (int j = z ? 1 : 2 * n; j < 2 * n - 1; j += 2) {
            city[2 * i + 1][j + 1] = open;
        }
    }

    for (int j = 0; j < n; ++j) {
        cin >> z;
        for (int i = z ? 1 : 2 * m; i < 2 * m - 1; i += 2) {
            city[i + 1][2 * j + 1] = open;
        }
    }

    cin >> x >> y >> f >> e;
    x += x - 1;
    y += y - 1;
    f <<= 1;
    
    queue<tuple<int, int, int>> q;

    city[x][y] = reachable;
    q.push(make_tuple(x, y, f));

    while (!q.empty()) {
        tie(x, y, f) = q.front();
        q.pop();
        if (f <= 0) continue;
        for (auto [dx, dy] : directions) {
            if (city[x + dx][y + dy] == open) {
                city[x + dx][y + dy] = reachable;
                q.push(make_tuple(x + dx, y + dy, f - 1));
            }
        }
    }
    
    while (e--) {
        cin >> a >> b >> c;
        if (city[2 * a - 1 + c][2 * b - c] == reachable) {
            r++;
        }
    }

    cout << r << endl;

    return 0;
}
