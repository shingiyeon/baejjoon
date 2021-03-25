//# Author : nuclear852 ========================#
//# Solution : 5143326 =========================#
//# Time Stamp : 2017-02-01 17:48:24 ===========#
//# Problem Title : Starman ================#
//# Language : C++98 ===========================#

#include <iostream>
#include <stdio.h>
using namespace std;
int main(){
        int T; cin>>T;
        int year[25] = {1967, 1969, 1970, 1971, 1972, 1973, 1973, 1974,1975,1976,1977,1977,1979,1980,1983, 1984,1987,1993,1995,1997,1999,2002,2003,2013,2016};
        char s[25][100] = {"DavidBowie","SpaceOddity","TheManWhoSoldTheWorld","HunkyDory","TheRiseAndFallOfZiggyStardustAndTheSpidersFromMars","AladdinSane", "PinUps", "DiamondDogs", "YoungAmericans", "StationToStation", "Low", "Heroes", "Lodger", "ScaryMonstersAndSuperCreeps", "LetsDance", "Tonight", "NeverLetMeDown", "BlackTieWhiteNoise", "1.Outside", "Earthling", "Hours", "Heathen", "Reality", "TheNextDay", "BlackStar"};
        while(T--){
                int a, b;       scanf("%d %d",&a,&b);
                int num = 0;
                for(int i=0; i<25; i++) if(year[i] >= a && year[i] <= b)        num++;
                cout<<num<<"\n";
                for(int i=0; i<25; i++) if(year[i] >= a && year[i] <= b) printf("%d %s\n",year[i],s[i]);
        }
}