//# Author : nuclear852 ========================#
//# Solution : 26152662 ========================#
//# Time Stamp : 2021-02-08 09:12:40 ===========#
//# Problem Title : 앞뒤가 맞는 수열 ==============#
//# Language : C++17 ===========================#

#include <iostream>
#include <string>
#include <vector>
using namespace std;

pair<int, int> KMP(vector<int> s) {
    vector<int> fail(s.size() + 5, s.size() - 1);
    int j = s.size() - 1;
    for(int i = s.size() - 2; i >= 0; i--) {
        while(j < s.size() - 1 && s[i] != s[j]) {
            j = fail[j+1];
        }
        if(s[i] == s[j]) {
            fail[i] = --j;
        }
    }
    int max_val = 0;
    int max_num = 0;
    for(int i=0; i<=s.size()-1; i++) {
        if( s.size() - 1 - fail[i] > max_val) {
            max_val = s.size() - 1 - fail[i];
            max_num = 1;
        }
        else if(s.size() - 1 - fail[i] == max_val) {
            max_num++;
        }
    }
    return {max_val, max_num};
}

int main() {
    cin.tie(NULL); cout.tie(NULL);
    ios::sync_with_stdio(false);
    int num;
    vector<int> arr;
    cin >> num;
    for(int i=0; i<num; i++) {
        int tmp; cin >> tmp;
        arr.push_back(tmp);
    }
    auto kmp = KMP(arr);
    if(kmp.first == 0) cout << "-1";
    else cout << kmp.first << " " << kmp.second;
}