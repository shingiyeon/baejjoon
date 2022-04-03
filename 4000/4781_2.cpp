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

struct Candy{
    int c; double m;
    int k;
};

int main() {
    cin.tie(NULL);
    cout.tie(NULL);
    ios::sync_with_stdio(false);

    int n; double m;
    while(true) {
        cin >> n >> m;
        if(n == 0 && m == 0) break;
        int k = (int)(m * 100 + 0.5);

        vector<Candy> v;
        vector<int> dy(10001, 0);
        for(int i=0; i<n; i++) {
            Candy tmp; cin >> tmp.c >> tmp.m;
            tmp.k = (int)(tmp.m * 100 + 0.5);
            v.push_back(tmp);
        }

        for(int i=0; i<n; i++) {
            for(int j=0; j<=k; j++) {
                if(j >= v[i].k) {
                    dy[j] = max(dy[j], dy[j-v[i].k] + v[i].c);
                }
            }
        }
        cout << dy[k] << "\n";
    }
}