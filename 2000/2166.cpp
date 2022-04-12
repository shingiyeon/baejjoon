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

class Point {
public:
    int x, y;
    Point(int x, int y) {
        this->x = x;
        this->y = y;
    }
};

long double area(Point a, Point b) {
    return (long double)a.x * b.y - (long double)a.y * b.x;
}

int main() {
    cin.tie(NULL);
    cout.tie(NULL);
    ios::sync_with_stdio(false);
    int N; cin >> N;
    vector<Point> p;
    long double ans = 0;
    int x, y;
    for(int i=0; i<N; i++) {
        cin >> x >> y;
        p.push_back(Point(x, y));
    }
    p.push_back(p[0]);
    for(int i=0; i<N; i++) {
        ans += area(p[i], p[i+1]);
    }
    cout<<fixed;
    cout.precision(1);
    ans *= 0.5;
    if(ans < 0) ans *= -1;
    cout << ans;

}