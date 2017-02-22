#include<iostream>
#include<cmath>
using namespace std;
float (*multiplymat(float user1[3][3], float user2[3][3]))[3]
{
	float (*finalm)[3]=new float[3][3];
	float summ=0;
	int i2,j2,k2;
	for (i2 = 0; i2 <= 2; i2++) {
      for (j2 = 0; j2 <= 2; j2++) {
         summ = 0;
         for (k2 = 0; k2 <= 2; k2++) {
            summ = summ + user1[i2][k2] * user2[k2][j2];
         }
         finalm[i2][j2] = summ;
      }
   }
   return finalm;
}
float (*transpose(float trix[3][3]))[3]
{
	float (*newtrix)[3]=new float[3][3];
	int i1,j1;
	for(i1=0;i1<3;i1++)
	{
		for(j1=0;j1<3;j1++)
		{
			newtrix[i1][j1]=trix[j1][i1];
		}
	}
	return newtrix;
}
float determinant(float xuv[3][3])
{
	float det3=0;
	int ct1,ct2;
	det3= xuv[0][0] * ((xuv[1][1]*xuv[2][2]) - (xuv[2][1]*xuv[1][2])) -xuv[0][1] * (xuv[1][0] * xuv[2][2] - xuv[2][0] * xuv[1][2]) + xuv[0][2] * (xuv[1][0] * xuv[2][1] - xuv[2][0] * xuv[1][1]);
	return det3;
}
float *eigvecsolve(float solver[3][3])
{
	static float evex[3];
	evex[0]=(solver[0][1]*solver[1][2]-solver[0][2]*solver[1][1]);
	evex[1]=(solver[0][2]*solver[1][0]-solver[1][2]*solver[0][0]);
	evex[2]=(solver[0][0]*solver[1][1]-solver[0][1]*solver[1][0]); 
	cout<<evex[0]<<"  "<<evex[1]<<"  "<<evex[2]<<" ]";
	return evex;
}
float *cubeq(float bu, float cu, float du)
{
	float au=1,p,q,ca,fi,cb;
	static float eig[3];
	p=(3*au*cu-bu*bu)/(3*au*au);
	q=(2*pow(bu,3)-9*au*bu*cu+27*au*au*du)/(27*pow(au,3));
	if(p>0) {cout<<"At least one root is complex!"; return 0;}
	ca=2*pow((-p/3),0.5);
	fi=acos((3*q)/(ca*p));
	cb=-bu/(3*au);
	eig[0]=nearbyint(ca*cos(fi/3)+cb);
	eig[1]=nearbyint(ca*cos((fi+2*3.14)/3)+cb);
	eig[2]=nearbyint(ca*cos((fi+4*3.14)/3)+cb);
	cout<<"\nFirst eigen value: "<<-eig[0];
	cout<<"\nSecond eigen value: "<<-eig[1];
	cout<<"\nThird eigen value: "<<-eig[2];
	return eig;
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

	float sum=0, mid,factor;
	float mat[3][3],a[3],eigena[3],mat2[3][3],egvex[3][3];
	//float **evxi[3][3];
//	float **mat3[3][3];
	//float **diag[3][3];
	float *temp;
	float *redhat;
	int i,j,chen;
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
	cout<<"YOUR MATRIX : \n";
	for(i=0;i<3;i++)
	{
		for(j=0;j<3;j++)
		{
			cout<<mat[i][j]<<"  ";
		}
		cout<<"\n";
	}
	a[1]=cofac(mat[1][1],mat[1][2],mat[2][1],mat[2][2])+cofac(mat[0][0],mat[0][2],mat[2][0],mat[2][2])+cofac(mat[0][0],mat[0][1],mat[1][0],mat[1][1]);
	a[0]=mat[0][0]+mat[1][1]+mat[2][2];
	a[2]=determinant(mat);
	temp=cubeq(a[0],a[1],a[2]);
	eigena[0]=*temp;
	eigena[1]=*(temp+1);
	eigena[2]=*(temp+2);
	/*for(i=0;i<3;i++)
	{
		for(j=0;j<3;j++)
			{
				mat2[i][j]=mat[i][j];
			}
	}*/
	for(chen=0;chen<3;chen++)
	{
		for(i=0;i<3;i++)
	  {
		for(j=0;j<3;j++)
			{
				mat2[i][j]=mat[i][j];
			}
	  }
		for(i=0;i<3;i++)
	  {
		mat2[i][i]-=eigena[chen];
	  }
	  cout<<"\n\nEigen Vector "<<(chen+1)<<": [ ";
	  redhat=eigvecsolve(mat2);
	  egvex[chen][0]=*redhat;
	  egvex[chen][1]=*(redhat+1);
	  egvex[chen][2]=*(redhat+2);
	}
	for(i=0;i<3;i++)
	{
		for(j=0;j<3;j++)
		{
			factor+=pow(egvex[j][i],2);
		}
		factor=sqrt(factor);
		for(j=0;j<3;j++)
		{
			egvex[j][i]/=factor;
		}
	}
	cout<<"\nYOUR NORMALIZED MATRIX : \n";
	for(i=0;i<3;i++)
	{
		for(j=0;j<3;j++)
		{
			cout<<egvex[i][j]<<"  ";
		}
		cout<<"\n";
	}
	/*redhat=transpose(egvex);
	for(i=0;i<3;i++)                 // the method was good for 1 x3 matrices ... need to refine it for 3x3 matrices
	{
	  evxi[i][0]=*redhat;
	  evxi[i][1]=*(redhat+1);
	  evxi[i][2]=*(redhat+2);
	}
	redhat=multiplymat(mat,egvex);
	for(i=0;i<3;i++)
	{
	  mat2[i][0]=*redhat;
	  mat2[i][1]=*(redhat+1);
	  mat2[i][2]=*(redhat+2);
	}
	redhat=multiplymat(evxi,mat2);
	for(i=0;i<3;i++)
	{
	  diag[i][0]=*redhat;
	  diag[i][1]=*(redhat+1);
	  diag[i][2]=*(redhat+2);
	}*/
	//evxi=transpose(egvex);
	//mat3=multiplymat(mat,egvex);
	//diag=multiplymat(evxi,mat3);
	float (*evxi)[3]=transpose(egvex);
	float (*mat3)[3]=multiplymat(mat,egvex);
	float (*diag)[3]=multiplymat(evxi,mat3);
	cout<<"\nYOUR DIAGONALIZED MATRIX : \n";
	for(i=0;i<3;i++)
	{
		for(j=0;j<3;j++)
		{
			cout<<(diag[i][j])<<"  ";
		}
		cout<<"\n";
	}
	return 0;
}