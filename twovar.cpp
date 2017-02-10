#include<iostream>
using namespace std;
int main()
{
	float a[2],b[2],c[2],x,y;
	int i;
	cout<<"STANDARD FORM IS: aix+biy+ci=0\nTHIS CASE: 2 VARIABLE";
	for(i=0;i<2;i++)
	{
		cout<<"\na"<<(i+1)<<": ";
		cin>>a[i];
	}
	for(i=0;i<2;i++)
	{
		cout<<"\nb"<<(i+1)<<": ";
		cin>>b[i];
	}
	for(i=0;i<2;i++)
	{
		cout<<"\nc"<<(i+1)<<": ";
		cin>>c[i];
	}
	cout<<"EQN1: "<<a[0]<<"x+ "<<b[0]<<"y+ "<<c[0]<<"=0";
	cout<<"\nEQN2: "<<a[1]<<"x+ "<<b[1]<<"y+ "<<c[1]<<"=0";
	cout<<"\nx="<<(b[0]*c[1]-b[1]*c[0])/(a[0]*b[1]-a[1]*b[0]);
	cout<<"\ny="<<(c[0]*a[1]-c[1]*a[0])/(a[0]*b[1]-a[1]*b[0]);
	return 0;
}