#include <iostream>
#include <math.h>
#include <vector>
#include <algorithm>
#include <map>
#include <unordered_map>
#include <set>
#include <unordered_set>
#include <functional>
#include <queue>
#include <stack>
#include <string>
using namespace std;

class Line {
public:
    int x, y;
    Line(int x1, int y1, int x2, int y2) {
        x = x2 - x1;
        y = y2 - y1;
    }

    static int ccw(Line a, Line b) {
        return a.x*b.y - a.y*b.x;
    }
};

int main() {
    cin.tie(NULL);
    cout.tie(NULL);
    ios::sync_with_stdio(false);
    int x[3], y[3];
    for(int i=0; i<3; i++) cin >> x[i] >> y[i];
    Line a(x[0], y[0], x[1], y[1]);
    Line b(x[1], y[1], x[2], y[2]);
    int ccw = Line::ccw(a, b);
    if(ccw < 0) ccw = -1;
    else if(ccw > 0) ccw = 1;
    cout << ccw;
}