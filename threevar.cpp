#include<iostream>
using namespace std;
int det(float *job, float *pk int y)
{ 
	float *x=*job
	float k,sum=0;
	if(y!=0)
	{
		*x[y-1][0]=*pk[0];
		*x[y-1][1]=*pk[1];
		*x[y-1][2]=*pk[2];
	}
	for(k=0;k<3;k++)
	{
		if(k==0)
		{
			sum+=x[k][0]*(x[k+1][k+1]*x[k+2][k+2]-x[k+1][k+2]*x[k+2][k+1]);
		}
		if(k==1)
		{
			sum-=x[k][0]*(x[k-1][k]*x[k+1][k+1]-x[k-1][k+1]*x[k+1][k]);
		}
		if(k==2)
		{
			sum+=x[k][0]*(x[k-2][k-1]*x[k-1][k]-x[k-2][k]*x[k-1][k-1]);
		}
	}
	return(sum);
}
int main()
{
	float a[3][3],cons[3];
	int i,j;
	cout<<"STANDARD FORM IS: aix+biy+ciz+di=0\nTHIS CASE: 3 VARIABLE";
	for(i=0;i<2;i++)
	{
		for(j=0;j<3;j++)
		{
			switch(i)
			{
				case 0: cout<<"\na"<<(j+1)<<": ";
				case 1: cout<<"\nb"<<(j+1)<<": ";
				case 2: cout<<"\nc"<<(j+1)<<": ";
			}
			cin>>a[i][j];
		}
	}
	for(i=0;i<3;i++)
	{
		cout<<"\nd"<<(i+1)<<": ";
		cin>>cons[i];
	}
	cout<<"\nx= "<<(det(&a,&cons,1)/det(&a,&cons,0));
	cout<<"\ny= "<<(det(&a,&cons,2)/det(&a,&cons,0));
	cout<<"\nz= "<<(det(&a,&cons,3)/det(&a,&cons,0));
	/*cout<<"EQN1: "<<a[0]<<"x+ "<<b[0]<<"y+ "<<c[0]<<"=0";
	cout<<"\nEQN2: "<<a[1]<<"x+ "<<b[1]<<"y+ "<<c[1]<<"=0";
	cout<<"\nx="<<(b[0]*c[1]-b[1]*c[0])/(a[0]*b[1]-a[1]*b[0]);
	cout<<"\ny="<<(c[0]*a[1]-c[1]*a[0])/(a[0]*b[1]-a[1]*b[0]);*/
	return 0;
}