//# Author : nuclear852 ========================#
//# Solution : 26154560 ========================#
//# Time Stamp : 2021-02-08 10:57:25 ===========#
//# Problem Title : 이름 정하기 =================#
//# Language : C++17 ===========================#

#include <stdio.h>
#include <iostream>
#include <string>
#include <vector>
using namespace std;

vector<int> make_failFunc(string p) {
    vector<int> fail(p.size());
    int j = 0;
    for(int i = 1; i < p.size(); i++) {
        while(j && p[i] != p[j]) j = fail[j-1];
        if(p[i] == p[j]) fail[i] = ++j;
    }
    return fail;
}

int main() {
    string s;
    int num;
    cin >> s >> num;

    auto fail = make_failFunc(s);
    long long ans = (long long) (num - 1) * ( s.size() - fail.back() ) + s.size();
    cout << ans;
}