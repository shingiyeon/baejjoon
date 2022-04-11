#include <iostream>
#include <math.h>
#include <vector>
#include <algorithm>
#include <map>
#include <unordered_map>
#include <set>
#include <unordered_set>
#include <functional>
#include <queue>
#include <stack>
#include <string>
using namespace std;

vector<int> getFailFunc(string s) {
    vector<int> f(s.length(), 0);
    int j = 0;
    for(int i = 1; i < s.length(); i++) {
        while(j > 0 && s[i] != s[j]) j = f[j-1];
        if(s[i] == s[j]) f[i] = ++j; 
    }
    return f;
}
int main() {
    cin.tie(NULL);
    cout.tie(NULL);
    ios::sync_with_stdio(false);

    int N, n;
    vector< string > vs;
    vector< vector<int> > vf;
    string S;
    queue<int> qs[100];
    queue<int> qe[100];

    cin >> N;
    vector<int> idx(N, 0);
    for(int i=0; i<N; i++) {
        cin >> n >> S;
        vs.push_back(S);
        vf.push_back(getFailFunc(S));
    }
    cin >> n >> S;

    // for(int i=0; i<vf.size(); i++) {
    //     for(auto val: vf[i]) {
    //         cout << val << " ";
    //     }
    //     cout << "\n";
    // }

    // for(auto val: vs) {
    //     cout << val << "\n";
    // }
    // cout << S << "\n";
    for(int i=0; i<S.length(); i++) {
        for(int j=0; j<N; j++) {
            while(idx[j] > 0 && vs[j][idx[j]] != S[i]) idx[j] = vf[j][idx[j] - 1];
            if(vs[j][idx[j]] == S[i]) {
                idx[j]++;
                if(idx[j] == vs[j].length()) {
                    qs[j].push(i - vs[j].length() + 1);
                    qe[j].push(i);
                    idx[j] = vf[j][idx[j] - 1];
                }
            }
        }
    }

    // for(int j=0; j<N; j++) {
    //     while(!qs[j].empty()) {
    //         cout << qs[j].front() << " " << qe[j].front() << "\n";;
    //         qs[j].pop(); qe[j].pop();
    //     }
    // }


    int answer = S.length();
    int r = 0;
    for(int l=0; l<S.length(); l++) {
        int num = 0;
        for(int j=0; j<N; j++) {
            while(!qs[j].empty() && l > qs[j].front()) {
                qs[j].pop();
                qe[j].pop();
            }
            if(!qs[j].empty() && l <= qs[j].front()) {
                num++;
            }
            r = max(r, qe[j].front());
        }
        if(num == N) {
            answer = min(answer, r - l + 1);
        }
        // cout << l << " " << r << "\n";
    }
    cout << answer;

}