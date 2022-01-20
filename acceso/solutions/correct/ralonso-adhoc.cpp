#include <cmath>
#include <iostream>
#include <vector>

using namespace std;

enum Scenario { Isolated, Horizontal, Vertical, Manhattan, OneIntersection, NoHorizontal, NoVertical };

bool reachable(int x, int y, int a, int b, int c, int f);

int main() {

    int m, n, x, y, f, e, a, b, c, z, r = 0;
    
    ios_base::sync_with_stdio(false);

    cin >> m >> n;

    vector<int> hori(m + 1);
    vector<int> vert(n + 1);

    for (int i = 1; i <= m; ++i) {
        cin >> hori[i];
    }

    for (int j = 1; j <= n; ++j) {
        cin >> vert[j];
    }

    cin >> x >> y >> f >> e;

    Scenario scenario = (Scenario)(hori[x] | (vert[y] << 1));

    int x1 = 0, y1 = 0, f1 = 0;
    int x2 = 0, y2 = 0, f2 = 0;

    switch (scenario) {
    case Isolated:  // No sidewalks to walk on
        cout << 0 << endl;
        return 0;
    case Horizontal:
        int j;
        x1 = x2 = x;
        for (j = y - 1; j > 0; --j) {
            if (vert[j]) {
                y1 = j;
                f1 = f - abs(y - y1);
                break;
            }
        }
        for (j = y + 1; j <= n; ++j) {
            if (vert[j]) {
                y2 = j;
                f2 = f - abs(y - y2);
                break;
            }
        }
        if (y1 && y2) {
        } else if (y1 || y2) {
            scenario = OneIntersection;
            if (y2) {
                y1 = y2;
                f1 = f2;
            }
        } else {
            scenario = NoVertical;
        }
        break;
    case Vertical:
        int i;
        y1 = y2 = y;
        for (i = x - 1; i > 0; --i) {
            if (hori[i]) {
                x1 = i;
                f1 = f - abs(x - x1);
                break;
            }
        }
        for (i = x + 1; i <= m; ++i) {
            if (hori[i]) {
                x2 = i;
                f2 = f - abs(x - x2);
                break;
            }
        }
        if (x1 && x2) {
        } else if (x1 || x2) {
            scenario = OneIntersection;
            if (x2) {
                x1 = x2;
                f1 = f2;
            }
        } else {
            scenario = NoHorizontal;
        }
        break;
    case Manhattan:
        break;
    }

    while (e--) {
        cin >> a >> b >> c;
        if ((c && !vert[b]) || (!c && !hori[a])) {
            continue;  // Point of interest has no sidewalk
        }
        if ((c && b == y) || (!c && a == x) || scenario == Manhattan) {
            // Same sidewalk or starting from sidewalk intersection
            if (reachable(x, y, a, b, c, f)) r++;
            continue;
        }

        switch (scenario) {
        case NoHorizontal:
        case NoVertical:
            break;  // Unreachable
        case Horizontal:
        case Vertical:
            // 2 intersections to start from
            if (reachable(x1, y1, a, b, c, f1) || reachable(x2, y2, a, b, c, f2)) {
                r++;
            }
            break;
        case OneIntersection:
            if (reachable(x1, y1, a, b, c, f1)) {
                r++;
            }
            break;
        }
    }

    cout << r << endl;

    return 0;
}

bool reachable(int x, int y, int a, int b, int c, int f) {
    int aa, bb;
    if (c) {  // Vertical
        aa = a + 1;
        bb = b;
    } else {
        aa = a;
        bb = b + 1;
    }
    return abs(x - a) + abs(y - b) <= f && abs(x - aa) + abs(y - bb) <= f;
}
