//# Author : nuclear852 ========================#
//# Solution : 25964407 ========================#
//# Time Stamp : 2021-02-02 22:46:52 ===========#
//# Problem Title : List of Unique Numbers =#
//# Language : C++17 ===========================#

#include <iostream>
using namespace std;

int arr[101010];
int cnt[101010];
int N;
int main() {
	cin.tie(NULL); cout.tie(NULL);
	ios::sync_with_stdio(false);
	
	cin >> N;
	for(int i=0; i<N; i++) cin >> arr[i];
	int s = 0, e = 0;
	long long ans = 0;
	while(e < N){
		cnt[arr[e]]++;
		while(cnt[arr[e]] >= 2) {
			ans += (long long)(e - s);
			cnt[arr[s]]--;
			s++;
		}
		e++;
	}
	ans += (long long) (N-s)*(N-s+1) / 2;
	
	cout << ans;
	
	return 0;
}