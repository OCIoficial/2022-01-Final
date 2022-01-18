#include <iostream>
#include <vector>

using namespace std;

int main() {
    int n, k, suma, minima_suma;

    ios_base::sync_with_stdio(false);

    cin >> n;

    vector<int> m(n);

    for (int i = 0; i < n; ++i) {
        cin >> m[i];
    }

    minima_suma = 2000000000;
    for (int i = 0; i < n; ++i) {
        suma = 0;
        for (int j = 0; j < m[i]; ++j) {
            cin >> k;
            suma += k;
        }
        if (suma < minima_suma) {
            minima_suma = suma;
        }
    }

    cout << minima_suma << endl;

    return 0;
}
 
