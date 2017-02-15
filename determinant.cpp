#include<iostream>
using namespace std;
int main()
{
	float sum=0;
	float a[3][3];
	int i,j;
	for(i=0;i<3;i++)
	{
		for(j=0;j<3;j++)
		{
			switch(i)
			{
				case 0: cout<<"\na"<<(j+1)<<": ";break;
				case 1: cout<<"\nb"<<(j+1)<<": ";break;
				case 2: cout<<"\nc"<<(j+1)<<": ";break;
			}
			cin>>a[i][j];
		}
	}
	for(i=0;i<3;i++)
	{
		if(i==0)
		{
			sum+=a[i][0]*(a[i+1][i+1]*a[i+2][i+2]-a[i+1][i+2]*a[i+2][i+1]);
		}
		if(i==1)
		{
			sum-=a[i][0]*(a[i-1][i]*a[i+1][i+1]-a[i-1][i+1]*a[i+1][i]);
		}
		if(i==2)
		{
			sum+=a[i][0]*(a[i-2][i-1]*a[i-1][i]-a[i-2][i]*a[i-1][i-1]);
		}
	}
	cout<<"\nSUM is: "<<sum;
	return 0;
}