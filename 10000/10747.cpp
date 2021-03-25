//# Author : nuclear852 ========================#
//# Solution : 26154192 ========================#
//# Time Stamp : 2021-02-08 10:45:05 ===========#
//# Problem Title : Censoring ==============#
//# Language : C++17 ===========================#

#include <stdio.h>
#include <iostream>
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

string KMP(string s, string p) {
    vector<int> fail = make_failFunc(p);
    vector<int> idx;
    string word = "";
    int j = 0;
    for(int i = 0; i < s.size(); i++) {
        word.push_back(s[i]);
        while(j && s[i] != p[j]) j = fail[j-1];
        if(s[i] == p[j]) ++j;
        idx.push_back(j);
        if(j == p.size()) {
            for(int i=0; i<p.size(); i++) {
                word.pop_back();
                idx.pop_back();
            }
            j = idx.back();
        }
    }
    return word;
}

int main() {
    cin.tie(NULL); cout.tie(NULL);
    ios::sync_with_stdio(false);
    string s, p;
    cin >> s >> p;
    cout << KMP(s, p);
}