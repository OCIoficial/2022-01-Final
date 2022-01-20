#include "testlib.h"
#include <vector>

using namespace std;

int main() {
  registerValidation();

  int N = inf.readInt(1, 500, "N");
  inf.readEoln();

  vector<int> lengths(N);
  for (int i = 0; i < N; ++i) {
    if (i > 0) {
      inf.readSpace();
    }
    lengths[i] = inf.readInt(1, 1000, "M_i");
  }
  inf.readEoln();

  for (int i = 0; i < N; ++i) {
    for (int j = 0; j < lengths[i]; ++j) {
      if (j > 0) {
        inf.readSpace();
      }
      inf.readInt(1, 1000, "M_i");
    }
    inf.readEoln();
  }

  inf.readEof();
}
