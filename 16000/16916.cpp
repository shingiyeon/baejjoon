//# Author : nuclear852 ========================#
//# Solution : 24845990 ========================#
//# Time Stamp : 2021-01-02 23:15:35 ===========#
//# Problem Title : 부분 문자열 =================#
//# Language : C++17 ===========================#

#include <stdio.h>
#include <string>
using namespace std;
string S, P;
int f[1000001];
void make_failFunc() {
    int j = 0;
    for(int i=1; i<P.size(); i++) {
        while(j>0 && P[i] != P[j]) {
            j = f[j-1];
        }
        if(P[i] == P[j]) {
            f[i] = ++j;
        }
    }
}

bool KMP() {
    int j = 0;
    for(int i=0; i<S.size(); i++) {
        while(j>0 && S[i] != P[j]) {
            j = f[j-1];
        }
        if(S[i] == P[j]) {
            if(j == P.size()-1) {
                return true;
            }
            else {
                j++;
            }
        }
    }
    return false;
}

int main() {
    char tmp[1000005];
    scanf("%s", tmp);
    S = tmp;
    scanf("%s", tmp);
    P = tmp;
    make_failFunc();
    printf("%d", KMP());
}