/*
 * Final OCI 2021
 * Problema: Torre
 * Autor solución: Blaz
 */
#include <bits/stdc++.h>
using namespace std;

#ifdef LOCAL
#include "dbg.h"
#else
#define dbg(...) 1313
#endif

typedef long long ll;

int main(){
  ios_base::sync_with_stdio(0); cin.tie(0);
  int n, v; cin >> n >> v;
  vector <int> a(n);
  for(int i=0; i<n; i++) cin >> a[i];
  vector <vector <bool>> dp(n, vector<bool>(n, 0));
  vector <vector <int>> last(n, vector<int>(n, -1));
  for(int i=0; i<n; i++){
    if(a[i] <= v){
      dp[i][i] = 1;
      last[i][i] = i;
    }
  }
  for(int i=n-1; i>=0; i--){
    for(int j=i+1; j<n; j++){
      int cur_v = v+j-i;
      if(dp[i][j-1] && cur_v >= a[j]){
        dp[i][j] = 1;
        last[i][j] = j;
      }
      else if(dp[i+1][j] && cur_v >= a[i]){
        dp[i][j] = 1;
        last[i][j] = i;
      }
    }
  }
  if(dp[0][n-1]){
    vector <int> ans;
    int l=0, r=n-1;
    while(l<=r){
      ans.push_back(last[l][r]);
      if(last[l][r] == r) r--;
      else l++;
    }
    for(int i=ans.size()-1; i>=0; i--){
      cout << ans[i]+1 << ' ';
    } cout << '\n';
  }
  else{
    cout << "FALLIDA\n";
  }
  return 0;
}
