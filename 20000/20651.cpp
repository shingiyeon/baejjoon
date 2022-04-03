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
    vector<int> v;
    for(int i=0; i<N; i++) {
        int tmp; cin >> tmp; v.push_back(tmp);
    }
    int ans = 0;
    for(int i=0; i<N; i++) {
        int sum = 0;
        for(int j=i; j<N; j++) {
            sum += v[j];
            int len = j - i + 1;
            if(sum % len == 0) {
                bool flag = false;
                for(int k=i; k<=j; k++) {
                    if(v[k] == (sum / len)) flag = true;
                }
                ans += flag;
            }
        }
    }
    cout << ans;
}