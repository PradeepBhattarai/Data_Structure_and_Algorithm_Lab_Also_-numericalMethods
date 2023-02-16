#include<iostream>
#include<cmath>
using namespace std;
class Bisection
{
    float a,b;
    public:
    Bisection(float x,float y)
    {
        a=x;
        b=y;
    }
    float f(float x)
    {
        return x*x*x*x*x+3*x*x-5;
    }
    void solution()
    {
        float c;
        int iter=0;
        if(f(a)*f(b)>0)
        {
            cout<<"No roots on given interval."<<endl;
            return;
        }
        else
        {
            do
            {
                iter++;
                if(iter>500 && f(c)>0.000001)
                {
                    cout<<"Function is discontinious "<<iter<<endl;
                    return;
                }
                else
                {
                    c=(a+b)/2;
                if((f(a)*f(c))<0)
                    b=c;
                else
                    a=c;
                }
            }while(fabs(f(c))>=0.000001);
        }
        cout<<"The solution is: "<<c;
    }
};
int main()
{
    float a,b;
    cout<<"Enter Intervals a and b: ";
    cin>>a>>b;
    Bisection b1(a,b);
    b1.solution();
    return 0;
}