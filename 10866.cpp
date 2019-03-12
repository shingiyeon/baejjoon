#include <stdio.h>
#include <vector>
using namespace std;

vector<int> v;

void push_front(int x){
	v.insert(v.begin(),x);
}

void push_back(int x){
	v.push_back(x);
}

void pop_front(){
	if(v.empty()) printf("-1\n");
	else{
		printf("%d\n",v[0]);
		v.erase(v.begin());
	}
}

void pop_back(){
	if(v.empty()) printf("-1\n");
	else{
		printf("%d\n",v[v.size()-1]);
		v.pop_back();
	}
}

void size(){
	printf("%d\n", v.size());
}

void empty(){
	printf("%d\n", v.empty());
}

void front(){
	if(v.empty()) printf("-1\n");
	else printf("%d\n", v[0]);
}

void back(){
	if(v.empty()) printf("-1\n");
	else printf("%d\n", v[v.size()-1]);
}

int main(){
	int N; scanf("%d", &N);
	char command[20];
	while(N--){
		int temp;
		scanf("%s",command);
		switch(command[1]){
			case 'a':
				back(); break;
			case 'i':
				size(); break;
			case 'm':
				empty(); break;
			case 'r':
				front(); break;
			case 'u':
				scanf("%d", &temp);
				if(command[5]=='b') push_back(temp);
				else push_front(temp);
				break;
			case 'o':
				if(command[4]=='f') pop_front();
				else pop_back();
				break;
		}
	}
}
