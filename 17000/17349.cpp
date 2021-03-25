//# Author : nuclear852 ========================#
//# Solution : 26491354 ========================#
//# Time Stamp : 2021-02-18 11:06:36 ===========#
//# Problem Title : 1루수가 누구야 ===============#
//# Language : C++17 ===========================#

#include <iostream>
#include <vector>
#include <utility>
using namespace std;

int check(vector<pair<int, int> > v, int pos) {
    vector< vector<int> > tmp(10, vector<int>(2));
    int T = 0; int F = 0;
    v[pos] = {v[pos].first, !v[pos].second};
    for(auto val: v) {
        tmp[val.first][val.second] += 1;
    }
    for(int i=1; i<=9; i++) {
        if(tmp[i][0] == 0 && tmp[i][1]) T++;
        if(tmp[i][1] == 0 && tmp[i][0]) F++;
    }
    for(int i=1; i<=9; i++) {
        if(tmp[i][0] && tmp[i][1]) return 0;
    }
    if(T >= 2) return 0;
    if(T == 1) {
        for(int i=1; i<=9; i++) {
            if(tmp[i][0] == 0 && tmp[i][1]) return i;
        }
    }
    if(F == 8) {
        for(int i=1; i<=9; i++) {
            if(tmp[i][0] == 0) return i;
        }
    }
    return -1;
}

int main() {
    vector< pair<int, int> > v(9);
    for(int i=0; i<9; i++) {
        int a, b; cin >> a >> b;
        v[i] = {b, a};
    }
    int pos = 0;
    for(int i=0; i<9; i++) {
        int tmp_pos = 0;
        tmp_pos = check(v, i);
        if(tmp_pos == -1) {
            pos = 0;
            break;
        }
        if(pos && tmp_pos) {
            pos = 0;
            break;
        }
        else if(pos == 0) pos = tmp_pos;
    }
    cout << (pos == 0 ? -1 : pos);
}