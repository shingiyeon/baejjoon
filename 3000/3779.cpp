//# Author : nuclear852 ========================#
//# Solution : 26155234 ========================#
//# Time Stamp : 2021-02-08 11:23:44 ===========#
//# Problem Title : 주기 =====================#
//# Language : C++17 ===========================#

#include <iostream>
#include <vector>
#include <string>
#include <utility>
using namespace std;

vector<int> make_failFunc(string p) {
    vector<int> fail(p.size());
    int j=0;
    for(int i=1; i<p.size(); i++) {
        while(j && p[i] != p[j]) j = fail[j-1];
        if(p[i] == p[j]) fail[i] = ++j; 
    }
    return fail;
}

int main() {
    cin.tie(NULL); cout.tie(NULL);
    ios::sync_with_stdio(false);
    int num; string str;
    int idx = 1;
    cin >> num;
    while(num != 0) {
        cin >> str;
        vector<int> fail = make_failFunc(str);
        vector<pair<int, int> > ans;
        for(int i=0; i<fail.size(); i++) {
            if(fail[i]) {
                if( (i+1) % (i+1 - fail[i]) == 0 ) {
                    ans.push_back({i+1, (i+1)/ (i+1 -fail[i])});
                }
            }
        }
        cout << "Test case #" << idx << "\n";
        for(auto val: ans) {
            cout << val.first << " " << val.second << "\n";
        }
        cout << "\n";
        idx++; cin >> num;
    }

}