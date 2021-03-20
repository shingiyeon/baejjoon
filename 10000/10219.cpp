#include <stdio.h>
int main(){
	int T; scanf("%d",&T);
	while(T--){
		char map[11][11]; int H,W; scanf("%d%d",&H,&W);
		for(int i=0; i<H; i++){
			scanf("%s", map[i]);
			//getchar();
		}
		for(int i=0; i<H; i++){
			for(int j=W-1; j>=0; j--)
				printf("%c", map[i][j]);
			printf("\n");
		}
	}
}
