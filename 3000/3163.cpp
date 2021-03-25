//# Author : nuclear852 ========================#
//# Solution : 3785542 =========================#
//# Time Stamp : 2016-08-10 02:30:03 ===========#
//# Problem Title : 떨어지는 개미 ================#
//# Language : C++98 ===========================#

#include <iostream>
#include <algorithm>
#include <stdio.h>

using namespace std;

struct ant{
        int ID;
        int pos;
};

struct antinf{
        int length;
        bool dir;
        int ID;
};

bool cmp_antinf(antinf a, antinf b){
        if( a.length < b.length)
                return 1;
        else if( a.length == b.length && a.dir == 0)
                return 1;
        else
                return 0;
}

int main(void)
{
        int testcase;
        cin>>testcase;
        int answer;

        while(testcase--)
        {
                int N, L, k;

                cin>>N>>L>>k;

                ant a[100000];
                antinf b[100000];
                int s=0;
                int e=N-1;

                for(int i=0; i<N; i++)
                        scanf("%d %d",&a[i].pos,&a[i].ID);

                for(int i=0; i<N; i++)
                {
                        if(a[i].ID >= 0) {
                                b[i].length = L - a[i].pos;
                                b[i].dir = 1;
                                b[i].ID = a[i].ID;
                        }
                        else{
                                b[i].length = a[i].pos;
                                b[i].dir = 0;
                                b[i].ID = a[i].ID;
                        }
                }

                sort(b,b+N,cmp_antinf);

                for(int i=0; i<k; i++)
                {
                        if( (i<N-1) && (b[i].length == b[i+1].length) )
                        {
                                if(a[s].ID > a[e].ID)
                                        swap( b[i], b[i+1] );
                        }

                        if( b[i].dir == 0)
                                answer = a[s++].ID;
                        else
                                answer = a[e--].ID;

                }

                cout<<answer<<endl;
        }
}