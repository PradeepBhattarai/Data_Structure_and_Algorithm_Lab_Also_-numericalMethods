#include<iostream>
using namespace std;
//solving dy/dx=x+y
float f(float x,float y)
{
    return x+y;
}
int main()
{
    float x0,y0,xn,yn,slope;
    float h;
    cout<<"Enter Initial Conditions:"<<endl;
    cout<<"x0= ";
    cin>>x0;
    cout<<"y0= ";
    cin>>y0;
    cout<<"Enter calculation point xn= ";
    cin>>xn;
    cout<<"Enter step size: ";
    cin>>h;

    //calculating step size h
    // int n=(xn-x0)/h;
    //Euler's Method
    cout<<"\nx\ty\tslope\tyn+1\n";
    cout<<"--------------------------\n";

   while(x0<=xn)
    {
        slope=f(x0,y0);
        yn=y0+h*slope;
        cout<<x0<<"\t"<<y0<<"\t"<<slope<<"\t"<<yn<<endl;
        y0=yn;
        x0=x0+h;
    }
    cout<<"\n Value of y at x = "<<xn<<" is "<<yn<<endl;

    return 0;
}