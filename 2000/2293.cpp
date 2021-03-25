//# Author : nuclear852 ========================#
//# Solution : 11303637 ========================#
//# Time Stamp : 2019-01-10 22:28:23 ===========#
//# Problem Title : 동전 1 ===================#
//# Language : C++98 ===========================#

#include <stdio.h>
#include <iostream>
int main() {
	int K, N;
	scanf("%d%d", &K, &N);
	int dy[10001];
	int coin[101];
	for (int i = 1; i <= N; i++) {
		dy[i] = 0;
	}
	dy[0] = 1;
	for (int i = 1; i <= K; i++)
		scanf("%d", &coin[i]);
	for (int i = 1; i <= K; i++)
	{
		for (int j = 1; j <= N; j++) {
			if (j >= coin[i])
				dy[j] += dy[j - coin[i]];
		}
	}
	printf("%d", dy[N]);
}