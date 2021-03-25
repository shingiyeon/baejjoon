//# Author : nuclear852 ========================#
//# Solution : 13081945 ========================#
//# Time Stamp : 2019-05-08 21:27:42 ===========#
//# Problem Title : 트리 순회 ==================#
//# Language : C++98 ===========================#

#include <stdio.h>
#include <utility>
using namespace std;

pair<int, int> tree[27];

void preorder(int visited){
	printf("%c", visited+'A');
	if(tree[visited].first != 26){
		preorder(tree[visited].first);
	}
	if(tree[visited].second!=26){
		preorder(tree[visited].second);
	}
}


void inorder(int visited){
	if(tree[visited].first != 26){
		inorder(tree[visited].first);
	}
	printf("%c", visited+'A');
	if(tree[visited].second!=26){
		inorder(tree[visited].second);
	}
}

void postorder(int visited){
	if(tree[visited].first != 26){
		postorder(tree[visited].first);
	}
	if(tree[visited].second!=26){
		postorder(tree[visited].second);
	}
	printf("%c", visited+'A');
}

int main(){
	int N; scanf("%d", &N);
	while(N--){
		char a, b, c;
		scanf("\n%c %c %c", &a,&b,&c);
		a = a - 'A';
		b = (b == '.' ? 26 : b-'A');
		c = (c == '.' ? 26 : c-'A');
		tree[a].first = b;
		tree[a].second = c;
	}
	
	preorder(0);
	printf("\n");
	inorder(0);
	printf("\n");
	postorder(0);
	
}