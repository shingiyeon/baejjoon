#include <iostream>
#include <stdio.h>
#include <algorithm>
#include <math.h>
using namespace std;

int dy[200001];
int arrx[200001];
int arry[200001];
int cha;


bool cmp(int k,int d)
{
	if( abs(f

	



int bs(int s, int e, int d)
{
	if(




int main(void)
{
	int test;
	cin>>test;
	while(test--)
	{
		int a, b, x, y, n;
		scanf("%d%d%d%d%d",&a,&b,&x,&y,&n);
		
		for(int i=0; i<=200000; i++){
			dy[i]=0;
			arrx[i]=0;
			arry[i]=0;
		}

		for(int i=1; i<n+1; i++)
		{
			dy[i]=0;
			scanf("%d%d",&arrx[i],&arry[i]);
		}
		
		cha=b-a;
		if(a>b)
			cha=a-b;

		for(int i=1; i<n+1; i++)
		{




		
		
