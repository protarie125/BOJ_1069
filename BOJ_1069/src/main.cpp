#include <iostream>
#include <iomanip>
#include <cmath>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    double X, Y, D, T;
    cin >> X >> Y >> D >> T;

    double dist = sqrt(X * X + Y * Y);
    auto time = dist;

    auto jump = static_cast<int>(dist / D);
    dist -= jump * D;

    if (0 == jump) {
        time = min(time, T + (D - dist));
        time = min(time, 2 * T);
    }
    else {
        time = min(time, jump * T + dist);
        time = min(time, (jump + 1.0) * T);
    }

    cout << fixed << setprecision(10) << time;

    return 0;
}