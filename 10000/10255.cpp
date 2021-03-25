//# Author : nuclear852 ========================#
//# Solution : 1676618 =========================#
//# Time Stamp : 2016-02-13 18:27:37 ===========#
//# Problem Title : 교차점 ====================#
//# Language : C++98 ===========================#

#include <iostream>
using namespace std;
int ccw(int p1x, int p1y, int p2x, int p2y, int p3x, int p3y) {
        int direction = (p2x-p1x) * (p3y-p1y) - (p3x-p1x) * (p2y - p1y);
        if (direction > 0)
                return 1;
        else if(direction < 0)
                return -1;
        else
                return 0;
}
int isIntersection(int p1x, int p1y, int p2x, int p2y, int p3x, int p3y, int p4x, int p4y) {
        int tmp1, tmp2, tmp3, tmp4;

        tmp1 = ccw( p1x, p1y, p2x, p2y, p3x, p3y);
        tmp2 = ccw( p1x, p1y, p2x, p2y, p4x, p4y);
        tmp3 = ccw( p4x, p4y, p3x, p3y, p1x, p1y);
        tmp4 = ccw( p4x, p4y, p3x, p3y, p2x, p2y);

        if( tmp1 != tmp2 && tmp3 != tmp4)
        {
                if(tmp2 == 0)
                        return 1;
                else if(tmp1 == 0)
                        return -1;
                else
                        return 0;
        }
        else
                return -2;
}
int main(void)
{
        int T;
        cin>>T;
        for(int test=0; test<T; test++)
        {
                int xmin, xmax, ymin, ymax;
                int x1, y1, x2, y2;

                cin>> xmin >> ymin>> xmax>> ymax;
                cin>> x1>> y1>> x2>> y2;

                int ans = 0;
                bool checkymax = 0;
                bool checkymin = 0;

                if( x1 == x2 && (x1 == xmin || x1 == xmax) )
                {
                        int tmpy1, tmpy2;
                        if( y1> y2)
                        {       tmpy1 = y1; tmpy2 = y2; }
                        else
                        {       tmpy1 = y2; tmpy2 = y1; }

                        if( tmpy2 <= ymin && ymax <= tmpy1)
                                ans = 4;
                        if( tmpy2 < ymax && tmpy2 >= ymin)
                                ans = 4;
                        if( tmpy1 <= ymax && tmpy1 > ymin)
                                ans = 4;
                }

                else if( y1==y2 && (y1 == ymin || y1==ymax) )
                {
                        int tmpx1, tmpx2;
                        if(x1> x2)
                        {       tmpx1 = x1; tmpx2 = x2;}
                        else
                        {       tmpx1 = x2; tmpx2 = x1;}
                        if( tmpx2 <= xmin && xmax <= tmpx1)
                                ans = 4;
                        if( tmpx2 < xmax && tmpx2 >=xmin)
                                ans = 4;
                        if( tmpx1 <= xmax && tmpx1 > xmin)
                                ans = 4;
                }
                
            if(ans != 4)
                {
                        int temp;
                        bool yminon = 0;
                        bool ymaxon = 0;
                        bool xmaxon = 0;
                        temp=isIntersection(x1,y1,x2,y2,xmin,ymin,xmin,ymax);
                        if(temp != -2)
                        {
                                ans++;
                                if(temp == 1)
                                        ymaxon = 1;
                                else if(temp == -1)
                                        yminon = 1;
                        }
                        temp=isIntersection(x1,y1,x2,y2,xmin,ymax,xmax,ymax);
                        if(temp != -2 && ymaxon == 0)
                        {
                                ans++;
                                if(temp == 1)
                                        xmaxon = 1;
                        }
                        temp = isIntersection(x1,y1,x2,y2,xmax,ymax,xmax,ymin);
                        if(temp != -2 && xmaxon == 0)
                        {
                                ans++;
                                if(temp == 1)
                                        yminon = 1;
                        }
                        temp = isIntersection(x1,y1,x2,y2,xmax,ymin,xmin,ymin);
                        if(temp != -2 && yminon == 0)
                        {
                                ans++;
                        }
                }
                cout<<ans<<endl;
        }
        return 0;
}