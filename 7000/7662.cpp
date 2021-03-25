//# Author : nuclear852 ========================#
//# Solution : 3785922 =========================#
//# Time Stamp : 2016-08-10 03:15:39 ===========#
//# Problem Title : 이중 우선순위 큐 ==============#
//# Language : C++98 ===========================#

#include <iostream>
#include <queue>
#include <stdio.h>
#include <utility>

using namespace std;

int main(void)
{
        int testcase;
        cin>>testcase;

        while(testcase--)
        {
                int N;
                cin>>N;

                priority_queue < pair<long long, int> > maxq, minq;
                bool out[1000001];
                int number = 0;

                for(int i=0; i<1000001; i++)
                        out[i] = 0;

                while(N--)
                {
                        char c;
                        long long a;
                        scanf(" %c %lld",&c,&a);
                        if(c=='I')
                        {
                                out[number++] = 1;
                                pair<long long, int> asd1 = make_pair(a, number-1);
                                pair<long long, int> asd2 = make_pair(-a, number-1);
                                maxq.push( asd1 );
                                minq.push( asd2 );
                        }
                        else
                        {
                                while( !maxq.empty() && !out[ maxq.top().second] ) maxq.pop();
                                while( !minq.empty() && !out[ minq.top().second] ) minq.pop();

                                if( maxq.empty() && minq.empty() ) continue;

                                if(a==1){
                                        out[ maxq.top().second ] = 0;
                                        maxq.pop();
                                }
                                else{
                                        out[ minq.top().second ] = 0;
                                        minq.pop();
                                }
                        }
                }

                while( !maxq.empty() && !out[maxq.top().second] ) maxq.pop();
                while( !minq.empty() && !out[minq.top().second] ) minq.pop();

                if(maxq.empty() && minq.empty())
                        cout<<"EMPTY"<<endl;
                else
                        cout<<maxq.top().first<<" "<<-minq.top().first<<endl;
        }
}