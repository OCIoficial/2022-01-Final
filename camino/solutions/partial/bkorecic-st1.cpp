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
  int n, m, x; cin >> n >> m;
  for(int i=0; i<m; i++) cin >> x;
  int ans=0;
  for(int i=0; i<m; i++){
    cin >> x;
    if(i>0) ans += x;
  }
  cout << ans << '\n';
  return 0;
}
