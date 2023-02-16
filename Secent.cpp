#include<iostream>
#include<cmath>
using namespace std;

float f(float x)
{
    return cos(x)-x*exp(x);
}
float secSolution(float a,float b)
{
    float c;
    int iter=0;
    do
    {
        iter++;
        if(iter>300)
        {
            cout<<"Function is discontinious on given interval:";
            return 0;
        }
        c=(a*f(b)-b*f(a))/(f(b)-f(a));
        a=b;
        b=c;
    }while((fabs(f(c)))>=0.00001);
    return c;
}
int main()
{
    float a,b;
    cout<<"Enter intervals: ";
    cin>>a>>b;
    cout<<"The solution is:"<<secSolution(a,b);
    return 0;
}