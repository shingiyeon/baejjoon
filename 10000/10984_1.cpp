//# Author : nuclear852 ========================#
//# Solution : 11585793 ========================#
//# Time Stamp : 2019-01-30 03:42:11 ===========#
//# Problem Title : 내 학점을 구해줘 ==============#
//# Language : C++98 ===========================#

#include <stdio.h>
#include <math.h>
int main(){
	int T; scanf("%d",&T);
	float a[2][10];
	while(T--){
		int N; scanf("%d", &N);
		float s = 0; int s2 = 0;
		for(int i=0; i<N; i++){
			scanf("%f%f",&a[0][i],&a[1][i]);
			s += a[1][i] * a[0][i]; s2 += a[0][i];
		}
		if(int(s*100)%10>=5) s += 0.1*s2;
		printf("%d %.1f\n", s2, s/s2);
	}
}