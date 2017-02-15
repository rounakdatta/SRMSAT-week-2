#include<iostream>
#include<cmath>
using namespace std;
int main()
{
	float a,b,c,d,p,q,ca,fi,cb,x,y,z;
	cout<<"Standard form is : ax3+bx2+cx+d=0\n";
	cout<<"Enter a: ";
	cin>>a;
	cout<<"Enter b: ";
	cin>>b;
	cout<<"Enter c: ";
	cin>>c;
	cout<<"Enter d: ";
	cin>>d;
	p=(3*a*c-b*b)/(3*a*a);
	q=(2*pow(b,3)-9*a*b*c+27*a*a*d)/(27*pow(a,3));
	if(p>0) {cout<<"At least one root is complex!"; return 0;}
	ca=2*pow((-p/3),0.5);
	fi=acos((3*q)/(ca*p));
	cb=-b/(3*a);
	x=ca*cos(fi/3)+cb;
	y=ca*cos((fi+2*3.14)/3)+cb;
	z=ca*cos((fi+4*3.14)/3)+cb;
	cout<<"\nFirst value: "<<x;
	cout<<"\nSecond value: "<<y;
	cout<<"\nThird value: "<<z;
	return 0;
}