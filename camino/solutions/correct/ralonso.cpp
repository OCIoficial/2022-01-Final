#include <iostream>
#include <vector>

using namespace std;

int main() {
    int m, n, p;

    ios_base::sync_with_stdio(false);

    cin >> m >> n;

    vector<vector<int>> pa(m, vector<int>(n));
    vector<vector<int>> pi(m, vector<int>(n));

    vector<vector<int>> dp(m, vector<int>(n, 0));

    for (int i = 0; i < m; ++i) {
        for (int j = 0; j < n; ++j) {
            cin >> p;
            pa[i][j] = p;
        }
    }

    for (int i = 0; i < m; ++i) {
        for (int j = 0; j < n; ++j) {
            cin >> p;
            pi[i][j] = p;
        }
    }

    for (int i = 1; i < m; ++i) {
        dp[i][0] = dp[i - 1][0] + pa[i][0];
    }

    for (int j = 1; j < n; ++j) {
        dp[0][j] = dp[0][j - 1] + pi[0][j];
    }

    for (int i = 1; i < m; ++i) {
        for (int j = 1; j < n; ++j) {
            dp[i][j] = max(dp[i - 1][j] + pa[i][j], dp[i][j - 1] + pi[i][j]);
        }
    }

    cout << dp[m - 1][n - 1] << endl;

    return 0;
}
 
