#include "testlib.h"

using namespace std;

int main() {
  const int maxScore = 1000000;
  registerValidation();

  int M = inf.readInt(1, 500, "Filas");
  inf.readSpace();
  int N = inf.readInt(1, 500, "Columnas");
  inf.readEoln();

  int score;

  for (int i = 1; i <= M; ++i) {
    for (int j = 1; j <= N; ++j) {
      int s = inf.readInt(0, maxScore, "Puntaje desde arriba");
      if (i == 1 && j == 1) {
        score = s;
      } else {
        ensuref(s == score, "Puntajes para (%d, %d) no coinciden: %d != %d", i,
                j, s, score);
      }
      if (j != N)
        inf.readSpace();
    }
    inf.readEoln();
  }

  for (int i = 1; i <= M; ++i) {
    for (int j = 1; j <= N; ++j) {
      int s = inf.readInt(0, maxScore, "Puntaje desde la izquierda");
      ensuref(s == score, "Puntajes para (%d, %d) no coinciden: %d != %d", i, j,
              s, score);
      if (j != N)
        inf.readSpace();
    }
    inf.readEoln();
  }

  inf.readEof();
}
