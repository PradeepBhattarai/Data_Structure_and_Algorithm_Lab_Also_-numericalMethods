#include<iostream>
#include<cmath>

using namespace std;

float f(float x,float y)
{
    return 2 * y / x;
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
    
    float k1,k2,k,x,y;
    cout<<"\nxn\tyn\n";
    cout<<x0<<"\t"<<y0<<endl;

    while(x0<xn)
    {
        
        k1=h*f(x0,y0);
        k2=h*f(x0+h,y0+k1);
        k=(k1+k2)/2;
        y=y0+k;
        x0=x0+h;
        y0=y;
        cout<<x0<<"\t"<<y0<<endl;
    }
    cout<<"The value of y( "<<xn<<" ) is= "<<y0;
    return 0;
}