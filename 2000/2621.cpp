#include <stdio.h>
#include <algorithm>
using namespace std;
struct card{
	char color;
	int number;
}c[5];
int color(){
	char a = c[0].color;
	for(int i=1; i<5; i++)
		if(a!=c[i].color) return 0;
	return c[4].number;
}
int straight(){
	int num = c[0].number;
	for(int i=1; i<5; i++)
		if(num+i!=c[i].number) return 0;
	return c[4].number;
}
int fourcard(){
	for(int i=0; i<2; i++){
		bool pos = 1;
		int num=c[i].number;
		for(int j=i+1; j<i+4; j++)
			if(num!=c[j].number) pos = 0;
		if(pos) return num;
	}
	return 0;
}
int fullhouse(){
	if(c[0].number == c[1].number && c[2].number == c[3].number && c[4].number==c[2].number)
		return c[2].number*10 + c[0].number;
	if(c[3].number == c[4].number && c[0].number == c[1].number && c[2].number==c[0].number)
		return c[0].number*10 + c[3].number;
	return 0;
}
int triple(){
	if(c[0].number == c[1].number && c[1].number == c[2].number)
		return c[0].number;
	if(c[1].number == c[2].number && c[2].number == c[3].number)
		return c[1].number;
	if(c[2].number == c[3].number && c[3].number == c[4].number)
		return c[2].number;
	return 0;
}
int twopair(){
	if(c[0].number == c[1].number && c[2].number == c[3].number)
		return 10*c[2].number + c[0].number;
	if(c[0].number == c[1].number && c[3].number == c[4].number)
		return 10*c[3].number + c[0].number;
	if(c[1].number == c[2].number && c[3].number == c[4].number)
		return 10*c[3].number + c[1].number;
	return 0;
}
int onepair(){
	for(int i=0; i<4; i++){
		if(c[i].number == c[i+1].number)
			return c[i].number;
	}
	return 0;
}
bool comp(card a, card b){return a.number>b.number? 0:1;}
int main(){
	for(int i=0; i<5; i++)
		scanf(" %c%d",&c[i].color,&c[i].number);
	sort(c, c+5, comp);
	if(color()&&straight()){
		printf("%d",900+c[4].number);
		return 0;
	}
	if(fourcard()){
		printf("%d", 800+fourcard());
		return 0;
	}
	if(fullhouse()){
		printf("%d", 700+fullhouse());
		return 0;
	}
	if(color()){
		printf("%d", 600+color());
		return 0;
	}
	if(straight()){
		printf("%d", 500+straight());
		return 0;
	}
	if(triple()){
		printf("%d", 400+triple());
		return 0;
	}
	if(twopair()){
		printf("%d", 300+twopair());
		return 0;
	}
	if(onepair()){
		printf("%d", 200+onepair());
		return 0;
	}
	printf("%d", 100+c[4].number);
	
}
