//# Author : nuclear852 ========================#
//# Solution : 11607650 ========================#
//# Time Stamp : 2019-01-31 15:44:07 ===========#
//# Problem Title : 외판원 순회 2 ===============#
//# Language : C++98 ===========================#

#include <iostream>
#include <stdio.h>
#include <math.h>
using namespace std;

int dy[17][1<<17];
int map[17][17];
int N;
int start = 1;

int min(int a, int b)
{       return a < b? a : b; }
int city(int citynum, int state)
{
        int current = 1<<(citynum);
        //printf("current|state: %d\n", current|state );
        if( (current | state) == ((1<<N+1)-2) ){
			if(map[citynum][1] == 0)
				return 987654321;
            return map[citynum][1];
		}
        if( dy[citynum][state] != -1)
                return dy[citynum][state];

        int Min = 987654321;
        for(int i=1; i<=N; i++)
        {
                int temp = 1<<i;
        //      printf("temp & (current|state) : %d\n", temp & current|state);
                if( (temp & (current|state)) == 0 && map[citynum][i] != 0 ){
                        Min = min( Min, city(i, current|state)+map[citynum][i] );
                //      printf("City: %d, State: %d, Min : %d\n", citynum, state,Min);
                }
        }
        dy[citynum][state] = Min;
        return Min;
}

int main(){

        cin>>N;
        for(int i=1; i<=N; i++)
                for(int j=1; j<=N; j++)
                        scanf("%d", &map[i][j]);
        for(int i=1; i<=N; i++)
                for(int j=0; j<=(1<<N+1)-1; j++)
                        dy[i][j] = -1;

        printf("%d", city(1,0));
}