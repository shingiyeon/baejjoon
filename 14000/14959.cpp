//# Author : nuclear852 ========================#
//# Solution : 26153639 ========================#
//# Time Stamp : 2021-02-08 10:19:43 ===========#
//# Problem Title : Slot Machines ==========#
//# Language : C++17 ===========================#

#include <iostream>
#include <stdio.h>
#include <vector>

using namespace std;

pair<int, int> kmp(vector<int> s) {
    vector<int> fail(s.size() + 5, s.size() - 1);
    vector<int> arr(s.size() + 5);
    int j = s.size() - 1;
    for(int i = s.size() - 2; i >= 0; i--) {
        while(j < s.size() - 1 && s[i] != s[j]) j = fail[j+1];
        if(s[i] == s[j]) fail[i] = --j;
    }

    for(int i=0; i<s.size(); i++) {
        arr[i] = fail[i] - i + 1;
    }

    int k, p;
    int idx = 999999999;
    for(int i=0; i<s.size(); i++) {
        if( i + arr[i] < idx) {
            idx = i + arr[i];
            k = i;
            p = arr[i];
        }
        else if(i + arr[i] == idx) {
            if( arr[i] < p) {
                k = i;
                p = arr[i];
            }
        }
    }

    return {k, p};
} 

int main() {
    cin.tie(NULL); cout.tie(NULL);
    ios::sync_with_stdio(false);
    int num, tmp;
    cin >> num;
    vector<int> s;
    for(int i=0; i<num; i++) {
        cin >> tmp; s.push_back(tmp);
    }
    auto ans = kmp(s);
    cout << ans.first << " " << ans.second;
}