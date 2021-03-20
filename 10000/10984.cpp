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
		printf("%d %.1f\n", s2, roundf(s/s2*10)/10);
	}
}
