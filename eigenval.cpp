#include<iostream>
#include<cmath>
using namespace std;
int main()
{
	float sum=0, mid;
	float a[2][2]={0};
	int i,j;
	cout<<"ENTER 2X2 MATRIX:\n";
	for(i=0;i<2;i++)
	{
		for(j=0;j<2;j++)
		{
			switch(i)
			{
				case 0: cout<<"\na"<<(j+1)<<": ";break;
				case 1: cout<<"\nb"<<(j+1)<<": ";break;
			}
			cin>>a[i][j];
		}
	}
	sum=a[0][0]*a[1][1]-a[0][1]*a[1][0];
	mid=-a[0][0]-a[1][1];
	cout<<"\nEigen value 1: "<<((-mid+sqrt(mid*mid-4*sum))/2);
	cout<<"\nEigen value 2: "<<((-mid-sqrt(mid*mid-4*sum))/2);
	return 0;
}