#include <iostream>
#include <vector>

using namespace std;

int main() {
    int n, v;

    ios_base::sync_with_stdio(false);

    cin >> n >> v;

    vector<vector<int>> dp(n + 2, vector<int>(n + 2, -1));
    vector<int> p(n + 1, 0);

    for (int i = 1; i <= n; i++) {
        cin >> p[i];
    }
    for (int i = 1; i <= n + 1; i++) {
        dp[i][i] = 0;
    }

    for (int r = 1; r <= n; r++, v++) {
        for (int i = 1; i <= n - r + 1; i++) {
            if (dp[i][i + r - 1] >= 0 && p[i + r - 1] <= v) {
                dp[i][i + r] = i + r - 1;
            } else if (dp[i + 1][i + r] >= 0 && p[i] <= v) {
                dp[i][i + r] = i;
            }
        }
    }

    if (dp[1][n + 1] == -1) {
        cout << "FALLIDA" << endl;
        return 0;
    }

    int l = 1, r = n + 1;
    for (int i = 1; i <= n; ++i) {
        p[n + 1 - i] = dp[l][r];
        p[n + 1 - i] == l ? l++ : r--;
    }

    for (int i = 1; i < n; ++i) {
        cout << p[i] << " ";
    }
    cout << p[n] << endl;

    return 0;
}
