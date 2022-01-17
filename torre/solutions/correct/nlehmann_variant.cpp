#include <cstdio>
#include <vector>
using namespace std;

int N, V;
vector<int> P;
vector<int> sol;

bool simulate(int i) {
  sol.clear();

  if (P[i] > V) {
    return false;
  }

  sol.push_back(i);
  int v = V + 1;
  int left = i - 1;
  int right = i + 1;

  while (left >= 0 || right < N) {
    if (right < N && P[right] <= v) {
      sol.push_back(right++);
    } else if (left >= 0 && P[left] <= v) {
      sol.push_back(left--);
    } else {
      return false;
    }
    ++v;
  }
  return true;
}

int main() {
  scanf("%d%d", &N, &V);

  P.resize(N);
  for (int i = 0; i < N; ++i) {
    scanf("%d", &P[i]);
  }

  for (int i = 0; i < N; ++i) {
    if (simulate(i)) {
      for (int j = 0; j < N; ++j) {
        if (j > 0) {
          printf(" ");
        }
        printf("%d", sol[j] + 1);
      }
      printf("\n");
      return 0;
    }
  }
  printf("FALLIDA\n");

  return 0;
}
