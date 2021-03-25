//# Author : nuclear852 ========================#
//# Solution : 24811569 ========================#
//# Time Stamp : 2021-01-01 22:10:22 ===========#
//# Problem Title : 광고 =====================#
//# Language : C++17 ===========================#

#include <stdio.h>
#include <string>

using namespace std;

char tmp[1000005];
int pi[1000005];
string s;
int N;

void find_fail() {
    int j=0;
    for(int i=1; i<N; i++) {
        while(s[i] != s[j] && j > 0) {
            j = pi[j-1];
        }
        if(s[i] == s[j]) {
            pi[i] = ++j;
        }
    }
}

int main() {
    scanf("%d", &N);
    scanf("%s", tmp);
    s = tmp;
    find_fail();
    printf("%d", N-pi[N-1]);
}