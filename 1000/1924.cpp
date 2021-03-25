//# Author : nuclear852 ========================#
//# Solution : 5046787 =========================#
//# Time Stamp : 2017-01-18 10:12:52 ===========#
//# Problem Title : 2007년 ==================#
//# Language : C++98 ===========================#

#include <iostream>
#include <string.h>
using namespace std;
int main(){
        int arr[13] = {0,31,28,31,30,31,30,31,31,30,31,30,31};
        string d[7] = {"MON","TUE","WED","THU","FRI","SAT","SUN"};
        int x, y; cin>>x>>y;
        int day = 0;
        for(int i=1; i<x; i++)
                day += arr[i];
        day += y;       day = day-1;
        cout<< d[ day%7 ] <<endl;
}