//# Author : nuclear852 ========================#
//# Solution : 24846672 ========================#
//# Time Stamp : 2021-01-02 23:31:40 ===========#
//# Problem Title : 속타는 저녁 메뉴 ==============#
//# Language : C++17 ===========================#

#include <stdio.h>
#include <string>
#include <vector>
using namespace std;
int N;
string S, P;
int f[1000001];
vector<int> ans;

int gcd(int a, int b) {
    while(a%b) {
        int tmp = a % b;
        a = b;
        b = tmp;
    }
    return b;
}

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

void KMP() {
    int j = 0;
    for(int i=0; i<S.size(); i++) {
        while(j>0 && S[i] != P[j]) {
            j = f[j-1];
        }
        if(S[i] == P[j]) {
            if(j == P.size()-1) {
                j = f[j];
                ans.push_back(i - P.size() + 1);
            }
            else {
                j++;
            }
        }
    }
}

int main() {
    scanf("%d", &N);
    char A[2000100];
    for(int i=0; i<N; i++) {
        scanf(" %c", &A[i]);
    }
    for(int i=0; i<N; i++) {
        A[i+N] = A[i];
    }
    A[2*N] = 0;
    S = A;
    for(int i=0; i<N; i++) {
        scanf(" %c", &A[i]);
    }
    A[N] = 0;
    P = A;
    make_failFunc();
    KMP();
    int num = 0;
    for(auto val: ans) {
        if(val < N) num++;
    }
    int g = gcd(N, num);
    printf("%d/%d", num/g, N/g);
}