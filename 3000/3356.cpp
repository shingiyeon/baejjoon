//# Author : nuclear852 ========================#
//# Solution : 26017540 ========================#
//# Time Stamp : 2021-02-04 11:10:20 ===========#
//# Problem Title : 라디오 전송 =================#
//# Language : C++17 ===========================#

#include <stdio.h>
#include <string>
#include <vector>
#include <iostream>
using namespace std;

string str;
int N;
vector<int> make_failFunc() {
    vector<int> fail(N + 5);

    int j = 0;
    for(int i=1; i<str.size(); i++) {
        while(j && str[i] != str[j]) j = fail[j-1];
        if (str[i] == str[j]) {
            fail[i] = ++j;
        }
    }
    return fail;
}

int main() {
    cin.tie(NULL); cout.tie(NULL);
    ios::sync_with_stdio(false);
    cin >> N >> str;
    auto f = make_failFunc();
    cout << N - f[N-1];
}