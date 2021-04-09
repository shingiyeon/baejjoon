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

class KMP {

private:
    vector<int> fail;
    string f;

public:
    KMP(string _f) {
        f = _f;
        fail.resize((int)f.size(), 0);
    }

    vector<int> getFail() {
        return fail;
    }

    void makeFail() {
        int j = 0;
        for(int i=1; i<f.size(); i++) {
            while(j > 0 && f[i] != f[j]) {
                j = fail[j-1];
            }
            if(f[i] == f[j]) {
                fail[i] = ++j;
            }
        }
    }

    vector<int> findString(string s) {
        vector<int> ans;
        int j = 0;
        for(int i=0; i<s.size(); i++) {
            while(j > 0 && f[j] != s[i]) j = fail[j-1];
            if(f[j] == s[i]) {
                ++j;
                if(j == f.size()) {
                    ans.push_back(j - f.size());
                    j = fail[j-1];
                }
            }
        }
        return ans;
    }
};

int main() {
    string str; cin >> str;
    KMP *kmp = new KMP(str);
    kmp->makeFail();
    auto fail = kmp->getFail();
    for(int i=1; i<fail.size(); i++) {
        if( ((i+1) % (i+1-fail[i])) == 0 && fail[i] > 0) {
            cout << i+1 << " " << (i+1) / (i+1-fail[i]) << "\n";
        }
    }
    
    delete kmp;
}