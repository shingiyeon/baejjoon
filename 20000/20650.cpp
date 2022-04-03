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

    vector<int> num;
    for(int i=0; i<7; i++) {
        int tmp; cin >> tmp;
        num.push_back(tmp);
    }
    sort(num.begin(), num.end());
    cout << num[0] << " " << num[1] << " " << num[6] - num[0] - num[1];
}