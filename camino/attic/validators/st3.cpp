#include "testlib.h"
#include <vector>

using namespace std;

int main() {
  const int maxScore = 100000000;
  registerValidation();

  int M = inf.readInt(1, 100, "Filas");
  inf.readSpace();
  int N = inf.readInt(1, 100, "Columnas");
  inf.readEoln();

  vector<vector<int>> scores(M, vector<int>(N));

  for (int i = 1; i <= M; ++i) {
    for (int j = 1; j <= N; ++j) {
      scores[i][j] = inf.readInt(0, maxScore, "Puntaje desde arriba");
      if (i != N) inf.readSpace();
    }
    inf.readEoln();
  }

  for (int i = 1; i <= M; ++i) {
    for (int j = 1; j <= N; ++j) {
      int s = inf.readInt(0, maxScore, "Puntaje desde la izquierda");
      ensuref(
        s == scores[i][j],
        "Puntajes para (%d, %d) no coinciden: %d != %d",
        i,
        j,
        s,
        scores[i][j]
      );
      if (i != N) inf.readSpace();
    }
    inf.readEoln();
  }

  inf.readEof();
}
