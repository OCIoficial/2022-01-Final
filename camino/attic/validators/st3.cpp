#include "testlib.h"
#include <vector>

using namespace std;

int main() {
  const int maxScore = 1000000;
  registerValidation();

  int M = inf.readInt(1, 500, "Filas");
  inf.readSpace();
  int N = inf.readInt(1, 500, "Columnas");
  inf.readEoln();

  vector<vector<int>> scores(M, vector<int>(N));

  for (int i = 0; i < M; ++i) {
    for (int j = 0; j < N; ++j) {
      if (j > 0)
        inf.readSpace();
      scores[i][j] = inf.readInt(0, maxScore, "Puntaje desde arriba");
    }
    inf.readEoln();
  }

  for (int i = 0; i < M; ++i) {
    for (int j = 0; j < N; ++j) {
      if (j > 0)
        inf.readSpace();
      int s = inf.readInt(0, maxScore, "Puntaje desde la izquierda");
      ensuref(s == scores[i][j],
              "Puntajes para (%d, %d) no coinciden: %d != %d", i, j, s,
              scores[i][j]);
    }
    inf.readEoln();
  }

  inf.readEof();
}
