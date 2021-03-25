//# Author : nuclear852 ========================#
//# Solution : 22237606 ========================#
//# Time Stamp : 2020-09-02 13:41:56 ===========#
//# Problem Title : 사탕상자 ===================#
//# Language : C++14 ===========================#

#include <stdio.h>
#include <algorithm>
typedef long long ll;
using namespace std;

int n;

int arr[1000001];
ll tree[4000001];

void update(int index, int start, int end, int cur, ll diff) {
	if(start <= cur && cur <= end) {
		tree[index] += diff;
	}
    else return;
	if(start == end) return;
	int mid = (start + end) / 2;
	update(index * 2, start , mid , cur, diff);
	update(index * 2 + 1, mid + 1 , end , cur, diff);
}

ll find(int index, int start, int end, ll val) {
	if(start >= end || start == 0 || end == 0){
        return start;
    }
    ll left_val = tree[index * 2];
    int mid = (start + end)/ 2;
    if(left_val >= val) {
        return find(index * 2, start, mid, val);
    }
    else {
        return find(index * 2 + 1, mid + 1, end, val - left_val);
    }
}


int main() {
	scanf("%d", &n);
	int a, k;
    ll b, c;
	for(int i=1; i<=n; i++){
		scanf("%d", &a);
		if(a==2) {
			scanf("%d%lld", &k, &c);
			update(1, 1, 1000000, k, c);
		}
		else {
			scanf("%lld", &b);
			int idx = find(1, 1, 1000000, b);
			printf("%d\n", idx);
			update(1, 1, 1000000, idx, -1);
		}
	}
}