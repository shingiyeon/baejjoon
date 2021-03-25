//# Author : nuclear852 ========================#
//# Solution : 26530503 ========================#
//# Time Stamp : 2021-02-19 14:00:31 ===========#
//# Problem Title : DVD ====================#
//# Language : C++17 ===========================#

#include <iostream>
using namespace std;

int main() {
    long long w, W, h, H, x, y, vx, vy , X, Y;
    cin >> w >> h >> W >> H >> x >> y >> vx >> vy;
    X = vx > 0 ? x : (W-w-x);
    Y = vy > 0 ? y : (H-h-y);

    for(int i=1; i<=(H-h); i++) {
        if ( (Y-X + (W-w) * i) % (H-h) == 0) {
            cout << (W-w) * i - X;
            return 0;
        }
    }
    cout << "-1";
}