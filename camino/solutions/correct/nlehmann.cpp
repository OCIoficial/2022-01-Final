#include <algorithm>
#include <cstdio>
#include <vector>
using namespace std;

typedef vector<vector<int>> matrix;

struct DP {
  matrix &up;
  matrix &left;
  matrix table;

  DP(matrix &up, matrix &left)
      : up(up), left(left), table(up.size(), vector<int>(up[0].size(), -1)) {}

  int solve() { return solve(up.size() - 1, up[0].size() - 1); }

  int solve(int i, int j) {
    if (table[i][j] != -1) {
      return table[i][j];
    }
    if (i == 0 && j == 0) {
      return 0;
    }

    table[i][j] = max(i > 0 ? up[i][j] + solve(i - 1, j) : -1,
                      j > 0 ? left[i][j] + solve(i, j - 1) : -1);
    return table[i][j];
  }
};

int main() {
  int M, N;
  scanf("%d%d", &M, &N);

  matrix up(M, vector<int>(N));
  for (int i = 0; i < M; ++i) {
    for (int j = 0; j < N; ++j) {
      scanf("%d", &up[i][j]);
    }
  }

  matrix left(M, vector<int>(N));
  for (int i = 0; i < M; ++i) {
    for (int j = 0; j < N; ++j) {
      scanf("%d", &left[i][j]);
    }
  }

  DP dp(up, left);

  printf("%d\n", dp.solve());

  return 0;
}
