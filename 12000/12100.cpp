//# Author : nuclear852 ========================#
//# Solution : 22914311 ========================#
//# Time Stamp : 2020-09-29 15:32:49 ===========#
//# Problem Title : 2048 (Easy) ============#
//# Language : C++14 ===========================#

#include <stdio.h>
#include <vector>
#include <queue>
#include <algorithm>
typedef long long ll;
using namespace std;

int N;
ll map[21][21];

struct State{
    ll v;
    ll m[21][21];
};

vector<ll> push_of_list(vector<ll> input) {
    vector<ll> temp;
    int i = 0;
    while(i<input.size()) {
        if(i + 1 == input.size()) break;
        int index = 1;
        for(index = 1; i + index < N; index++) {
            if(input[i+index]) break;
        }
        if(i + index != N) {
            if(input[i] == input[i+index]) {
                input[i] *= 2;
                input[i+index] = 0;
            }          
        }
        i = i + index;
    }

    for(int i=0; i<input.size(); i++) {
        if(input[i]) temp.push_back(input[i]);
    }

    return temp;
}

void clear_map(ll cur_map[][21]) {
    for(int i=0; i<N; i++) {
        for(int j=0; j<N; j++) {
            cur_map[i][j] = 0;
        }
    }
}

void print_map(ll cur_map[][21]) {
    for(int i=0; i<N; i++) {
        for(int j=0; j<N; j++) {
            printf("%lld ", cur_map[i][j]);
        }
        printf("\n");
    }
    printf("----------\n");
}

int main() {
    scanf("%d", &N);

    State S; S.v = 0;
    for(int i=0; i<N; i++) {
        for(int j=0; j<N; j++) {
            scanf("%lld", &S.m[i][j]);
            S.v = max(S.v, S.m[i][j]);
        }
    }
    long long ans = 0;
    queue<pair<State, int> > q;
    //print_map(S.m);
    q.push({S, 0});

    while(!q.empty()) {
        S = q.front().first;
        int repeat = q.front().second;
        q.pop();
        vector<ll> input;
        vector<ll> output;
        State temp;
        ans = max(ans, S.v);

        if(repeat == 5) continue;

        clear_map(temp.m);
        temp.v = 0;
        for(int i=0; i<N; i++) {
            input.clear();
            output.clear();
            for(int j=0; j<N; j++) input.push_back(S.m[i][j]);
            output = push_of_list(input);
            for(int j=0; j<N; j++) {
                if(j<output.size()) temp.m[i][j] = output[j];
                else temp.m[i][j] = 0;
                temp.v = max(temp.v, temp.m[i][j]);
            }
        }
        //print_map(temp.m);
        q.push({temp, repeat + 1});

        clear_map(temp.m);
        temp.v = 0;
        for(int i=0; i<N; i++) {
            input.clear();
            output.clear();
            for(int j=N-1; j>=0; j--) input.push_back(S.m[i][j]);
            output = push_of_list(input);
            for(int j=0; j<N; j++) {
                if(j<output.size()) temp.m[i][N-1-j] = output[j];
                else temp.m[i][N-1-j] = 0;
                temp.v = max(temp.v, temp.m[i][N-1-j]);
            }
        }
        //print_map(temp.m);
        q.push({temp, repeat + 1});

        clear_map(temp.m);
        temp.v = 0;
        for(int j=0; j<N; j++) {
            input.clear();
            output.clear();
            for(int i=0; i<N; i++) input.push_back(S.m[i][j]);
            output = push_of_list(input);
            for(int i=0; i<N; i++) {
                if(i<output.size()) temp.m[i][j] = output[i];
                else temp.m[i][j] = 0;
                temp.v = max(temp.v, temp.m[i][j]);
            }
        }
        //print_map(temp.m);
        q.push({temp, repeat + 1});

        clear_map(temp.m);
        temp.v = 0;
        for(int j=0; j<N; j++) {
            input.clear();
            output.clear();
            for(int i=N-1; i>=0; i--) input.push_back(S.m[i][j]);
            output = push_of_list(input);
            for(int i=0; i<N; i++) {
                if(i<output.size()) temp.m[N-1-i][j] = output[i];
                else temp.m[N-1-i][j] = 0;
                temp.v = max(temp.v, temp.m[N-1-i][j]);
            }
        }
        //print_map(temp.m);
        q.push({temp, repeat + 1});

    }
    printf("%lld", ans);
}