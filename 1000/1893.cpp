//# Author : nuclear852 ========================#
//# Solution : 25107168 ========================#
//# Time Stamp : 2021-01-10 09:23:16 ===========#
//# Problem Title : 시저 암호 ==================#
//# Language : C++17 ===========================#

#include <stdio.h>
#include <string>
#include <map>
#include <vector>
using namespace std;

int f[50005];
char dic[65];
char ori[50005];
char enc[500005];
map<char, int> rm;
string S, P;

void make_failFunc() {
    int j = 0;
    for(int i = 1; i < P.size(); i++) {
        while(j>0 && P[i] != P[j]) j = f[j-1];
        if(P[i] == P[j]) f[i] = ++j;
    }
}

bool KMP() {
    int ans = 0;

    int j = 0;
    for(int i = 0; i < S.size(); i++) {
        while(j>0 && S[i] != P[j]) j = f[j-1];
        if(S[i] == P[j]) {
            ++j;
            if(j == P.size()) {
                ans++;
                j = f[j-1];
            }
        }
    }
    if(ans == 1) return true;
    return false;
}

int main() {
    int T; scanf("%d", &T);
    while(T--) {
        scanf("%s", dic);
        vector<int> ans;

        int size = 0;
        for(size = 0 ; dic[size] != '\0'; size++) {
            rm[dic[size]] = size;
        }

        scanf("%s", ori);
        scanf("%s", enc);
        S = enc;

        for(int i=0; i<size; i++) {
            string tmp = ori;
            for(int j = 0; j<50005; j++) f[j] = 0;
            for(int j = 0; ori[j] != '\0'; j++) {
                tmp[j] = dic[(rm[ori[j]] + i) % size];
            }
            
            P = tmp;
            make_failFunc();
            if(KMP()) ans.push_back(i);
        }
        if(ans.size() == 0) {
            printf("no solution\n");
        }
        else if(ans.size() == 1) {
            printf("unique: %d\n", ans[0]);
        }
        else {
            printf("ambiguous: ");
            for(auto val: ans) {
                printf("%d ", val);
            }
            printf("\n");
        }
    }
}