//# Author : nuclear852 ========================#
//# Solution : 24962036 ========================#
//# Time Stamp : 2021-01-06 09:37:12 ===========#
//# Problem Title : 바이러스 ===================#
//# Language : C++17 ===========================#

#include <stdio.h>
#include <vector>
using namespace std;


vector<int> v[101];
int N, K;
int f[1001];

vector<int> make_failFunc(vector<int> S) {
    for(int i=0; i<=1000; i++) f[i] = 0;
    int j = 0;
    for(int i=1; i<S.size(); i++) {
        while(S[i] != S[j] && j > 0) j = f[j-1];
        if(S[i] == S[j]) f[i] = ++j;
    }
    return S;
}

bool KMP(vector<int> P, vector<int> S) {
    int j = 0;
    for(int i=0; i<P.size(); i++) {
        while(P[i] != S[j] && j > 0) j = f[j-1];
        if(P[i] == S[j]) {
            ++j;
            if(j == S.size()) return true;
        }
    }
    return false;
}

vector<int> rev(vector<int> P) {
    vector<int> tmp;
    for(int i=P.size()-1; i>=0; i--) {
        tmp.push_back(P[i]);
    }
    return tmp;
}

void print(vector<int> v) {
    for(auto val: v) {
        printf("%d ", val);
    }
    printf("\n");
}

int main() {
    scanf("%d%d", &N, &K);
    for(int i=0; i<N; i++) {
        int size; scanf("%d", &size);
        for(int j=0; j<size; j++) {
            int tmp; scanf("%d", &tmp);
            v[i].push_back(tmp);
        }
    }

    bool ans = false;
    for(int i=0; i<=v[0].size()-K; i++) {
        vector<int> ref;
        for(int j=i; j<i+K; j++) {
            ref.push_back(v[0][j]);
        }
        make_failFunc(ref);

        int pos = true;
        for(int j=1; j<N; j++) {
            vector<int> rev_v = rev(v[j]);
            pos &= (KMP(rev_v, ref) | KMP(v[j], ref));
        }
        ans |= pos;
    }
    printf("%s", ans ? "YES" : "NO");
}