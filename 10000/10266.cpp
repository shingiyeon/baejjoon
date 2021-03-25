//# Author : nuclear852 ========================#
//# Solution : 24913778 ========================#
//# Time Stamp : 2021-01-04 22:42:54 ===========#
//# Problem Title : 시계 사진들 =================#
//# Language : C++17 ===========================#

#include <stdio.h>
#include <algorithm>
#include <vector>
using namespace std;

int tA[400001], tB[200001];
vector<int> A, B;
int N;
int pi[200001];
void make_failFunc() {
    int j = 0;
    for(int i=1; i<N-1; i++) {
        while(j>0 && B[i] != B[j]) {
            j = pi[j-1];
        }
        if(B[i] == B[j]) {
            pi[i] = ++j;
        }
    }
}

bool KMP() {
    int j = 0;
    for(int i=0; i<2*N-1; i++) {
        while(j>0 && A[i] != B[j]) {
            j = pi[j-1];
        }
        if(A[i] == B[j]) {
            if(j == N-2) return true;
            j++;
        }
    }
    return false;
}

int main() {
    scanf("%d", &N);
    for(int i=0; i<N; i++) scanf("%d", &tA[i]);
    for(int i=0; i<N; i++) scanf("%d", &tB[i]);
    for(int i=0; i<N; i++) {
        tA[i+N] = tA[i] + 360000;
    }
    sort(tA, tA+2*N);
    sort(tB, tB+N);
    for(int i=1; i<2*N; i++) {
        A.push_back(tA[i] - tA[i-1]);
    }
    for(int i=1; i<N; i++) {
        B.push_back(tB[i] - tB[i-1]);
    }

    make_failFunc();
    bool pos = KMP();
    if(pos) {
        printf("possible");
    }
    else {
        printf("impossible");
    }
}