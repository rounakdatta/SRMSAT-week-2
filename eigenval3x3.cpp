#include<iostream>
#include<cmath>
using namespace std;
float cubeq(float bu, float cu, float du)
{
	float au=1,p,q,ca,fi,cb;
	float eig[3];
	p=(3*au*cu-bu*bu)/(3*au*au);
	q=(2*pow(bu,3)-9*au*bu*cu+27*au*au*du)/(27*pow(au,3));
	if(p>0) {cout<<"At least one root is complex!"; return 0;}
	ca=2*pow((-p/3),0.5);
	fi=acos((3*q)/(ca*p));
	cb=-bu/(3*au);
	eig[0]=ca*cos(fi/3)+cb;
	eig[1]=ca*cos((fi+2*3.14)/3)+cb;
	eig[2]=ca*cos((fi+4*3.14)/3)+cb;
	cout<<"\nFirst eigen value: "<<-eig[0];
	cout<<"\nSecond eigen value: "<<-eig[1];
	cout<<"\nThird eigen value: "<<-eig[2];
	return 0;//&eig[0];
}
float determinant(float xuv[3][3])
{
	float det3=0;
	int ct1,ct2;
	det3= xuv[0][0] * ((xuv[1][1]*xuv[2][2]) - (xuv[2][1]*xuv[1][2])) -xuv[0][1] * (xuv[1][0] * xuv[2][2] - xuv[2][0] * xuv[1][2]) + xuv[0][2] * (xuv[1][0] * xuv[2][1] - xuv[2][0] * xuv[1][1]);
	return det3;
}
float cofac(float a1, float b1, float c1, float d1)
{
	float det2=0;
	int counter,count2;
	det2=a1*d1-b1*c1;
	return det2;
}
int main()
{

	float sum=0, mid;
	float mat[3][3],a[3];
	int i,j;
	cout<<"ENTER 3X3 MATRIX:\n";
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
			cin>>mat[i][j];
		}
	}
	a[1]=cofac(mat[1][1],mat[1][2],mat[2][1],mat[2][2])+cofac(mat[0][0],mat[0][2],mat[2][0],mat[2][2])+cofac(mat[0][0],mat[0][1],mat[1][0],mat[1][1]);
	a[0]=mat[0][0]+mat[1][1]+mat[2][2];
	a[2]=determinant(mat);
	cubeq(a[0],a[1],a[2]);
	return 0;
}