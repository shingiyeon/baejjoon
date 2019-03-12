#include <stdio.h>
int n;
int map[20][20];
int arr[400];
int number[1001];

bool make(int size, int x, int y, int o_size){
	bool pos = 0;
	if(size == 1){
		pos = 0;
		for(int i=2; i<=o_size; i++){
			for(int j=1; j<=1000; j++){
				if(number[j]>=2){
					map[x+ (i%2==0) * (i/2)][y + (i%2==1) * (i/2)] = j;
					map[x- (i%2==0) * (i/2)][y - (i%2==1) * (i/2)] = j;
					number[j] -= 2;
					pos = 1;
					break;
				}
			}
			if(!pos) return 0;
		}
		pos = 0;
		for(int i=1; i<=1000; i++){
			if(number[i]){
				map[x][y] = i;
				pos = 1;
				break;
			}
		}
		if(!pos) return 0;
		return 1;
	}
	
	if(size == 2){
		pos = 0;
		for(int i=1; i<=1000; i++){
			if(number[i]>=4){
				map[x][y] = i;
				map[x+1][y+1] = i;
				map[x][y+1] = i;
				map[x+1][y] = i;
				pos = 1;
				break;
			}
		}
		if(!pos) return 0;
		return 1;	
	}
	
	int t_size = size - 2;
	/// x,y  x+size-1 y+size-1
	pos = 0;
	for(int i=1; i<=1000; i++){
		if(number[i]>=4){
			map[x][y] = i;
			map[x+size-1][y] = i;
			map[x][y+size-1] = i;
			map[x+size-1][y+size-1] = i;
			number[i] -= 4;
			pos = 1;
			break;
		}
	}
	if(!pos) return 0;
	//garo
	for(int i=1; i<=(t_size)/2; i++){
		pos = 0;
		for(int j=1; j<=1000; j++){
			if(number[j]>=4){
				map[x+i][y] = j;
				map[x+size-1-i][y] = j;
				map[x+i][y+size-1] = j;
				map[x+size-1-i][y+size-1] = j;
				number[j] -= 4;
				pos = 1;
				break;
			}
		}
		if(!pos) return 0;
	}
	//sero
	for(int i=1; i<=(t_size)/2; i++){
			pos = 0;
		for(int j=1; j<=1000; j++){
			if(number[j]>=4){
				map[x][y+i] = j;
				map[x][y+size-1-i] = j;
				map[x+size-1][y+i] = j;
				map[x+size-1][y+size-1-i] = j;
				number[j] -= 4;
				pos = 1;
				break;
			}
		}
		if(!pos) return 0;
	}
	return make(size-2, x+1, y+1, o_size);
}


int main(){
	scanf("%d", &n);
	for(int i=0; i<n*n; i++) scanf("%d", &arr[i]);
	for(int i=0; i<n*n; i++)	number[arr[i]]++;
	if(make(n,0,0,n) == 0) printf("NO");
	else{
		printf("YES\n");
		for(int i=0; i<n; i++){
			for(int j=0; j<n; j++){
				printf("%d ", map[i][j]);
			}
			printf("\n");
		}
	}
	
}
