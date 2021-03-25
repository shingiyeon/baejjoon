//# Author : nuclear852 ========================#
//# Solution : 26491476 ========================#
//# Time Stamp : 2021-02-18 11:11:56 ===========#
//# Problem Title : 2루수 이름이 뭐야 =============#
//# Language : C++17 ===========================#

#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
using namespace std;

vector<string> v;

int main() {
    cin.tie(NULL); cout.tie(NULL);
    ios::sync_with_stdio(false);
    int N; cin >> N;
    for(int i=0; i<N; i++) {
        string tmp; cin >> tmp;
        v.push_back(tmp);
    }
    sort(v.begin(), v.end());
    
    if(binary_search(v.begin(), v.end(), "anj")) {
        cout << "뭐야;";
    }
    else {
        cout << "뭐야?";
    }
}