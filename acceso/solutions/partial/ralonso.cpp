#include <iostream>

using namespace std;

int main() {
    int m, n, x, y, f, e, a, b, c, z, r = 0;
    
    ios_base::sync_with_stdio(false);

    cin >> m >> n;

    for (int i = 0; i < m; ++i) {
        cin >> z;
    }

    for (int j = 0; j < n; ++j) {
        cin >> z;
    }

    cin >> x >> y >> f >> e;
    f += f;
    x += x;
    y += y;
    
    while (e--) {
        cin >> a >> b >> c;
        a += a + c;
        b += b + 1 - c;
        if (abs(x - a) + abs(y - b) <= f) {
            r++;
        }
    }

    cout << r << endl;

    return 0;
}
