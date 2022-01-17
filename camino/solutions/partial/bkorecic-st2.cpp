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
  int n, m; cin >> n >> m;
  int x; cin >> x;
  cout << x*(n+m-2) << '\n';
  return 0;
}
