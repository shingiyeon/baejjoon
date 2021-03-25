//# Author : nuclear852 ========================#
//# Solution : 24813983 ========================#
//# Time Stamp : 2021-01-01 23:16:40 ===========#
//# Problem Title : 문자열 제곱 =================#
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
    for(int i=1; i<s.size(); i++) {
        while(s[i] != s[j] && j > 0) {
            j = pi[j-1];
        }
        if(s[i] == s[j]) {
            pi[i] = ++j;
        }
    }
}

int main() {
    scanf("%s", tmp);
    while(tmp[0] != '.') {
        s = tmp;
        for(int i=0; i<1000005; i++) pi[i] = 0;
        find_fail();
        if(s.size() % (s.size() - pi[s.size()-1]) == 0) {
            printf("%d\n", (int)s.size() / ((int)s.size() - pi[s.size()-1]));
        }
        else {
            printf("1\n", (int)s.size());
        }
        scanf("%s", tmp);
    }
}