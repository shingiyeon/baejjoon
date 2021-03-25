//# Author : nuclear852 ========================#
//# Solution : 2966583 =========================#
//# Time Stamp : 2016-05-20 11:13:01 ===========#
//# Problem Title : 점 숫자 ===================#
//# Language : C++98 ===========================#

#include <iostream>
using namespace std;
int main(void)
{
	int test;
	cin >> test;
	while (test--)
	{
		int p1x, p1y, p2x, p2y, p1, p2, p3, p3x, p3y;
		cin >> p1 >> p2;

		int arr[1001];

		arr[1] = 1;

		for (int i = 1; i < 1000; i++)
			arr[i + 1] = arr[i] + i;

		int num1 = 1;
		int num2 = 1;
		while (p1 >= arr[num1])
			num1++;
		while (p2 >= arr[num2])
			num2++;

		p1x = p1 - arr[num1 -1] + 1;
		p1y = num1 - p1x;
		p2x = p2 - arr[num2 -1] + 1;
		p2y = num2 - p2x;
		p3x = p1x + p2x;
		p3y = p1y + p2y;

		int temp = p3y + p3x - 1;

		p3 = arr[temp] + p3x - 1;

		cout << p3 << endl;
	}
}