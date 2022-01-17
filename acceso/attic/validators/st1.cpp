#include "testlib.h"

using namespace std;

int main() {
  registerValidation();

  int M = inf.readInt(1, 100, "Filas");
  inf.readSpace();
  int N = inf.readInt(1, 100, "Columnas");
  inf.readEoln();

  for (int i = 1; i <= M; ++i) {
    int c = inf.readInt(1, 1, "Fila tiene vereda");
    if (i != M) inf.readSpace();
  }
  inf.readEoln();

  for (int i = 1; i <= N; ++i) {
    int c = inf.readInt(1, 1, "Columna tiene vereda");
    if (i != N) inf.readSpace();
  }
  inf.readEoln();

  int X = inf.readInt(1, M, "Fila inicial");
  inf.readSpace();
  int Y = inf.readInt(1, N, "Columna inicial");
  inf.readSpace();
  int F = inf.readInt(1, M + N + max(M, N) - 3, "Distancia máxima");
  inf.readEoln();

  int E = inf.readInt(1, 1000, "Puntos de interés");
  inf.readEoln();

  for (int i = 1; i <= E; ++i) {
    int a = inf.readInt(1, M, "Fila de inicio de cuadra");
    inf.readSpace();
    int b = inf.readInt(1, N, "Columna de inicio de cuadra");
    inf.readSpace();
    int c = inf.readInt(0, 1, "Orientación de cuadra");

    ensuref(
        c ? a + 1 <= M : b + 1 <= N,
        "Punto de interés %d: está entre (%d, %d) y (%d, %d), grilla es %dx%d.",
        i,
        a,
        b,
        c ? a + 1 : a,
        c ? b : b + 1,
        M,
        N
    );

    inf.readEoln();
  }
  inf.readEof();
}
