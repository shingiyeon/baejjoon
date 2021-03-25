//# Author : nuclear852 ========================#
//# Solution : 23577809 ========================#
//# Time Stamp : 2020-11-01 01:29:50 ===========#
//# Problem Title : 수열과 쿼리 0 ===============#
//# Language : C++17 ===========================#

#include <bits/stdc++.h>
using namespace std;

const int sq = 400;
const int sz = 202020/sq + 10;

struct Query {
    int left, right, index;
    Query() {}
    Query(int left, int right, int index): left(left), right(right), index(index) {}
    bool operator < (const Query &t) const {
    	if(left/sq != t.left/sq) return left < t.left;
    	return right < t.right;
    }
};

int N, M;
int arr[202020];
vector<Query> Q;

list<int> pos[202020];
int bket[202020], Sbket[sz];
int ans[202020];

void Plus(int x, int dir){
	int now = 0;
	auto &dq = pos[arr[x]];
	if(!dq.empty()){
		now = dq.back() - dq.front();
		bket[now]--;
		Sbket[now/sq]--;
	}
	if(!dir) dq.push_front(x);
	else dq.push_back(x);
	now = dq.back() - dq.front();
	bket[now]++; Sbket[now/sq]++;
}

void Minus(int x, int dir){
	auto &dq = pos[arr[x]];
	int now = dq.back() - dq.front();
	bket[now]--; Sbket[now/sq]--;
	if(!dir) dq.pop_front();
	else dq.pop_back();
	if(!dq.empty()){
		now = dq.back() - dq.front();
		bket[now]++; Sbket[now/sq]++;
	}
}

int find_ans(){
	for(int i=sz-1; i>=0; i--){
		if(Sbket[i] == 0) continue;
		for(int j=sq-1; j>=0; j--){
			if(bket[i*sq+j] > 0){
				return i*sq+j;
			}
		}
	}
	return 0;
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    cin >> N;
    for(int i=1; i<=N; i++) cin >> arr[i];
	for(int i=1; i<=N; i++) arr[i] += arr[i-1];
	for(int i=0; i<=N; i++) arr[i] += 100000;
    cin >> M;
    for(int i=0; i<M; i++) {
        int l, r; cin >> l >> r;
        Q.push_back({l-1, r, i});
    }
    sort(Q.begin(), Q.end());
    
    int left = Q[0].left, right = Q[0].right, x = Q[0].index;
    for(int i=left; i<=right; i++) {
        Plus(i, 1);
    }
    ans[x] = find_ans();
    
    for(int i=1; i<M; i++) {
        x = Q[i].index;
        while(Q[i].left < left) Plus(--left, 0); 
        while(Q[i].right > right) Plus(++right, 1);
        while(Q[i].left > left) Minus(left++, 0);
        while(Q[i].right < right) Minus(right--, 1);
        ans[x] = find_ans();
    }
    
    for(int i=0; i<M; i++) cout << ans[i] << "\n";
}