//# Author : nuclear852 ========================#
//# Solution : 25964706 ========================#
//# Time Stamp : 2021-02-02 22:53:08 ===========#
//# Problem Title : 배열 합치기 =================#
//# Language : C++17 ===========================#

#include <iostream>
#include <vector>
using namespace std;
vector<int> ans, A, B;
int main() {
	cin.tie(NULL); cout.tie(NULL);
	ios::sync_with_stdio(false);
	int N, M; cin >> N >> M;
	int tmp;
	for(int i=0; i<N; i++) {
		cin >> tmp; A.push_back(tmp);
	}
	for(int i=0; i<M; i++) {
		cin >> tmp; B.push_back(tmp);
	}
	
	int As = 0, Bs = 0;
	while(As < N && Bs < M) {
		if(A[As] < B[Bs]) ans.push_back(A[As++]);
		else ans.push_back(B[Bs++]);
	}
	while(As < N) ans.push_back(A[As++]);
	while(Bs < M) ans.push_back(B[Bs++]);
	for(auto val: ans) cout << val << " ";
	return 0;
}