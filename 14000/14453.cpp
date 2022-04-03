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

    int N; cin >> N;
    vector< vector<int> > sum(3, vector<int>(N, 0));
    for(int i=0; i<N; i++) {
        char c; cin >> c;
        if(c == 'H') sum[0][i]++;
        else if(c == 'S') sum[1][i]++;
        else sum[2][i]++;
        if(i == 0) continue;
        for(int j=0; j<3; j++) {
            sum[j][i] += sum[j][i-1];
        }
    }

    int ans = 0;
    for(int i=0; i<N; i++) {
        int l = max(sum[0][i], max(sum[1][i], sum[2][i]));
        int r = max(sum[0][N-1] - sum[0][i], max(sum[1][N-1]-sum[1][i], sum[2][N-1]-sum[2][i]));
        ans = max(ans , l+r);
    }
    cout << ans;
}