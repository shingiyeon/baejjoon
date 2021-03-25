//# Author : nuclear852 ========================#
//# Solution : 22509005 ========================#
//# Time Stamp : 2020-09-12 23:42:16 ===========#
//# Problem Title : 연속합 2 ==================#
//# Language : C++14 ===========================#

#include <stdio.h>
#include <algorithm>
typedef long long ll;
using namespace std;
int N;
ll arr[100001];
ll dy[100001][2];

int main() {
	scanf("%d", &N);
	for(int i=1; i<=N; i++) {
		scanf("%lld", &arr[i]);
	}
	dy[1][0] = arr[1];
	dy[1][1] = arr[1];
	
	for(int i=2; i<=N; i++) {
		dy[i][0] = max(arr[i], arr[i] + dy[i-1][0]);
		dy[i][1] = max(dy[i-1][0], dy[i-1][1] + arr[i]);
	}
	ll ans = -100000000;
	for(int i=1; i<=N; i++) {
		ans = max(ans, dy[i][0]);
		ans = max(ans, dy[i][1]);
	}
	printf("%lld", ans);
}