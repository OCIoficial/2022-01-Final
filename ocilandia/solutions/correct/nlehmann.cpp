#include <algorithm>
#include <climits>
#include <cstdio>
#include <vector>
using namespace std;

int main() {
  int n;
  scanf("%d", &n);

  vector<int> lengths(n);
  for (int i = 0; i < n; ++i) {
    scanf("%d", &lengths[i]);
  }

  int best = INT_MAX;
  for (int i = 0; i < n; ++i) {
    int sum = 0;
    for (int j = 0; j < lengths[i]; ++j) {
      int a;
      scanf("%d", &a);
      sum += a;
    }
    best = min(sum, best);
  }
  printf("%d\n", best);
  return 0;
}
