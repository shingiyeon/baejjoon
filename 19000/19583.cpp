//# Author : nuclear852 ========================#
//# Solution : 22834513 ========================#
//# Time Stamp : 2020-09-25 23:17:54 ===========#
//# Problem Title : 싸이버개강총회 ================#
//# Language : C++14 ===========================#

#include <stdio.h>
#include <string>
#include <map>
using namespace std;
using std::string;

struct time {
	int h, m;
};

bool operator<=(const struct time &a, const struct time &b) {
	return a.h == b.h ? a.m <= b.m : a.h <= b.h;
}

map<string, int> m;

int main() {
	struct time S, E, Q;
	struct time T;
	char ID[21];
	int ans = 0;
	scanf("%d:%d %d:%d %d:%d", &S.h, &S.m, &E.h, &E.m, &Q.h, &Q.m);
	while(scanf("%d:%d %s", &T.h, &T.m, ID) != EOF) {
		if(T <= S) {
			string temp(ID);
			m[temp] = 1;
		}
		else if(E <= T && T <= Q) {
			string temp(ID);
			if(m[temp] == 1) {
				ans++;
				m[temp] = 2;
			}
		}
	}
	printf("%d", ans);
	
}