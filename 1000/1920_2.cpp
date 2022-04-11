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
typedef long long ll;
int main() {
    cin.tie(NULL);
    cout.tie(NULL);
    ios::sync_with_stdio(false);

    int N, M;
    vector<ll> v;
    ll val;

    cin >> N;
    for (int i = 0; i < N; i++)
    {
        cin >> val;
        v.push_back(val);
    }
    sort(v.begin(), v.end());
    cin >> M;
    for (int i = 0; i < M; i++)
    {
        cin >> val;
        if(binary_search(v.begin(), v.end(), val)) {
            cout << 1 << "\n";
        } else {
            cout << 0 << "\n";
        }
    }
    
    
}