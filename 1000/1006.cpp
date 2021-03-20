#include <stdio.h>
#define MAX 999999999
int a[2][10000];
int dy[10000][5];
int N, W;
int min(int a, int b){return a<b? a:b;}
void dyi(){
	for(int i=0; i<N; i++){
		for(int j=0; j<5; j++)
			dy[i][j] = MAX;
	}
}

int dyp(int num){
	int tempmin;
	
	if(num==3) dy[0][num] = 1;
	else if(num==0||num==1||num==2||num==4) dy[0][num] = 2;
	
	for(int i=1; i<N; i++){
		//0
		tempmin = MAX;
		tempmin = min(tempmin, dy[i-1][0]+2);
		tempmin = min(tempmin, dy[i-1][3]+2);
		tempmin = min(tempmin, dy[i-1][4]+2);
		tempmin = min(tempmin, dy[i-1][1]+2);
		tempmin = min(tempmin, dy[i-1][2]+2);
		dy[i][0] = tempmin;
		
		//1
		tempmin = MAX;
		if(a[1][i] + a[1][i-1] <= W){
			tempmin = min(tempmin, dy[i-1][0]+1);
			tempmin = min(tempmin, dy[i-1][2]+1);
		}
		dy[i][1] = tempmin;
		
		//2
		tempmin = MAX;
		if(a[0][i] + a[0][i-1] <= W){
			tempmin = min(tempmin, dy[i-1][0]+1);
			tempmin = min(tempmin, dy[i-1][1]+1);
		}
		dy[i][2] = tempmin;
		
		//3
		tempmin = MAX;
		if(a[0][i] + a[1][i] <= W){
			tempmin = min(tempmin, dy[i-1][0]+1);
			tempmin = min(tempmin, dy[i-1][1]+1);
			tempmin = min(tempmin, dy[i-1][2]+1);
			tempmin = min(tempmin, dy[i-1][3]+1);
			tempmin = min(tempmin, dy[i-1][4]+1);
		}
		dy[i][3] = tempmin;
		
		//4
		tempmin = MAX;
		if(a[0][i] + a[0][i-1] <= W && a[1][i] + a[1][i-1]<=W){
			tempmin = min(tempmin, dy[i-1][0]);
		}
		dy[i][4] = tempmin;
		//printf("i:%d / %d %d %d %d %d\n",i,dy[i][0],dy[i][1],dy[i][2],dy[i][3],dy[i][4]);
	}
	if(num==0 || num==3)
		return min(dy[N-1][0], min(dy[N-1][1], min(dy[N-1][2], min(dy[N-1][3], dy[N-1][4]))));
	else if(num==1)
		return min(dy[N-1][0], dy[N-1][2])-1;
	else if(num==2)
		return min(dy[N-1][0], dy[N-1][1])-1;
	else
		return dy[N-1][0]-2;
}

int main(){
	int T; scanf("%d", &T);
	while(T--){
		scanf("%d%d",&N,&W);
		for(int j=0; j<2; j++){
			for(int i=0; i<N; i++){
				scanf("%d", &a[j][i]);
			}
		}
		int MIN = MAX;
		dyi();
		MIN = min(MIN, dyp(0));
		dyi();
		if( (a[1][0] + a[1][N-1] <= W) && N>=2)
			MIN = min(MIN, dyp(1));
		dyi();
		if( (a[0][0] + a[0][N-1] <= W) && N>=2)
			MIN = min(MIN, dyp(2));
		dyi();
		if( (a[0][0] + a[1][0]) <= W)
			MIN = min(MIN, dyp(3));
		dyi();
		if(N>=2&&(a[0][0] + a[0][N-1] <= W) && (a[1][0] + a[1][N-1] <= W))
			MIN = min(MIN, dyp(4));
		printf("%d\n", MIN);
	}
}

