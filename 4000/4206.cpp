//# Author : nuclear852 ========================#
//# Solution : 26022193 ========================#
//# Time Stamp : 2021-02-04 14:06:20 ===========#
//# Problem Title : 피보나치 단어 ================#
//# Language : C++17 ===========================#

#include <iostream>
#include <string>
#include <vector>
using namespace std;
int N;
string str[101];
long long dy[101];
vector<int> make_failFunc(string s) {
    vector<int> fail(s.size() + 1);
    int j = 0;
    for(int i=1; i<s.size(); i++) {
        while(j && s[i] != s[j]) j = fail[j-1];
        if(s[i] == s[j]) fail[i] = ++j;
    }
    return fail;
}

long long KMP(string s, string p) {
    auto fail = make_failFunc(p);
    long long ans = 0;
    int j = 0;
    for(int i=0; i<s.size(); i++) {
        while(j && s[i]!=p[j]) j = fail[j-1];
        if(s[i] == p[j]) {
            ++j;
            if(j == p.size()) {
                ans++;
                j = fail[j-1];
            }
        }
    }
    return ans;
} 

int main() {
    cin.tie(NULL); cout.tie(NULL);
    ios::sync_with_stdio(false);
    str[0] = "0";
    str[1] = "1";
    for(int i=2; i<=28; i++) {
        str[i] = str[i-1] + str[i-2];
    }
    int num = 1;
    while(scanf("%d", &N) != EOF) {
        char tmp[101010]; scanf("%s", tmp);
        string st = tmp;
        for(int i=0; i<=100; i++) dy[i] = 0;
        int idx = 0;
        int l_idx = 0;
        for(int i=0; i<=28; i++) {
            dy[i] = KMP(str[i], st);
            if(dy[i] > 0) idx++;
            else idx = 0;
            if(idx == 4) {
                l_idx = i;
                break;
            }
        }
        if(dy[l_idx] == dy[l_idx - 1] + dy[l_idx - 2] && dy[l_idx-1] == dy[l_idx - 2] + dy[l_idx-3] + 1) {
            int flag = 1;
            while(l_idx < N) {
                l_idx++;
                if(flag == 0) {
                    dy[l_idx] = dy[l_idx - 1] + dy[l_idx - 2];
                }
                else {
                    dy[l_idx] = dy[l_idx - 1] + dy[l_idx - 2] + 1; 
                }
                flag = (flag + 1) % 2;
            }
        }
        else if(dy[l_idx] == dy[l_idx-1] + dy[l_idx-2] +1 && dy[l_idx-1] == dy[l_idx-2] + dy[l_idx-3] + 1) {
            while(l_idx < N) {
                l_idx++;
                dy[l_idx] = dy[l_idx-1] + dy[l_idx-2] + 1;
            }
        }
        else {
            while(l_idx < N) {
                l_idx++;
                dy[l_idx] = dy[l_idx-1] + dy[l_idx-2];
            }
        }
        cout << "Case " << num++ << ": " << dy[N] << "\n";
    }
    
    
    
    
}