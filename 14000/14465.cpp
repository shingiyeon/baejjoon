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

    int N, K, B; cin >> N >> K >> B;
    vector<int> arr(N+1, 1);
    for(int i=0; i<B; i++) {
        int tmp; cin >> tmp;
        arr[tmp] = 0;
    }

    int ans = 100000;
    int sum = 0;
    for(int i=1; i<=K; i++) {
        sum += arr[i];
    }
    ans = min(ans, K - sum);
    for(int i=K+1; i<=N; i++) {
        sum += arr[i];
        sum -= arr[i-K];
        ans = min(ans, K - sum);
    }
    cout << ans << "\n";
}