//# Author : nuclear852 ========================#
//# Solution : 5158392 =========================#
//# Time Stamp : 2017-02-04 09:17:10 ===========#
//# Problem Title : 농구 경기 ==================#
//# Language : C++98 ===========================#

#include <stdio.h>
#include <iostream>
#include <string.h>
using namespace std;
int main(){
        bool pos = 0;
        char s[35]; int N; cin>>N;
        int arr[30]; memset(arr,0,sizeof(arr));
        for(int i=0; i<N; i++){
                scanf("%s",s);
                arr[ s[0]-'a' ]++;
        }
        for(int i=0; i<30; i++){
                if(arr[i]>=5){
                        printf("%c",i+'a'); pos = 1;
                }
        }
        if(!pos) cout<<"PREDAJA";
}