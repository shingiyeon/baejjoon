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

long double p[6][3];

int getProbIdx(int A, int B) {
    if(A == 0) {
        return B - 1;
    } else if(A == 1) {
        return 3 + B - 2;
    } else if(A == 2) {
        return 5;
    }
}

pair<int, int> getCountryIdx(int idx) {
    if(idx < 3) {
        return {0, idx + 1};
    } else if(idx < 5) {
        return {1, idx - 1};
    } else {
        return {2, 3};
    }
}

vector<long double> getPrediction(long double prob, vector<int> results) {
    

    if(results.size() == 6) {
        pair<int, int> scores[4];
        for(int i=0; i<4; i++) {
            scores[i].second = i;
            scores[i].first = 0;
        }
        
        for(int i=0; i<6; i++) {
            pair<int, int> p = getCountryIdx(i);
            int A = p.first;
            int B = p.second;
            if( results[i] == 0 ) {
                scores[A].first += 3;
            } else if(results[i] == 1) {
                scores[A].first++; scores[B].first++;
            } else {
                scores[B].first += 3;
            }
        }

        sort(scores, scores + 4, greater<>());
        vector<long double> p(4);
        if(scores[0].first == scores[3].first) {
            for(int i=0; i<4; i++) {
                p[scores[i].second] = prob * ((long double)1/2);
            }
        } else if(scores[0].first == scores[2].first) {
            for(int i=0; i<3; i++) {
                p[scores[i].second] = prob * ((long double)2/3);
            }
            p[scores[3].second] = 0;
        } else if(scores[1].first == scores[3].first) {
            p[scores[0].second] = prob;
            for(int i=1; i<4; i++) {
                p[scores[i].second] = prob * ((long double)1/3);
            }
        } else if(scores[1].first == scores[2].first) {
            p[scores[0].second] = prob;
            for(int i=1; i<3; i++) {
                p[scores[i].second] = prob * ((long double)1/2);
            }
            p[scores[3].second] = 0;
        } else {
            p[scores[0].second] = p[scores[1].second] = prob;
            p[scores[2].second] = p[scores[3].second] = 0;
        }
        // if(prob > 0) {
        //     for(auto info: scores) {
        //         cout << info.first << " " << info.second << "\n";
        //     }
        //     for(auto val: p) {
        //         cout << val << " ";
        //     }
        //     cout << "\n";
        // }
        return p;
    }
    vector<long double> result(4, 0);

    for(int i=0; i<3; i++) {
        results.push_back(i);
        // if(p[(int)(results.size()-1)][i] > 0) {
        //     cout << "choosen result: ";
        //     for(int result: results) {
        //         cout << result << " ";
        //     }
        //     cout << "prob: " << prob << "\n";
        // }
        vector<long double> v = getPrediction(prob * p[(int)(results.size() - 1)][i], results);
        for(int j=0; j<4; j++) {
            result[j] += v[j];
        }
        results.pop_back();
    }

    return result;
}

int main() {
    cin.tie(NULL);
    cout.tie(NULL);
    ios::sync_with_stdio(false);

    map<string, int> m;
    string country[4];
    for(int i=0; i<4; i++) {
        cin >> country[i];
        m.insert({country[i], i});
    }

    for(int i=0; i<6; i++) {
        string A, B; cin >> A >> B;
        long double W, D, L;
        int Aidx = m.find(A)->second;
        int Bidx = m.find(B)->second;
        cin >> W >> D >> L;
        if(Aidx > Bidx) {
            swap(A, B); swap(Aidx, Bidx);
            swap(W, L);
        }
        p[getProbIdx(Aidx, Bidx)][0] = W;
        p[getProbIdx(Aidx, Bidx)][1] = D;
        p[getProbIdx(Aidx, Bidx)][2] = L;
    }

    // for(int i=0; i<6; i++) {
    //     pair<int, int> c = getCountryIdx(i);
    //     cout << c.first << " " << c.second << " ";
    //     for(int j=0; j<3; j++) {
    //         cout << p[i][j] << " ";
    //     }
    //     cout << "\n";
    // }

    vector<long double> res = getPrediction((long double)1, {});
    for(int i=0; i<4; i++) cout << res[i] << "\n";
}