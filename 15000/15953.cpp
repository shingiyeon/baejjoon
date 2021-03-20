#include <stdio.h>
int a[6] = {1, 3, 6, 10, 15, 21};
int b[5] = {1, 3, 7, 15, 31};
int wa[7] = {500, 300, 200, 50, 30, 10, 0};
int wb[6] = {512, 256, 128, 64, 32, 0};

int main(){
	int T; scanf("%d", &T);
	while(T--){
		int x, y; scanf("%d%d", &x,&y);
		int ranka= x==0? 6:0, rankb= y==0? 5:0;
		
		while(ranka<6 && x>a[ranka]) ranka++;
		while(rankb<6 && y>b[rankb]) rankb++;
		int tempa = ranka==6? 0 : wa[ranka];
		int tempb = rankb==5? 0 : wb[rankb];
		printf("%d\n", (tempa + tempb) * 10000);
	}
}
