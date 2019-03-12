#include <stdio.h>
int max(int a, int b, int c){
    if(a>=b){if(b>=c) return b; else{if(a>=c) return c; else return a;}}
    else{if(a>=c) return a; else{if (b>=c) return c; else return b;}}
}
int main(){int A,B,C;scanf("%d%d%d",&A,&B,&C);printf("%d",max(A,B,C));}
