#include <algorithm>
#include <cstdio>
#include <map>
#include <queue>
#include <tuple>
#include <vector>
using namespace std;

typedef tuple<int, int> pii;

struct Grilland {
  int M;
  int N;
  vector<bool> horizontal_sidewalk;
  vector<bool> vertical_sidewalk;
  map<tuple<pii, pii>, int> points;

  template <typename F> void neighbors(int i, int j, F f) {
    int d[] = {-1, 1};
    for (int k = 0; k < 2; ++k) {
      int vi = i + d[k];
      if (vi >= 0 && vi < M && vertical_sidewalk[j]) {
        f(vi, j, points_for_block({i, j}, {vi, j}));
      }

      int vj = j + d[k];
      if (vj >= 0 && vj < N && horizontal_sidewalk[i]) {
        f(i, vj, points_for_block({i, j}, {i, vj}));
      }
    }
  }

  int points_for_block(pii a, pii b) { return points[{min(a, b), max(a, b)}]; }

  int bfs(int i, int j, int F) {
    queue<tuple<int, int>> q;
    vector<vector<int>> dist(M, vector<int>(N, -1));
    dist[i][j] = 0;
    q.push({i, j});

    int sum = 0;
    while (!q.empty()) {
      tie(i, j) = q.front(), q.pop();
      neighbors(i, j, [&](int vi, int vj, int p) {
        if (dist[vi][vj] == -1) {
          int d = dist[i][j] + 1;

          q.push({vi, vj});
          dist[vi][vj] = d;

          if (d <= F) {
            sum += p;
          }
        }
      });
    }
    return sum;
  }
};

int main() {
  Grilland g;

  scanf("%d%d", &g.M, &g.N);

  for (int i = 0; i < g.M; ++i) {
    int b;
    scanf("%d", &b);
    g.horizontal_sidewalk.push_back(b == 1);
  }
  for (int i = 0; i < g.N; ++i) {
    int b;
    scanf("%d", &b);
    g.vertical_sidewalk.push_back(b == 1);
  }

  int X, Y, F;
  scanf("%d%d%d", &X, &Y, &F);
  X--, Y--;

  int E;
  scanf("%d", &E);
  for (int i = 0; i < E; ++i) {
    int a, b, c;
    scanf("%d%d%d", &a, &b, &c);
    a--, b--;
    if (c == 0) {
      g.points[{{a, b}, {a, b + 1}}] += 1;
    } else {
      g.points[{{a, b}, {a + 1, b}}] += 1;
    }
  }

  printf("%d\n", g.bfs(X, Y, F));

  return 0;
}
