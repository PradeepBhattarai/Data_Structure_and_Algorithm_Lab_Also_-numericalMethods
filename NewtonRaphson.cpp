#include<iostream>
#include<cmath>
using namespace std;

float f(float x)
{
    return x*sin(x)+cos(x);
}
float df(float x)
{
    return x*cos(x);
}
int main()
{
    float x0,x1,err;
    int count=0;
    cout<<"Enter the initial value of x:x0=";
    cin>>x0;
    do{
        x1=x0-f(x0)/df(x0);
        err=fabs(x1-x0);
        x0=x1;
        count++;
        if(count>100)
        {
            cout<<"Mathematical Error"<<endl;
            return 0;
        }
    }while(err>0.0001);
    cout<<"The root is: "<<x0;


    return 0;
}