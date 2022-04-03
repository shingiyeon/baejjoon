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
int main() {
    cin.tie(NULL);
    cout.tie(NULL);
    ios::sync_with_stdio(false);

    int T; cin >> T;
    while(T--) {
        int n; cin >> n;
        vector<int> arr[2];
        vector< vector<int> > dy(2, vector<int>(n, 0));
        int ans = 0;
        for(int i=0; i<2; i++) {
            for(int j=0; j<n; j++) {
                int tmp; cin >> tmp;
                arr[i].push_back(tmp);
            }
        }

        dy[0][0] = arr[0][0];
        dy[1][0] = arr[1][0];

        if(n > 1) {
            dy[0][1] = arr[0][1] + arr[1][0];
            dy[1][1] = arr[1][1] + arr[0][0];
        }

        for(int i=2; i<n; i++) {
            dy[0][i] = arr[0][i] + max(dy[1][i-1], dy[1][i-2]);
            dy[1][i] = arr[1][i] + max(dy[0][i-1], dy[0][i-2]);
        }
        
        for(int i=0; i<n; i++) {
            ans = max(ans, max(dy[0][i], dy[1][i]));
        }
        cout << ans << "\n";
    }

}