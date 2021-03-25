//# Author : nuclear852 ========================#
//# Solution : 1363819 =========================#
//# Time Stamp : 2016-01-23 12:12:32 ===========#
//# Problem Title : 2차원 배열의 합 ==============#
//# Language : C++98 ===========================#

#include <iostream>
using namespace std;
struct point{
        int sx;
        int sy;
        int ex;
        int ey;
};

int main(void)
{
        int N,M;

        cin>> N>>M;

        long arr[N][M];

        long dy[N][M];

        for(int i=0; i<N; i++)
        {
                for(int j=0; j<M; j++)
                {
                        cin>>arr[i][j];
                }
        }

        int k;
        cin >> k;

        point a[k];

        for(int i=0; i<k; i++)
                cin>>a[i].sx>>a[i].sy>>a[i].ex>>a[i].ey;

        dy[0][0] = arr[0][0];

        for(int i=0; i<N; i++)
        {
                for(int j=0; j<M; j++)
                {
                        if( j!=0 && i!=0)
                        {
                                dy[i][j] = dy[i-1][j] + dy[i][j-1] - dy[i-1][j-1] + arr[i][j];
                        }

                        else if( j == 0 && i != 0)
                        {
                                dy[i][j] = dy[i-1][j] + arr[i][j];
                        }

                        else if( i == 0 && j != 0)
                        {
                                dy[i][j]= dy[i][j-1] + arr[i][j];
                        }

                        else
                        {
                                dy[0][0] = arr[0][0];
                        }
                }
        }

        for(int i=0; i<k; i++)
        {
                if( a[i].sx >=2 && a[i].sy >=2)
                        cout<< ( dy[(a[i].ex-1)][(a[i].ey-1)] - dy[(a[i].sx-2)][(a[i].ey-1)]- dy[(a[i].ex-1)][(a[i].sy-2)] + dy[(a[i].sx-2)][(a[i].sy-2)])<<endl;

                else if( a[i].sx < 2 && a[i].sy >=2)
                        cout<< (dy[ a[i].ex-1 ][ a[i].ey-1 ] - dy[ a[i].ex-1 ][ a[i].sy-2 ])<<endl ;
                else if( a[i].sx >=2 && a[i].sy <2)
                        cout<<dy[(a[i].ex-1)][(a[i].ey-1)] - dy[(a[i].sx-2)][(a[i].ey-1)] <<endl;
                else
                        cout<<dy[(a[i].ex-1)][(a[i].ey-1)] <<endl;
        }
        return 0;
}