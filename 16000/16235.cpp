//# Author : nuclear852 ========================#
//# Solution : 11648614 ========================#
//# Time Stamp : 2019-02-04 06:34:46 ===========#
//# Problem Title : 나무 재테크 =================#
//# Language : C++98 ===========================#

#include <stdio.h>
#include <utility>
#include <vector>
#include <algorithm>
using namespace std;

int N, M, K; 
int c_yangboon[11][11];
int f_yangboon[11][11];
vector<int> tree[11][11];

void tree_sort(){
	for(int i=1; i<=N; i++){
		for(int j=1; j<=N; j++)
			sort(tree[i][j].begin(), tree[i][j].end());
	}
}

void spring_and_summer(){
	for(int i=1; i<=N; i++){
		for(int j=1; j<=N; j++){
			int age = 0; 
			int range = tree[i][j].size();
			for(int k=0; k<range; k++){
				if(tree[i][j][k] <= c_yangboon[i][j]){
					c_yangboon[i][j] -= tree[i][j][k];
					tree[i][j][k] += 1;
				}
				else{
					age += (tree[i][j][tree[i][j].size()-1] / 2);
					tree[i][j].pop_back();
				}
			}
			c_yangboon[i][j] += age;
	
		}
	}
}

void fall(){
	int dx[8] = {-1, -1, -1, 0, 0, 1, 1, 1};
	int dy[8] = {-1, 0, 1, -1, 1, -1, 0, 1};
	for(int i=1; i<=N; i++){
		for(int j=1; j<=N; j++){
			for(int l=0; l<tree[i][j].size(); l++){
				if(tree[i][j][l] % 5 != 0) continue;
				for(int k=0; k<8; k++){
					if(i+dx[k] <= 0 || i+dx[k] > N || j+dy[k] <= 0 || j+dy[k] > N) continue;
					tree[i+dx[k]][j+dy[k]].push_back(1);
				}
			}
		}
	}
}

void winter(){
	for(int i=1; i<=N; i++){
		for(int j=1; j<=N; j++){
			c_yangboon[i][j] += f_yangboon[i][j];
		}
	}
}

int counting(){
	int c = 0;
	for(int i=1; i<=N; i++){
		for(int j=1; j<=N; j++){
			c += tree[i][j].size();
		}
	}
	return c;
}

void print_c_yangboon(){
	printf("current yangboon\n");
	for(int i=1; i<=N; i++){
		for(int j=1; j<=N; j++){
			printf("%d ", c_yangboon[i][j]);
		}
		printf("\n");
	}
}

void print_tree_number(){
	printf("print_tree_number \n");
	for(int i=1; i<=N; i++){
		for(int j=1; j<=N; j++){
			if(tree[i][j].size() == 0) continue;
			printf("r: %d, c: %d, number: %d\n", i, j, tree[i][j].size());
		}
	}
}

void print_tree_age(){
	printf("print_tree_age \n");
	for(int i=1; i<=N; i++){
		for(int j=1; j<=N; j++){
			if(tree[i][j].size() == 0) continue;
			printf("r: %d, c: %d\n", i, j);
			printf("-----------------\n");
			for(int l=0; l<tree[i][j].size(); l++){
				printf("%d ", tree[i][j][l]);
			}
			printf("\n");
		}
	}
}

int main(){
	int x, y, age;
	scanf("%d%d%d",&N,&M,&K);
	for(int i=1; i<=N; i++){
		for(int j=1; j<=N; j++){
			scanf("%d", &f_yangboon[i][j]);
			c_yangboon[i][j] = 5;
		}
	}
	for(int i=1; i<=M; i++){
		scanf("%d%d%d",&x,&y,&age);
		tree[x][y].push_back(age);
	}
	while(K--){
		tree_sort();
		spring_and_summer();
		/*printf("End of spring_summer\n");
		print_c_yangboon();
		print_tree_age();*/
		fall();
		/*printf("End of fall\n");
		print_tree_age();*/
		winter();
		/*printf("End of winter\n");
		print_c_yangboon();
		printf("=====================\n====================\n");

		getchar();
		*/
	}
	printf("%d", counting());
}