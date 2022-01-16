#include "testlib.h"

using namespace std;

int main() {
  const int maxScore = 100000000;
  registerValidation();

  int M = inf.readInt(1, 100, "Filas");
  inf.readSpace();
  int N = inf.readInt(1, 100, "Columnas");
  inf.readEoln();

  int score;

  for (int i = 1; i <= M; ++i) {
    for (int j = 1; j <= N; ++j) {
      int s = inf.readInt(0, maxScore, "Puntaje desde arriba");
      if (i == 0 && j == 0) {
        score = s;
      } else {
        ensuref(
          s == score,
          "Puntajes para (%d, %d) no coinciden: %d != %d",
          i,
          j,
          s,
          score
        );
      }
      i == N ? inf.readEoln() : inf.readSpace();
    }
  }

  for (int i = 1; i <= M; ++i) {
    for (int j = 1; j <= N; ++j) {
      int s = inf.readInt(0, maxScore, "Puntaje desde la izquierda");
      ensuref(
        s == score,
        "Puntajes para (%d, %d) no coinciden: %d != %d",
        i,
        j,
        s,
        score
      );
      i == N ? inf.readEoln() : inf.readSpace();
    }
  }

  inf.readEof();
}
