#include<iostream>
#include<cmath>

using namespace std;

float f(float x,float y)
{
    return x*x+2*x-y;
}
int main()
{
    float x0, y0, xn, h;
    cout<<"Enter initial values of x0 and y0:";
    cin>>x0>>y0;
    cout<<"Enter step size:h=";
    cin>>h;
    cout<<"Enter xn for which y to be determined: ";
    cin>>xn;
    float k1,k2,k3,k4,k,x,y;
    cout<<"\nxn\tyn\n";
    cout<<x0<<"\t"<<y0<<endl;
    while(x0<=xn)
    {
        k1=h*f(x0,y0);
        k2=h*f(x0+h/2,y0+k1/2);
        k3=h*f(x0+h/2,y0+k2/2);
        k4=h*f(x0+h,y0+k3);
        k=(k1+2*k2+2*k3+k4)/6;
        y=y0+k;
        x=x0+h;
        x0=x;
        y0=y;
        cout<<x<<"\t"<<y<<endl;
    }
    cout<<"The value of y( "<<xn<<" ) is= "<<y0;
    return 0;
}