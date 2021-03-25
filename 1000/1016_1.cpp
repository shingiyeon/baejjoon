//# Author : nuclear852 ========================#
//# Solution : 11409919 ========================#
//# Time Stamp : 2019-01-18 02:44:52 ===========#
//# Problem Title : 제곱 ㄴㄴ 수 ================#
//# Language : C++98 ===========================#

#include <stdio.h>
bool visited[1000002];
int main()
{
	long long a, b;
	scanf("%lld%lld",&a,&b);
	for (long long j = 2; j*j<=b; j++)
	{
		long long temp = (a%(j*j)==0) ? (a/(j*j)) : (a/(j*j)+1);
		for(long long i = temp; j*j*i<=b; i++){
			visited[j*j*i-a] = 1;
		}
	}
	
	int ans = 0;
	for(long long i = a; i <= b; i++){
		if(!visited[i-a]) ans++;
	}
	
	printf("%d\n",ans);
	
}