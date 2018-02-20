//Secant Method for finding the roots of an equation
#include<iostream>
#include<iomanip>
#include<cmath>
#include <bits/stdc++.h>
using namespace std;
int t=0,tim=0;
double f(double x);   
double n; //declare the function for the given equation
double f(double x)    //define the function here, ie give the equation
{
    tim=tim+5;
    double a=pow(x,2)-n;    //write the equation whose roots are to be determined
    tim=tim+1;
    return a;
}


int main()
{
double i=0; 
tim=tim+1;
cout.precision(8);
tim=tim+1;
cout.setf(ios::fixed);
tim=tim+1;
FILE *f1;
tim=tim+1;
f1=fopen("output.txt","w");    //set the precision of the output
tim=tim+1;
double a,b,c,e;
cin>>n;
tim=tim+1;
tim=tim+1;
if(n==0)
{
	cout<<"Roots are both = 0"<<endl;
	tim=tim+2;	
	return 0;
}
tim=tim+1;
else if(n<0)
{
	cout<<"Roots are both imaginary"<<endl;
	tim=tim+2;	
	return 0;
}
/*cout<<"Enter the initial guess\na=";
cin>>b;
cout<<"b=\n";                //take an intial guess
cin>>c;*/
tim=tim+1;
while(f(i)<=0){
    tim=tim+2;
    i=i+1.0;	
}
b=i-1;
c=i;
e=1e-8;
cout<<"The degree of accuracy is"<< e << endl;
tim=tim+4;
int t=0;                   //take the desired accuracy
do
{    
    t++;
    a=b;                
    b=c;                //make b equal to the last calculated value of c
    c=b-(b-a)/(f(b)-f(a))*f(b);    //calculate c
    tim=tim+9;
    tim=tim+1;
    if (f(c)==0)
    {
        cout<<"\nThe root of the equation is "<<c;    //print the root
        fprintf(f1,"%d %0.4lf\n",t,abs(f(c))*100);        
	tim=tim+5;	
	return 0;
    }
    tim=tim+3;
    fprintf(f1,"%d %0.4lf\n",t,abs(f(c))*100);
    tim=tim+3;
}while(abs(c-b)>=e);            //check if the error is greater than the desired accuracy
cout<<"\nThe root of the equation is "<<c;    //print the root
tim=tim+1;
return 0;
}


