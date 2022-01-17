#include "testlib.h"

using namespace std;

int main() {
  registerValidation();

  int M = inf.readInt(1, 1, "Filas");
  inf.readSpace();
  int N = inf.readInt(1, 100, "Columnas");
  inf.readEoln();

  for (int i = 1; i <= M; ++i) {
    for (int j = 1; j <= N; ++j) {
      int s = inf.readInt(0, 100000000, "Puntaje desde arriba");
      if (i != N) inf.readSpace();
    }
    inf.readEoln();
  }

  for (int i = 1; i <= M; ++i) {
    for (int j = 1; j <= N; ++j) {
      int s = inf.readInt(0, 100000000, "Puntaje desde la izquierda");
      if (i != N) inf.readSpace();
    }
    inf.readEoln();
  }

  inf.readEof();
}
