//# Author : nuclear852 ========================#
//# Solution : 24696479 ========================#
//# Time Stamp : 2020-12-28 22:40:12 ===========#
//# Problem Title : 찾기 =====================#
//# Language : C++17 ===========================#

#include <stdio.h>
#include <vector>
#include <string>
using namespace std;

string T, P;

int pi[1000005];
vector<int> ans;

void find_failFunc(){
    int j = 0;
    for(int i=1; i < P.size(); i++) {
        while(j>0 && P[i] != P[j]) {
            j = pi[j-1];
        } 
        if(P[i] == P[j]) {
            pi[i] = ++j;
        }
    }
}

void find_ans() {
    int j = 0;
    for(int i=0; i < T.size(); i++) {
        while(P[j] != T[i] && j > 0) {
            j = pi[j-1];
        }
        if(T[i] == P[j]) {
            if(j == P.size()-1) {
                ans.push_back(i-P.size()+1);
                j = pi[j];
            }
            else {
                j++;
            }
        }
    }
}

int main() {
    char tmp[1000005];
    scanf("%[^\n]s", tmp);
    getchar();
    T = tmp;
    scanf("%[^\n]s", tmp);
    P = tmp;
    find_failFunc();
    find_ans();
    printf("%d\n", (int)ans.size());
    for(auto val: ans) {
        printf("%d ", val+1);
    }
}