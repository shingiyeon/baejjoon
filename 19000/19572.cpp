//# Author : nuclear852 ========================#
//# Solution : 22833784 ========================#
//# Time Stamp : 2020-09-25 22:46:12 ===========#
//# Problem Title : 가뭄(Small) ==============#
//# Language : C++14 ===========================#

#include <stdio.h>
using namespace std;

int main() {
	int d1, d2, d3;
	scanf("%d%d%d", &d1, &d2, &d3);
	double a, b, c;
	
	a = (double)(d1 + d2 - d3) / 2;
	b = (double)(d1 - d2 + d3) / 2;
	c = (double)(-d1 + d2 + d3) / 2;
	if(a <= 0 || b <= 0 || c <= 0) {
		printf("-1"); return 0;
	}
	else {
		printf("1\n");
		printf("%.1lf %.1lf %.1lf", a, b, c);
	}
}