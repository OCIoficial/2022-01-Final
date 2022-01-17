#include "testlib.h"

using namespace std;

int main() {
  registerValidation();

  int N = inf.readInt(1, 500, "N");
  inf.readSpace();
  int V = inf.readInt(1, 1000000000, "V");
  inf.readEoln();

  for (int i = 0; i < N; ++i) {
    if (i > 0)
      inf.readSpace();
    inf.readInt(1, 1000000000, "P");
  }
  inf.readEoln();

  inf.readEof();
}
