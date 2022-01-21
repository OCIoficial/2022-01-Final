#include <bits/stdc++.h>
using namespace std;

#ifdef LOCAL
#include "dbg.h"
#else
#define dbg(...) 1313
#endif

typedef long long ll;

const int INF = 1e9;

int main(){
  ios_base::sync_with_stdio(0); cin.tie(0);
  int n, m; cin >> n >> m;
  vector <vector <int>> cost(n, vector<int>(m));
  for(int i=0; i<n; i++)
    for(int j=0; j<m; j++)
      cin >> cost[i][j];
  vector <vector <int>> dp(n, vector<int>(m, -INF));
  dp[0][0] = 0; cost[0][0] = 0;
  for(int i=0; i<n; i++){
    for(int j=0; j<m; j++){
      if(i) dp[i][j] = max(dp[i][j], dp[i-1][j]);
      if(j) dp[i][j] = max(dp[i][j], dp[i][j-1]);
      dp[i][j] += cost[i][j];
    }
  }
  cout << dp[n-1][m-1] << '\n';
  return 0;
}
