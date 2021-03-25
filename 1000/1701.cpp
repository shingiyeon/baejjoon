//# Author : nuclear852 ========================#
//# Solution : 24789259 ========================#
//# Time Stamp : 2020-12-31 23:57:35 ===========#
//# Problem Title : Cubeditor ==============#
//# Language : C++17 ===========================#

#include <stdio.h>
#include <string>
#include <algorithm>

using namespace std;

string s;
int ans = 0;
int pi[5005];
void find() {
    for(int i=0; i<5005; i++) pi[i] = 0;
    int j=0;
    for(int i=1; i<s.size(); i++) {
        while(j>0 && s[i] != s[j]) {
            j = pi[j-1];
        }
        if(s[i] == s[j]) {
            pi[i] = ++j;
            ans = max(ans, pi[i]);
        }
    }
}
int main() {
    char temp[5005];
    scanf("%s", temp);
    s = temp;
    int num = s.size();
    for(int i=0; i<num; i++) {
        find();
        s = s.substr(1);
    }
    printf("%d", ans);
}