//# Author : nuclear852 ========================#
//# Solution : 25423055 ========================#
//# Time Stamp : 2021-01-19 09:52:49 ===========#
//# Problem Title : 괄호 추가하기 ================#
//# Language : C++17 ===========================#

#include <stdio.h>
#include <vector>
#include <string>
#include <iostream>
using namespace std;

vector<long long> num;
vector<int> ope;

long long ans = -9999999999;
int N;

long long c(long long a, long long b, int o) {
    if(o == 0) return a + b;
    else if(o == 1) return a - b;
    else return a * b;
}

void calc(vector<int> state) {
    vector<long long> n;
    vector<int> o;
    int idx = 0;
    for(int i=0; i<num.size(); i++) {
        if(idx >= state.size()) {
            n.push_back(num[i]);
            continue;
        }
        if(state[idx] == i) continue;
        else if(state[idx] == i-1) {
            n.push_back(c(num[i-1], num[i], ope[state[idx]]));
            idx++;
        }
        else {
            n.push_back(num[i]);
        }
    }
    idx = 0;
    for(int i=0; i<ope.size(); i++) {
        if(idx >= state.size()) {
            o.push_back(ope[i]);
            continue;
        }
        if(state[idx] == i) {
            idx++; continue;
        }
        o.push_back(ope[i]);
    }
    

    long long tmp_ans = 0;
    for(int i=0; i<n.size(); i++) {
        if(i == 0) {
            tmp_ans = c(tmp_ans, n[0], 0);
        }
        else {
            tmp_ans = c(tmp_ans, n[i], o[i-1]);
        }
    }
    ans = max(ans, tmp_ans);
}


void d(int last, vector<int> v) {
    if(ope.size() == 0) {
        ans = num[0];
    }
    for(int i=last + 2; i<ope.size(); i++) {
        vector<int> state = v;
        state.push_back(i);
        calc(state);
        d(i, state);
    }
}


int main() {
    cin >> N;
    string str; cin >> str;
    for(int i=0; i<str.size(); i++) {
        if(str[i] >= '0' && str[i] <= '9') {
            num.push_back((long long)str[i] - '0');
        }
        else {
            if(str[i] == '+') ope.push_back(0);
            else if(str[i] == '-') ope.push_back(1);
            else ope.push_back(2);
        }
    }
    vector<int> v;
    d(-2, v);
    printf("%lld", ans);
}