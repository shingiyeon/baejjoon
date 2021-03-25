//# Author : nuclear852 ========================#
//# Solution : 24916210 ========================#
//# Time Stamp : 2021-01-04 23:34:29 ===========#
//# Problem Title : 나는 친구가 적다 (Large) ======#
//# Language : C++17 ===========================#

#include <stdio.h>
#include <string>

using namespace std;

string S = "", K = "";
int f[200001];
void make_failFunc() {
    int j = 0;
    for(int i = 1; i < K.size(); i++) {
        while(j>0 && K[i] != K[j]) {
            j = f[j-1];
        }
        if(K[i] == K[j]) {
            f[i] = ++j;
        }
    }
}

bool KMP() {
    int j = 0;
    for(int i = 0; i < S.size(); i++) {
        while(j>0 && S[i] != K[j]) {
            j = f[j-1];
        }
        if(S[i] == K[j]) {
            j++;
            if(j == K.size()) return true;
        }
    }
    return false;
}

int main(){
    char tmp[200005];
    scanf("%s", tmp);
    for(int i=0; tmp[i] != '\0'; i++) {
        if('0' <= tmp[i] && tmp[i] <= '9') {
            continue;
        }
        S += tmp[i];
    }
    scanf("%s", tmp);
    K = tmp;
    make_failFunc();
    printf("%d", KMP());
}