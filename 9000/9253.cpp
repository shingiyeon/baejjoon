//# Author : nuclear852 ========================#
//# Solution : 25097713 ========================#
//# Time Stamp : 2021-01-09 22:44:09 ===========#
//# Problem Title : 스페셜 저지 =================#
//# Language : C++17 ===========================#

#include <stdio.h>
#include <string>

using namespace std;

string A, B, C;

int f[200005];

void make_failFunc() {
    int j = 0;
    for(int i = 1; i < C.size(); i++) {
        while( j > 0 && C[i] != C[j]) j = f[j-1];
        if(C[i] == C[j]) f[i] = ++j;
    }
} 

bool KMP(string P) {
    int j = 0;
    for(int i = 0 ; i < P.size(); i++) {
        while(j>0 && P[i] != C[j]) j = f[j-1];
        if(P[i] == C[j]) {
            ++j;
            if(j == C.size()) return 1;
        }
    }
    return false;
}

int main() {
    char tmp[200005];
    scanf("%s", tmp);
    A = tmp;
    scanf("%s", tmp);
    B = tmp;
    scanf("%s", tmp);
    C = tmp;
    make_failFunc();
    printf("%s", KMP(A) & KMP(B) == true ? "YES" : "NO");
}