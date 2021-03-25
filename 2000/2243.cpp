//# Author : nuclear852 ========================#
//# Solution : 22237611 ========================#
//# Time Stamp : 2020-09-02 13:42:10 ===========#
//# Problem Title : 사탕상자 ===================#
//# Language : C++14 ===========================#

#include <stdio.h>
#include <algorithm>
typedef long long ll;
using namespace std;

int n;

int arr[1000001];
int tree[3000001];

void update(int index, int start, int end, int cur, int diff) {
	if(start <= cur && cur <= end) {
		tree[index] += diff;
	}
    else return;
	if(start == end) return;
	int mid = (start + end) / 2;
	update(index * 2, start , mid , cur, diff);
	update(index * 2 + 1, mid + 1 , end , cur, diff);
}

int find(int index, int start, int end, int val) {
	if(start >= end || start == 0 || end == 0){
        return start;
    }
    int left_val = tree[index * 2];
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
	int a, b, c;
	for(int i=1; i<=n; i++){
		scanf("%d", &a);
		if(a==2) {
			scanf("%d%d", &b, &c);
			update(1, 1, 1000000, b, c);
		}
		else {
			scanf("%d", &b);
			int idx = find(1, 1, 1000000, b);
			printf("%d\n", idx);
			update(1, 1, 1000000, idx, -1);
		}
	}
}